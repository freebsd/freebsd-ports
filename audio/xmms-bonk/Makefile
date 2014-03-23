# $FreeBSD$

PORTNAME=	xmms-bonk
PORTVERSION=	0.12
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.proustmedia.de/bonk-xmms/
DISTNAME=	bonk-xmms-${PORTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin to play bonk files

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

ALL_TARGET=

PLIST_FILES=	lib/xmms/Input/libbonk.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Input
	${INSTALL_DATA} ${WRKSRC}/libbonk.so ${STAGEDIR}${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
