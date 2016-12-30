# Created by: stas
# $FreeBSD$

PORTNAME=	rawtherapee
PORTVERSION=	4.2
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://rawtherapee.com/shared/source/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Powerful RAW image processing application

LICENSE=	GPLv3

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24 \
		libiptcdata.so:graphics/libiptcdata \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libsigc-2.0.so:devel/libsigc++20 \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

USES=		cmake:outsource compiler:gcc-c++11-lib desktop-file-utils dos2unix \
		jpeg pkgconfig tar:xz
DOS2UNIX_REGEX=	.*\.(cc|h)
USE_GNOME=	gtk20 glib20
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC
CXXFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS:C|-Wl,-rpath=${_GCC_RUNTIME}||:C|-L${_GCC_RUNTIME}||}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}" \
		-DCREDITSDIR="${DOCSDIR}" \
		-DLICENCEDIR="${DOCSDIR}" \
		-DDESKTOPDIR="${DESKTOPDIR}" \
		-DDATADIR="${DATADIR}" \
		-DCMAKE_C_FLAGS="${CFLAGS:C|-Wl,-rpath=${_GCC_RUNTIME}||:C|-L${_GCC_RUNTIME}||}" \
		-DCMAKE_CXX_FLAGS="${CXXFLAGS:C|-Wl,-rpath=${_GCC_RUNTIME}||:C|-L${_GCC_RUNTIME}||}" \
		-DCACHE_NAME_SUFFIX="4.1"
SUB_FILES=	rawtherapee
SUB_LIST=	RTDIR="${RTDIR}"
INSTALLS_ICONS=	yes

.if defined(PACKAGE_BUILDING)
CMAKE_ARGS+=	-DPROC_TARGET_NUMBER="1"
.endif

RTDIR=		${PREFIX}/libdata/${PORTNAME}

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS OPENMP
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS OPENMP
OPENMP_DESC=		Enable multicore processing using OpenMP
OPTIMIZED_CFLAGS_DESC=	Use extra compiler optimizations (requires SSE support)

OPENMP_CMAKE_BOOL=	OPTION_OMP

.include <bsd.port.pre.mk>

# -------------------------------------------------------------------

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fexpensive-optimizations \
		-funroll-loops -msse
CXXFLAGS+=	-O3 \
		-funroll-loops -msse
.endif
.endif

# -------------------------------------------------------------------

post-patch:
	@${REINPLACE_CMD} -e 's#<auto_ptr.h>#<memory>#g' \
		${WRKSRC}/rtgui/darkframe.h \
		${WRKSRC}/rtgui/flatfield.h \
		${WRKSRC}/rtgui/icmpanel.h
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
