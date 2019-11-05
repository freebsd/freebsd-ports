# Created by: joerg
# $FreeBSD$

PORTNAME=	xmine
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sw.ru/pub/x11/ \
		LOCAL/joerg
DISTNAME=	${PORTNAME}-${PORTVERSION}-Xaw

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	The `Athena' port of the xminesweeper game

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d

USES=		imake xorg
USE_XORG=	x11 xaw xext xmu xt xpm sm ice

.include <bsd.port.mk>
