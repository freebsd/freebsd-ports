# $FreeBSD$

PORTNAME=	hexxagon
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.nesqi.se/hexxagon/hexxagon/download/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Strategy hexagon game

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="Hexxagon" "Strategy Game" "" \
		"hexxagon" "Game;StrategyGame;" false

.include <bsd.port.mk>
