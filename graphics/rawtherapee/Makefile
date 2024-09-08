PORTNAME=	rawtherapee
PORTVERSION=	5.11
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/Beep6581/RawTherapee/releases/download/${PORTVERSION}/ \
		https://rawtherapee.com/shared/source/ \
		LOCAL/mandree/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Powerful RAW image processing application
WWW=		https://www.rawtherapee.com/

LICENSE=	GPLv3

LIB_DEPENDS=	\
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libiptcdata.so:graphics/libiptcdata \
		libjxl_threads.so:graphics/libjxl \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libpng.so:graphics/png \
		libsigc-2.0.so:devel/libsigc++20 \
		libtiff.so:graphics/tiff

# We cannot use gcc-c++11-lib as of 2024-02-23 because
# Uses/compiler.mk would use the default compiler instead
# as though USE_GCC=yes had been set.
USES=		autoreconf:build cmake desktop-file-utils compiler:c++11-lib gnome \
		jpeg libtool:build localbase:ldflags pkgconfig tar:xz

USE_GNOME=	gtkmm30 librsvg2

_LTO_FLAGS=	-flto=${MAKE_JOBS_NUMBER}
# gcc needs -flto=${MAKE_JOBS_NUMBER} for parallel link (fixed in GCC 10?)
#     and does not understand -flto=thin
#
# llvm/clang needs -flto=thin and will automatically parallelize the link

# Fix <https://bugs.freebsd.org/251041>:
# 11.x has binutils that don't accept a --plugin option,
# and gcc-ar9 appears to grab those, so make sure that USE_BINUTILS
# override those in /usr/bin which usually is first in the PATH,
# before ${LOCALBASE}/bin.
# (For some reason, poudriere does not trigger this.)
BINARY_ALIAS+=	ar=${AR} ranlib=${RANLIB}
#
_AR=		${CC:S/gcc/gcc-ar/}
_RANLIB=	${CC:S/gcc/gcc-ranlib/}
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}" \
		-DCREDITSDIR="${DOCSDIR}" \
		-DLICENCEDIR="${DOCSDIR}" \
		-DDESKTOPDIR="${DESKTOPDIR}" \
		-DDATADIR="${DATADIR}" \
		-DCACHE_NAME_SUFFIX="" \
		-Wno-dev \
		-DCMAKE_AR:FILEPATH=${_AR} \
		-DCMAKE_RANLIB:FILEPATH=${_RANLIB} \
		-DCMAKE_POLICY_DEFAULT_CMP0056:STRING=NEW
CONFIGURE_ENV+=	AR=${_AR} RANLIB=${_RANLIB} # for embedded RawTherapee
# 3.4.x: CMAKE_EXE_LINKER_FLAGS is not passed to TRY_COMPILE by default
# any more. The CMP0056 policy must be explicitly set to NEW to ensure
# linker flags are passed. Else -lomp is not found with clang.
# See: https://cmake.org/cmake/help/v3.4/policy/CMP0056.html
CFLAGS+=	-I${LOCALBASE}/include -fPIC ${_OPT_FLAGS}
LDFLAGS+=	-Wl,--as-needed -lpthread ${_OPT_FLAGS}

.if defined(PACKAGE_BUILDING) && empty(CFLAGS:M-march*) && (${ARCH} == i386 || ${ARCH} == amd64 || ${ARCH} == aarch64)
# this gets translated to -mtune=generic, see ${WRKSRC}/ProcessorTargets.cmake
# and as of GCC 8.3, it appears that among FreeBSD's supported architectures,
# only the three listed above support this GCC option.
CMAKE_ARGS+=	-DPROC_TARGET_NUMBER="1"
.endif

# For gcc-based builds, rawtherapee's cmake ends up with GCC's absolute path
# in the CC/CXX variables, effectively disabling ccache. Wrap compiler in ccache explicitly.
# CCACHE_ENABLED does not get enabled soon enough as of dceadb6b0011 in February 2024,
# so we need to re-do what bsd.ccache.mk does.
# See also https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=277204
# NB: When changing this, make sure that the compiler is still wrapped by ccache!
.if "${WITH_CCACHE_BUILD}" == "yes" && !defined(NO_CCACHE)
CMAKE_ARGS+=	-DCMAKE_C_COMPILER_LAUNCHER=${CCACHE_BIN} \
		-DCMAKE_CXX_COMPILER_LAUNCHER=${CCACHE_BIN}
.endif

OPTIONS_DEFINE=		DOCS NATIVE LTO
OPTIONS_DEFINE_amd64=	OPENMP
OPTIONS_DEFINE_i386=	OPENMP
OPTIONS_DEFAULT=	OPENMP LTO
NATIVE_DESC=		Use -march=native (avoid for generic packages!)
OPENMP_DESC=		Enable OpenMP parallel processing (i386/amd64 only)

LTO_CFLAGS=		${_LTO_FLAGS}
LTO_LDFLAGS=		${_LTO_FLAGS}
NATIVE_CMAKE_ON=	-DPROC_TARGET_NUMBER="2"
OPENMP_CMAKE_BOOL=	OPTION_OMP
OPENMP_LDFLAGS=		-lm -lomp

.include <bsd.port.options.mk>

# -------------------------------------------------------------------

# Older clang versions (for instance clang 9.0, as of 2019-09-29),
# were known to miscompile RawTherapee, causing SIGSEGV or SIBGUS.
# As of 2024-02, GCC-12.3 compiled RawTherapee appears to be
# up to twice as fast as clang-16.0 compiled code.
# So we shall stick to a modern GCC for now.
#
.if (${OPSYS} == FreeBSD) && (${OSVERSION} >= 1400000 && ${OSVERSION} < 1400501)
# Unfortunately, we can't even upgrade to GCC >= 13 because that fails
# with our libc++ header files, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=273682
# - which was fixed by jhb@ commits on 2023-11-19 for head, 13.3, and 14.1,
# with log "Merge commit 3537338d1ab9 from llvm git (by Nikolas Klauser):
# [libc++][libunwind] Fixes to allow GCC 13 to compile libunwind/libc++abi/libc++ [...]"
# -- once FreeBSD 14.0 will have gone out of support on 2024-10-01, remove this branch
# and USE_GCC=yes unconditionally.
# It would be possible to hoist a fixed pair of libcxx headers remove_cv.h and
# remove_cvref.h into the build but that's too much of an effort for a mere month.
# For a more thorough fix, we could look at
# https://github.com/llvm/llvm-project/commit/55357160d0e151c32f86e1d6683b4bddbb706aa1
USE_GCC=	12
.else
USE_GCC=	yes # default
.endif

.if (${OPSYS} == FreeBSD) && (${OSVERSION} >= 1500000)
# don't waste everybody's time with Tier-2 and moving targets.
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=only amd64 is supported on non-released FreeBSD versions
.endif

.if defined(WITH_DEBUG)
STRIP=
CMAKE_BUILD_TYPE=	None	# Arch Linux packaging trick to avoid cmake overriding our flags
_OPT_FLAGS=	-ggdb3 -Og	# -Og is GCC-specific, use -O1 for clang
.else
_OPT_FLAGS=	-O3 -funroll-loops
.endif

# x86_64/amd64 includes -msse2 by default
.if ${ARCH} == i386
# -mstackrealign: workaround for values passed on the stack that cause SIGBUS on SSE2
# -msse2: SSE2 has been around since the year 2003 latest
_OPT_FLAGS+=	-msse2
_OPT_FLAGS+=	-mstackrealign
.endif

# -------------------------------------------------------------------

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
CXXFLAGS+=	-stdlib=libc++
.endif

post-patch:
	${REINPLACE_CMD} -e '/COMMAND.*SHELL/s/-l -c/-c/' ${WRKSRC}/rtengine/LibRaw.cmake
	${REINPLACE_CMD} -e 's#DESTINATION "$${CMAKE_INSTALL_PREFIX}/share/man/man1"#DESTINATION "${PREFIX}/share/man/man1/"#' \
		${WRKSRC}/CMakeLists.txt

TESTIMAGES=	${MASTERDIR}/testimages

# paranoia: run rawtherapee to be sure it finds all its
# shared libraries (this hinges on proper RPATH setting and propagation)
#
# _check_version strips stuffixes from distnames etc. that do not appear
# in the program's version numbering
_check_version=	${PKGVERSION:C/.g0//}
_env=		LANG= LC_ALL=C LANGUAGE= DISPLAY= HOME="$$TMP" RT_SETTINGS=${WRKDIR}/rt-config RT_CACHE="$$TMP/rtcache"
post-install:
	@${RM} -f ${WRKDIR}/selftest.exitcodes ${WRKDIR}/selftest.expect
	@(set -e; _mp=$$(/bin/df -P ${STAGEDIR}${PREFIX}/bin/rawtherapee | ${AWK} 'NR==2{print $$NF}') ; \
	_fsflags=$$(${MOUNT} -p | ${AWK} "{ if (\$$2 == \"$$_mp\") { print \$$4 } }") ; \
	case $$_fsflags in *noexec*) \
		${TOUCH} ${WRKDIR}/selftest.expect ${WRKDIR}/selftest.exitcodes ; \
		${ECHO_CMD} "===> Skipping smoke tests, STAGEDIR=${STAGEDIR} is on a noexec file system" ; \
		exit 0 ;; \
	esac ; \
	${ECHO_MSG} "===> Running smoke tests" ; \
	${RM} -rf ${WRKDIR}/rt-config ; \
	${MKDIR} ${WRKDIR}/rt-config ${WRKDIR}/rt-config/dcpprofiles ${WRKDIR}/rt-config/profiles ; \
	${CP} ${WRKSRC}/rtengine/camconst.json ${WRKDIR}/rt-config ; \
	${CP} ${WRKSRC}/rtdata/options/options.lin ${WRKDIR}/rt-config/options ; \
	(cd ${WRKSRC}/rtdata/ && ${COPYTREE_SHARE} "profiles dcpprofiles" ${WRKDIR}/rt-config ) ; \
	(set -x ; TMP=$$(${MKTEMP} -d -t ${PORTNAME}) && trap "rc=$$? ; ${RM} -rf \"$$TMP\" ; exit \$$rc" 0 && \
		( set +e ; ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee -v ; \
		    ${ECHO_CMD} $$? >&3 ) 3>&3 | ${EGREP} -q "RawTherapee, version ${_check_version:C/_.*//:C/,.*//}|cannot open display:" && \
		( set +e ; ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli | dd ibs=8k ; \
		    ${ECHO_CMD} $$? >&3 ) 3>&3 | ${EGREP} -q "RawTherapee, version ${_check_version:C/_.*//:C/,.*//}" && \
		expect=$$'0\n0\n' && \
		onefile=$$(ls "${TESTIMAGES}"/* | head -1) && \
		if test -d "${TESTIMAGES}" && test -n "$$onefile" -a -r "$$onefile" ; then \
		  expect=$$'0\n0\n0\n0\n0\n' && \
		  ( set +e ; \
		  /usr/bin/time ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli \
			-o "$$TMP" -q -f -c ${TESTIMAGES} ; ${ECHO_CMD} $$? >&3 ; \
		  /usr/bin/time ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli \
			-o "$$TMP" -q -s -Y -c ${TESTIMAGES} ; ${ECHO_CMD} $$? >&3 ; \
		  /usr/bin/time ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli \
			-o "$$TMP" -q -s -Y -tz -c ${TESTIMAGES} ; ${ECHO_CMD} $$? >&3 ) 3>&3 ; \
		fi ; \
		ls -Rlbai "${TESTIMAGES}" "$${TMP}" || :; \
	${PRINTF} "%s" "$$expect" >&4 ) ) 3>${WRKDIR}/selftest.exitcodes 4>${WRKDIR}/selftest.expect  ; \
	${HEAD} ${WRKDIR}/selftest.exitcodes ${WRKDIR}/selftest.expect ; \
	cmp ${WRKDIR}/selftest.expect ${WRKDIR}/selftest.exitcodes \
	|| { ${ECHO_CMD} '===> !!! SELF-TEST FAILED !!! <===' ; exit 1 ; }

.include <bsd.port.post.mk>
