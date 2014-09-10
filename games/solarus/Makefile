# $FreeBSD$

PORTNAME=	solarus
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.solarus-games.org/downloads/solarus/
DISTNAME=	solarus-${PORTVERSION}-src

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Zelda-like 2D game engine

LIB_DEPENDS=	libphysfs.so:${PORTSDIR}/devel/physfs \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		liblua-5.1.so:${PORTSDIR}/lang/lua51 \
		libluajit-5.1.so:${PORTSDIR}/lang/luajit \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg

USE_SDL=	sdl2 ttf2 image2

PLIST_FILES=	bin/solarus

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		cmake openal

.include <bsd.port.mk>
