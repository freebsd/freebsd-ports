# $FreeBSD$

PORTNAME=	hexxagon
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.nesqi.se/download/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Strategy hexagon game

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		gmake pkgconfig tar:bzip2
GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="Hexxagon" "Strategy Game" "" \
		"hexxagon" "Game;StrategyGame;" false

.include <bsd.port.mk>
