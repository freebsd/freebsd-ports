# New ports collection makefile for:	rawtherapee
# Date created:		01/10/2010
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	rawtherapee
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A powerful RAW image processing application

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
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CMAKE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}" \
		-DCREDITSDIR="${DOCSDIR}" \
		-DLICENCEDIR="${DOCSDIR}" \
		-DDESKTOPDIR="${DESKTOPDIR}" \
		-DDATADIR="${DATADIR}"
SUB_FILES=	rawtherapee
SUB_LIST=	RTDIR="${RTDIR}"
INSTALLS_ICONS=	yes
LICENSE=	GPLv3

RTDIR=	${PREFIX}/libdata/${PORTNAME}

OPTIONS=	OPTIMIZED_CFLAGS "Use optimized CFLAGS" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fexpensive-optimizations \
		-funroll-loops -msse
.endif
.endif

.include <bsd.port.post.mk>
