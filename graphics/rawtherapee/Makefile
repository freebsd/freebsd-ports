# New ports collection makefile for:	rawtherapee
# Date created:				01/10/2010
# Whom:					stas
#
# $FreeBSD$
#

PORTNAME=	rawtherapee
PORTVERSION=	4.0.9
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful RAW image processing application

LICENSE=	GPLv3

LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		iptcdata:${PORTSDIR}/graphics/libiptcdata \
		jpeg:${PORTSDIR}/graphics/jpeg \
		lcms2:${PORTSDIR}/graphics/lcms2 \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20

USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_XZ=		yes
USE_GNOME=	gtk20 glib20
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
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
