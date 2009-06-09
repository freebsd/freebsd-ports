# New ports collection makefile for:    xblackjack
# Date created:         8/16/1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xblackjack
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11/Motif blackjack game

USE_IMAKE=	yes
USE_XORG=	x11 xext xp xt xmu
LIB_DEPENDS+=	Xm.2:${PORTSDIR}/x11-toolkits/lesstif
MAN1=		xblackjack.1

.include <bsd.port.mk>
