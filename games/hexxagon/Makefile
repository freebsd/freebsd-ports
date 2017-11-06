# $FreeBSD$

PORTNAME=	hexxagon
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.nesqi.se/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strategy hexagon game

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		compiler:c++11-lang gmake pkgconfig tar:bzip2
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="Hexxagon" "Strategy Game" "" \
		"hexxagon" "Game;StrategyGame;" false

.include <bsd.port.mk>
