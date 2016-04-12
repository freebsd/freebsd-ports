# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	xblackjack
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11/Motif blackjack game

LIB_DEPENDS=	libXm.so:x11-toolkits/lesstif

USES=		imake tar:Z
USE_XORG=	x11 xext xp xt xmu
CFLAGS+=	-Wno-error=return-type

.include <bsd.port.mk>
