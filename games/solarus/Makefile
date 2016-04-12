# $FreeBSD$

PORTNAME=	solarus
PORTVERSION=	1.4.5
CATEGORIES=	games
MASTER_SITES=	http://www.solarus-games.org/downloads/solarus/
DISTNAME=	solarus-${PORTVERSION}-src

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Zelda-like 2D game engine

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libmodplug.so:audio/libmodplug \
		liblua-5.1.so:lang/lua51 \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

CMAKE_ARGS+=	-DSOLARUS_USE_LUAJIT=OFF

USE_SDL=	sdl2 ttf2 image2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		cmake compiler:c++11-lib openal
USE_LDCONFIG=	yes

.include <bsd.port.mk>
