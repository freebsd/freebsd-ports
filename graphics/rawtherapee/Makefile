# Created by: stas
# $FreeBSD$

PORTNAME=	rawtherapee
PORTVERSION=	5.7
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://rawtherapee.com/shared/source/

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
USE_GCC=	9+
USE_BINUTILS=	yes

# gcc needs -flto=${MAKE_JOBS_NUMBER} for parallel link
#   and does not understand -flto=thin
#   
# llvm/clang needs -flto=thin and will automatically parallelize the link
#
# As of 2019-09-29, this port is known to be micompiled by clang90 (SIGSEGV or SIBGUS)
# FreeBSD 12.0's base clang 6.0.1 emits worse code with considerably higher
# processing times.
# so we shall stick to GCC 9.x for now
_LTO_FLAGS=	-flto=${MAKE_JOBS_NUMBER}
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

INSTALLS_ICONS=	yes

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

RTDIR=		${PREFIX}/libdata/${PORTNAME}

OPTIONS_DEFINE=		DOCS NATIVE
OPTIONS_DEFINE_i386=	DOCS NATIVE OPENMP
OPTIONS_DEFINE_amd64=	DOCS NATIVE OPENMP
OPTIONS_DEFAULT=	OPENMP
OPENMP_DESC=		Enable OpenMP parallel processing (i386/amd64 only)
NATIVE_DESC=		Use -march=native (avoid for generic packages!)

OPENMP_CMAKE_BOOL=	OPTION_OMP

.include <bsd.port.options.mk>

# -------------------------------------------------------------------

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
LIB_DEPENDS+=	libomp.so:devel/openmp
OPENMP_FLAGS=	-lm -lomp
LDFLAGS+=	${OPENMP_FLAGS}
.endif

.if defined(WITH_DEBUG)
STRIP=
.endif

_OPT_FLAGS=	-O3 -funroll-loops
# GCC 5.4 includes -fexpensive-optimizations in -O2 already
.if (${ARCH} == i386) || (${ARCH} == amd64)
_OPT_FLAGS+=	-msse2
.endif

.if ${ARCH} == i386
_OPT_FLAGS+=	-mstackrealign
.endif

# -------------------------------------------------------------------

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#DESTINATION "$${CMAKE_INSTALL_PREFIX}/share/man/man1"#DESTINATION "${MANPREFIX}/man/man1/"#' \
		${WRKSRC}/CMakeLists.txt

# paranoia: run rawtherapee --help to be sure it finds all its
# shared libraries (this hinges on proper RPATH setting and propagation)
post-install:
	@${ECHO_MSG} "===> Running smoke tests"
	@TMP=$$(mktemp -d -t ${PORTNAME}) && trap "rc=$$? ; ${RM} -rf \"$$TMP\" ; exit \$$rc" 0 && \
	${SETENV} LANG= LC_ALL=C LANGUAGE= DISPLAY= HOME="$$TMP" ${STAGEDIR}${PREFIX}/bin/rawtherapee --help 2>&1 \
	    | ${EGREP} -q "RawTherapee, version ${PKGVERSION:C/_.*//:C/,.*//}|cannot open display:" && \
	${SETENV} LANG= LC_ALL=C LANGUAGE= DISPLAY= HOME="$$TMP" ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli --version 2>&1 \
	    | ${EGREP} -q "RawTherapee, version ${PKGVERSION:C/_.*//:C/,.*//}"

.include <bsd.port.post.mk>
