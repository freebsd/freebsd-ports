# $FreeBSD$

PORTNAME=	cdogs-sdl
PORTVERSION=	0.8.0
CATEGORIES=	games

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Classic overhead run-and-gun game

USES=		cmake compiler:c++11-lang gnome pkgconfig sdl
USE_SDL=	sdl2 image2 mixer2
USE_GNOME=	gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	cxong
CMAKE_ARGS=	-DCDOGS_DATA_DIR=${DATADIR}/

.include <bsd.port.mk>
