# Created by: stas
# $FreeBSD$

PORTNAME=	rawtherapee
PORTVERSION=	5.4
PORTREVISION=	2
#DISTNAME=	${PORTNAME}-${PORTVERSION:R}-r${PORTVERSION:E}${DISTVERSIONSUFFIX}
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

USES=		cmake:outsource desktop-file-utils dos2unix \
		jpeg localbase:ldflags pkgconfig tar:xz
DOS2UNIX_REGEX=	.*\.(cc|h)
LDFLAGS+=	-Wl,--as-needed # fontconfig, freetype, gettext, libX11
USE_GNOME=	gtkmm30
USE_LDCONFIG=	yes
# The -D_GLIBCXX_USE_C99 works around stoi not being defined
# by default because the GCC headers believe FreeBSD insufficiently C99
# compliant.
CFLAGS+=	-I${LOCALBASE}/include -fPIC -D_GLIBCXX_USE_C99 -Wno-deprecated-declarations -Wno-unused-result
LDFLAGS+=	-lpthread
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}" \
		-DCREDITSDIR="${DOCSDIR}" \
		-DLICENCEDIR="${DOCSDIR}" \
		-DDESKTOPDIR="${DESKTOPDIR}" \
		-DDATADIR="${DATADIR}" \
		-DCACHE_NAME_SUFFIX="" \
		-Wno-dev \
		-DCMAKE_POLICY_DEFAULT_CMP0056:STRING=NEW
# 3.4.x: CMAKE_EXE_LINKER_FLAGS is not passed to TRY_COMPILE by default
# any more. The CMP0056 policy must be explicitly set to NEW to ensure
# linker flags are passed. Else -lomp is not found with clang.
# See: https://cmake.org/cmake/help/v3.4/policy/CMP0056.html

INSTALLS_ICONS=	yes

.if defined(PACKAGE_BUILDING) && empty(CFLAGS:M-march*)
CMAKE_ARGS+=	-DPROC_TARGET_NUMBER="1"
.endif

RTDIR=		${PREFIX}/libdata/${PORTNAME}

OPTIONS_DEFINE=		DOCS OPTIMIZED_CFLAGS OPENMP NATIVE
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS OPENMP
OPENMP_DESC=		Enable multicore processing using OpenMP (amd64)
OPTIMIZED_CFLAGS_DESC=	Use extra compiler optimizations (requires SSE2 support)
NATIVE_DESC=		Use -march=native for compilation (do not use for generic packages!)

OPENMP_CMAKE_BOOL=	OPTION_OMP

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -funroll-loops -msse2
# GCC 5.4 includes -fexpensive-optimizations in -O2 already

.include <bsd.port.options.mk>

# -------------------------------------------------------------------
#

BROKEN_aarch64=		fails to build: gcc5: error: unrecognized command line option -msse2
BROKEN_powerpc64=	fails to build: gcc6: error: unrecognized command line option -msse2

.if ${OPSYS} == FreeBSD
.if ${OSVERSION} >= 1200000
# don't waste everybody's time with Tier-2 and moving targets.
# might add ARM64 or SPARC64 later on if they are established by the
# time FreeBSD 12 is out.
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=Only amd64 is supported on non-released FreeBSD versions.
.endif
.endif

.if ${PORT_OPTIONS:MNATIVE}
CMAKE_ARGS+=	-DPROC_TARGET_NUMBER="2"
.endif

.if !empty(PORT_OPTIONS:MOPENMP) && ${ARCH} == "amd64"
LIB_DEPENDS+=	libomp.so.0:devel/openmp
OPENMP_FLAGS=	-lm -lomp
LDFLAGS+=	${OPENMP_FLAGS}
.endif

.if defined(WITH_DEBUG)
STRIP=
.endif

.if ${ARCH} == i386
USES+=		compiler:c++11-lib
# If we were to use GCC on i386, we'd need to use -mstackrealign
# or similar options, else we get SIGBUS when SSE2 is enabled due to
# improper alignment. Base clang is good enough though, i386 does not
# support OpenMP, and those seeking ultimate performance need to use
# amd64. Workaround implemented below.
.else
USES+=		compiler:c++14-lang
.endif

# -------------------------------------------------------------------

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
# work around compiler faults
.if ${ARCH} == i386
CFLAGS+=	-mstackrealign
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#DESTINATION "$${CMAKE_INSTALL_PREFIX}/share/man/man1"#DESTINATION "${MANPREFIX}/man/man1/"#' \
		${WRKSRC}/CMakeLists.txt

# paranoia: run rawtherapee --help to be sure it finds all its
# shared libraries (this hinges on proper RPATH setting and propagation)
post-install:
	@${ECHO_MSG} "===> Running smoke tests"
	@TMP=$$(mktemp -d -t ${PORTNAME}) && trap "rc=$$? ; rm -rf \"$$TMP\" ; exit \$$rc" 0 && \
	${SETENV} LANG= LC_ALL=C LANGUAGE= DISPLAY= HOME="$$TMP" ${STAGEDIR}${PREFIX}/bin/rawtherapee --help 2>&1 \
	    | ${EGREP} -q "RawTherapee, version ${PKGVERSION:C/_.*//:C/,.*//}|cannot open display:" && \
	${SETENV} LANG= LC_ALL=C LANGUAGE= DISPLAY= HOME="$$TMP" ${STAGEDIR}${PREFIX}/bin/rawtherapee-cli --version 2>&1 \
	    | ${EGREP} -q "RawTherapee, version ${PKGVERSION:C/_.*//:C/,.*//}"

.include <bsd.port.post.mk>
