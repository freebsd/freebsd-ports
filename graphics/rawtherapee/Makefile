# Created by: stas
# $FreeBSD$

PORTNAME=	rawtherapee
PORTVERSION=	5.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://rawtherapee.com/shared/source/ \
		LOCAL/mandree/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Powerful RAW image processing application

LICENSE=	GPLv3

LIB_DEPENDS=	\
		liblensfun.so:graphics/lensfun \
		libcanberra-gtk.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libexpat.so:textproc/expat2 \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libiptcdata.so:graphics/libiptcdata \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libsigc-2.0.so:devel/libsigc++20 \
		libtiff.so:graphics/tiff

USES=		cmake desktop-file-utils compiler:gcc-c++11-lib gnome \
		jpeg localbase:ldflags pkgconfig tar:xz

DOS2UNIX_REGEX=	.*\.(cc|h)
USE_GNOME=	gtkmm30 librsvg2
INSTALLS_ICONS=	yes

# Binutils required for LTO (base ar/nm/ld/ranlib don't work)
USE_BINUTILS=	yes

# As of 2019-09-29, this port is known to be miscompiled by clang90
# (SIGSEGV or SIBGUS) and 12.1's base clang.
#
# FreeBSD 11.2/12.0's base clang 6.0.1 emits worse code with
# considerably higher processing times, and on i386 additional calls to
# __atomic_*(), so we shall stick to GCC 9.x for now
USE_GCC=	9+

_LTO_FLAGS=	-flto=${MAKE_JOBS_NUMBER}
# gcc needs -flto=${MAKE_JOBS_NUMBER} for parallel link (fixed in GCC 10?)
#     and does not understand -flto=thin
#
# llvm/clang needs -flto=thin and will automatically parallelize the link
#
_AR=		${CC:S/gcc/gcc-ar/}
_RANLIB=	${CC:S/gcc/gcc-ranlib/}
CFLAGS+=	-I${LOCALBASE}/include -fPIC ${_LTO_FLAGS} ${_OPT_FLAGS}
LDFLAGS+=	-Wl,--as-needed -lpthread ${_LTO_FLAGS} ${_OPT_FLAGS}
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
# 3.4.x: CMAKE_EXE_LINKER_FLAGS is not passed to TRY_COMPILE by default
# any more. The CMP0056 policy must be explicitly set to NEW to ensure
# linker flags are passed. Else -lomp is not found with clang.
# See: https://cmake.org/cmake/help/v3.4/policy/CMP0056.html

.if defined(PACKAGE_BUILDING) && empty(CFLAGS:M-march*) && (${ARCH} == i386 || ${ARCH} == amd64 || ${ARCH} == aarch64)
# this gets translated to -mtune=generic, see ${WRKSRC}/ProcessorTargets.cmake
# and as of GCC 8.3, it appears that among FreeBSD's supported architectures,
# only the three listed above support this GCC option.
CMAKE_ARGS+=	-DPROC_TARGET_NUMBER="1"
.endif

.if "${WITH_CCACHE_BUILD}" == "yes" && !defined(NO_CCACHE)
CMAKE_ARGS+=	-DCMAKE_C_COMPILER_LAUNCHER=${CCACHE_BIN} \
		-DCMAKE_CXX_COMPILER_LAUNCHER=${CCACHE_BIN}
.endif

OPTIONS_DEFINE=		DOCS NATIVE
OPTIONS_DEFINE_i386=	OPENMP TCMALLOC
OPTIONS_DEFINE_amd64=	OPENMP TCMALLOC
OPTIONS_DEFAULT=	OPENMP TCMALLOC
OPENMP_DESC=		Enable OpenMP parallel processing (i386/amd64 only)
NATIVE_DESC=		Use -march=native (avoid for generic packages!)
TCMALLOC_DESC=		Use Google's tcmalloc instead of system allocator

OPENMP_CMAKE_BOOL=	OPTION_OMP

TCMALLOC_CMAKE_BOOL=	ENABLE_TCMALLOC
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

.include <bsd.port.options.mk>

# -------------------------------------------------------------------

.if (${OPSYS} == FreeBSD) && (${OSVERSION} <  1200000)
# can't save 16-bit TIFF on FreeBSD 11.3 i386:
# "TIFFWriteDirectoryTagIfdIfd8Array: Attempt to write value
# larger than 0xFFFFFFFF in Classic TIFF file"
#
# And no, the maintainer is not going to spend any time on it
# unless there is a tested proven well-integrated patch offered.
#
# Tier-2 only supported on the latest stable FreeBSD release.
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON= i386 malfunctions on 11.x - upgrade to 12.x
.endif

.if (${OPSYS} == FreeBSD) && (${OSVERSION} >= 1300000)
# don't waste everybody's time with Tier-2 and moving targets.
# might add ARM64 or SPARC64 later on if they are established by the
# time FreeBSD 12 is out.
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=Only amd64 is supported on non-released FreeBSD versions.
.endif

.if ${PORT_OPTIONS:MNATIVE}
CMAKE_ARGS+=	-DPROC_TARGET_NUMBER="2"
.endif

.if !empty(PORT_OPTIONS:MOPENMP) && !empty(OPTIONS_DEFINE:MOPENMP)
. if ${OSVERSION} < 1102507 || (${OSVERSION} >= 1200000 && ${OSVERSION} < 1200506) || (${OSVERSION} >= 1300000 && ${OSVERSION} < 1300050)
LIB_DEPENDS+=	libomp.so:devel/openmp
. endif
OPENMP_FLAGS=	-lm -lomp
LDFLAGS+=	${OPENMP_FLAGS}
.endif

.if defined(WITH_DEBUG)
STRIP=
CMAKE_BUILD_TYPE=	RelWithDebInfo
_OPT_FLAGS=	-O1
.else
_OPT_FLAGS=	-O3 -funroll-loops
.endif

# GCC >= 5.4 includes -fexpensive-optimizations in -O2 already
.if (${ARCH} == i386) || (${ARCH} == amd64)
# and SSE2 has been around since the years 2000...2003 latest
_OPT_FLAGS+=	-msse2
.endif

# workaround for values on the stack that cause SIGBUS on SSE2:
.if ${ARCH} == i386
_OPT_FLAGS+=	-mstackrealign
.endif

# -------------------------------------------------------------------

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#DESTINATION "$${CMAKE_INSTALL_PREFIX}/share/man/man1"#DESTINATION "${MANPREFIX}/man/man1/"#' \
		${WRKSRC}/CMakeLists.txt

TESTIMAGES=	${FILESDIR}/../testimages

# paranoia: run rawtherapee to be sure it finds all its
# shared libraries (this hinges on proper RPATH setting and propagation)
#
# _check_version strips stuffixes from distnames etc. that do not appear
# in the program's version numbering
_check_version=	${PKGVERSION:C/.g0//}
_env=		LANG= LC_ALL=C LANGUAGE= DISPLAY= HOME="$$TMP" RT_SETTINGS=${WRKDIR}/rt-config RT_CACHE="$$TMP/rtcache"
post-install:
	@${ECHO_MSG} "===> Running smoke tests"
	@${RM} -f ${WRKDIR}/selftest.exitcodes ${WRKDIR}/selftest.expect 
	@${RM} -rf ${WRKDIR}/rt-config
	${MKDIR} ${WRKDIR}/rt-config ${WRKDIR}/rt-config/dcpprofiles ${WRKDIR}/rt-config/profiles
	${CP} ${WRKSRC}/rtengine/camconst.json ${WRKDIR}/rt-config
	${CP} ${WRKSRC}/rtdata/options/options.lin ${WRKDIR}/rt-config/options
	(cd ${WRKSRC}/rtdata/ && ${COPYTREE_SHARE} "profiles dcpprofiles" ${WRKDIR}/rt-config )
	@(set -x ; TMP=$$(${MKTEMP} -d -t ${PORTNAME}) && trap "rc=$$? ; ${RM} -rf \"$$TMP\" ; exit \$$rc" 0 && \
		( ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee -v 2>&1 ; \
		    echo $$? >&3 ) 3>&3 | ${EGREP} -q "RawTherapee, version ${_check_version:C/_.*//:C/,.*//}|cannot open display:" && \
		( ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli 2>&1 ; \
		    echo $$? >&3 ) 3>&3 | ${EGREP} -q "RawTherapee, version ${_check_version:C/_.*//:C/,.*//}" && \
		expect='0\n0\n' && \
		onefile=$$(ls "${TESTIMAGES}"/* | head -1) && \
		if test -d "${TESTIMAGES}" && test -n "$$onefile" -a -r "$$onefile" ; then \
		  expect='0\n0\n0\n0\n0\n' && \
		  /usr/bin/time ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli \
			-o "$$TMP" -q -f -c ${TESTIMAGES} ; echo $$? >&3 ; \
		  /usr/bin/time ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli \
			-o "$$TMP" -q -s -Y -c ${TESTIMAGES} ; echo $$? >&3 ; \
		  /usr/bin/time ${SETENV} ${_env} ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli \
			-o "$$TMP" -q -s -Y -tz -c ${TESTIMAGES} ; echo $$? >&3 ; \
		fi ; \
		ls -Rlbai "${TESTIMAGES}" "$${TMP}" || :; \
	${PRINTF} "%s" "$$expect" >&4 ) 3>${WRKDIR}/selftest.exitcodes 4>${WRKDIR}/selftest.expect ; \
	${PRINTF} "$$(cat ${WRKDIR}/selftest.expect)" | cmp - ${WRKDIR}/selftest.exitcodes || { ${ECHO_CMD} '===> !!! SELF-TEST FAILED !!! <===' ; exit 1 ; }

.include <bsd.port.post.mk>
