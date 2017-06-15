# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	gxmms2
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK2 based XMMS2 client, written in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxmmsclient.so:audio/xmms2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk20
USES=		gmake pkgconfig
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/gxmms2 \
		%%DATADIR%%/gxmms2_mini.xpm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gxmms2src/gxmms2_mini.xpm ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
