# New ports collection makefile for:	rawtherapee
# Date created:		01/10/2010
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	rawtherapee
PORTVERSION=	4.0.2
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful RAW image processing application

LICENSE=	GPLv3

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		iptcdata.3:${PORTSDIR}/graphics/libiptcdata \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		lcms2.2:${PORTSDIR}/graphics/lcms2 \
		png:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20

USE_CMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20 glib20 pkgconfig
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

RTDIR=	${PREFIX}/libdata/${PORTNAME}

OPTIONS=	OPTIMIZED_CFLAGS "Use optimized CFLAGS" on \
		OPENMP "Enable multicore processing using OpenMP" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fexpensive-optimizations \
		-funroll-loops -msse
CXXFLAGS+=	-O3 -ffast-math -fexpensive-optimizations \
		-funroll-loops -msse
.endif
.endif

.if !defined(WITHOUT_OPENMP)
CMAKE_ARGS+=	-DOPTION_OMP:BOOL=ON
.else
CMAKE_ARGS+=	-DOPTION_OMP:BOOL=OFF
.endif

.include <bsd.port.post.mk>
