# New ports collection makefile for:	rawtherapee
# Date created:				01/10/2010
# Whom:					stas
#
# $FreeBSD$
#

PORTNAME=	rawtherapee
PORTVERSION=	4.0.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful RAW image processing application

LICENSE=	GPLv3

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		iptcdata.3:${PORTSDIR}/graphics/libiptcdata \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		lcms2.2:${PORTSDIR}/graphics/lcms2 \
		png15:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20

USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_XZ=		yes
USE_GNOME=	gtk20 glib20
USE_LDCONFIG=	yes
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fexpensive-optimizations \
		-funroll-loops -msse
CXXFLAGS+=	-O3 -ffast-math -fexpensive-optimizations \
		-funroll-loops -msse
.endif
.endif

#.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
#BROKEN=		Does not compile on ia64, powerpc, or sparc64
#.endif

.if ${PORT_OPTIONS:MOPENMP}
CMAKE_ARGS+=	-DOPTION_OMP:BOOL=ON
.else
CMAKE_ARGS+=	-DOPTION_OMP:BOOL=OFF
.endif

.include <bsd.port.post.mk>
