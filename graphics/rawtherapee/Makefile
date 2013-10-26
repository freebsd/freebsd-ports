# Created by: stas
# $FreeBSD$

PORTNAME=	rawtherapee
PORTVERSION=	4.0.11
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	A powerful RAW image processing application

LICENSE=	GPLv3

LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libiptcdata.so:${PORTSDIR}/graphics/libiptcdata \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3

USES=		cmake:outsource pkgconfig
USE_XZ=		yes
USE_GNOME=	gtk20 glib20
USE_LDCONFIG=	yes
# base GCC and clang in 9.1-RELEASE are insufficient:
USE_GCC=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC ${PTHREAD_CFLAGS}
CXXFLAGS+=	-I${LOCALBASE}/include -fPIC ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CMAKE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}" \
		-DCREDITSDIR="${DOCSDIR}" \
		-DLICENCEDIR="${DOCSDIR}" \
		-DDESKTOPDIR="${DESKTOPDIR}" \
		-DDATADIR="${DATADIR}" \
		-DCMAKE_C_FLAGS="${CFLAGS}" \
		-DCMAKE_CXX_FLAGS="${CXXFLAGS}"
SUB_FILES=	rawtherapee
SUB_LIST=	RTDIR="${RTDIR}"
INSTALLS_ICONS=	yes

RTDIR=		${PREFIX}/libdata/${PORTNAME}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS OPENMP
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS OPENMP
OPENMP_DESC=	Enable multicore processing using OpenMP

post-patch:
	@${REINPLACE_CMD} -e 's#<auto_ptr.h>#<memory>#g' \
		${WRKSRC}/rtgui/darkframe.h ${WRKSRC}/rtgui/flatfield.h \
		${WRKSRC}/rtgui/icmpanel.h
	@${REINPLACE_CMD} -e 's#DESTINATION "$${CMAKE_INSTALL_PREFIX}/share/man/man1"#DESTINATION "${MANPREFIX}/man/man1/"#' \
		${WRKSRC}/CMakeLists.txt

# paranoia: run rawtherapee --help to be sure it finds all its
# shared libraries (this hinges on proper RPATH setting and propagation)
post-install:
	${SETENV} HOME=/dev/null ${STAGEDIR}${PREFIX}/bin/rawtherapee --help 2>&1 \
	| ${EGREP} -q "RawTherapee, version ${PKGVERSION:C/_.*//:C/,.*//}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fexpensive-optimizations \
		-funroll-loops -msse
CXXFLAGS+=	-O3 -ffast-math -fexpensive-optimizations \
		-funroll-loops -msse
.endif
.endif

.if ${PORT_OPTIONS:MOPENMP}
CMAKE_ARGS+=	-DOPTION_OMP:BOOL=ON
.else
CMAKE_ARGS+=	-DOPTION_OMP:BOOL=OFF
.endif

.include <bsd.port.post.mk>
