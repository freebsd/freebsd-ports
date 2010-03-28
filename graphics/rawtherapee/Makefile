# New ports collection makefile for:	rawtherapee
# Date created:		01/10/2010
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	rawtherapee
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.rawtherapee.com/
DISTNAME=	${PORTNAME}${PORTVERSION:S,.,,g}src
EXTRACT_SUFX=	.tgz

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A powerful RAW image processing application

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		iptcdata.3:${PORTSDIR}/graphics/libiptcdata \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms \
		png:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_CMAKE=	yes
USE_GNOME=	gtk20 glib20
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CMAKE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
SUB_FILES=	rawtherapee
SUB_LIST=	RTDIR="${RTDIR}"

WRKSRC=		${WRKDIR}/RawTherapee${PORTVERSION:S,.,,g}
RTDIR=	${PREFIX}/libdata/${PORTNAME}

OPTIONS=	OPTIMIZED_CFLAGS "Use optimized CFLAGS" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fexpensive-optimizations \
		-funroll-loops -msse
.endif
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/rtengine/librtengine.so ${PREFIX}/lib
	${MKDIR} ${RTDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/rtgui/rth ${RTDIR}/
	(cd ${WRKSRC}/release && ${COPYTREE_SHARE} \* ${RTDIR}/)
	${INSTALL_DATA} ${WRKSRC}/options.lin ${RTDIR}/options
	${INSTALL_SCRIPT} ${WRKDIR}/rawtherapee ${PREFIX}/bin/

.include <bsd.port.post.mk>
