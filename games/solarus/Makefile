# $FreeBSD$

PORTNAME=	solarus
PORTVERSION=	1.5.3
PORTREVISION=	1
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
MAKE_ARGS+=	DESTDIR=${STAGEDIR}
USE_QT5=	buildtools_build core gui linguisttools_build widgets
USE_SDL=	sdl2 ttf2 image2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		cmake:noninja qmake compiler:c++11-lib openal
USE_LDCONFIG=	yes

.include <bsd.port.mk>
