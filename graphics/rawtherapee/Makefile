# Created by: stas
# $FreeBSD$

PORTNAME=	rawtherapee
PORTVERSION=	4.2
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://rawtherapee.com/shared/source/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Powerful RAW image processing application

LICENSE=	GPLv3

LIB_DEPENDS=	libcanberra-gtk.so:audio/libcanberra \
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
USE_GNOME=	gtkmm24
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC
CXXFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-lpthread
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}" \
		-DCREDITSDIR="${DOCSDIR}" \
		-DLICENCEDIR="${DOCSDIR}" \
		-DDESKTOPDIR="${DESKTOPDIR}" \
		-DDATADIR="${DATADIR}" \
		-DCACHE_NAME_SUFFIX="4.1" \
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

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS OPENMP
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS OPENMP
OPENMP_DESC=		Enable multicore processing using OpenMP (amd64)
OPTIMIZED_CFLAGS_DESC=	Use extra compiler optimizations (requires SSE2 support)

OPENMP_CMAKE_BOOL=	OPTION_OMP

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -funroll-loops \
			${OPTIMIZED_CFLAGS_CFLAGS_${CHOSEN_COMPILER_TYPE}}
OPTIMIZED_CFLAGS_CFLAGS_gcc=	-fexpensive-optimizations

.include <bsd.port.options.mk>

# -------------------------------------------------------------------
#

.if !empty(PORT_OPTIONS:MOPENMP) && ${ARCH} == "amd64"
LIB_DEPENDS+=	libomp.so.0:devel/openmp
OPENMP_FLAGS=	-lm -lomp
LDFLAGS+=	${OPENMP_FLAGS}
.if ${OSVERSION} < 1100101
# clang 3.4 doesn't support OpenMP,
# OTOH gcc 4.9 doesn't generate usable code on FreeBSD 11.
USES+=		compiler:gcc-c++11-lib
.endif
.endif

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

# -------------------------------------------------------------------

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#DESTINATION "$${CMAKE_INSTALL_PREFIX}/share/man/man1"#DESTINATION "${MANPREFIX}/man/man1/"#' \
		${WRKSRC}/CMakeLists.txt
	${RM} ${WRKSRC}/rtengine/dcraw.patch \
		${WRKSRC}/rtengine/dcraw.c

# paranoia: run rawtherapee --help to be sure it finds all its
# shared libraries (this hinges on proper RPATH setting and propagation)
post-install:
	${SETENV} HOME=/dev/null ${STAGEDIR}${PREFIX}/bin/rawtherapee --help 2>&1 \
	| ${EGREP} -q "RawTherapee, version ${PKGVERSION:C/_.*//:C/,.*//}"

.include <bsd.port.post.mk>
