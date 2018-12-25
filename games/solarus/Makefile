# $FreeBSD$

PORTNAME=	solarus
PORTVERSION=	1.6.0
CATEGORIES=	games
MASTER_SITES=	http://www.solarus-games.org/downloads/solarus/
DISTNAME=	solarus-${PORTVERSION}-src

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Zelda-like 2D game engine

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libmodplug.so:audio/libmodplug \
		libluajit-5.1.so:lang/luajit \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		cmake:noninja compiler:c++11-lib gl openal qmake qt:5

MAKE_ARGS+=	DESTDIR=${STAGEDIR}
USE_QT=		buildtools_build core gui linguisttools_build widgets
USE_SDL=	sdl2 ttf2 image2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GL=		gl glu
USE_LDCONFIG=	yes

.include <bsd.port.mk>
