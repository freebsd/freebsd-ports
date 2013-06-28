# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	xblackjack
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	XCONTRIB
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11/Motif blackjack game

LIB_DEPENDS=	Xm:${PORTSDIR}/x11-toolkits/lesstif

USES=		imake
USE_XORG=	x11 xext xp xt xmu
MAN1=		xblackjack.1
CFLAGS+=	-Wno-error=return-type

.include <bsd.port.mk>
