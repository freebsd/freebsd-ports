# $FreeBSD$

PORTNAME=	solarus
PORTVERSION=	1.1.0
CATEGORIES=	games
MASTER_SITES=	http://www.solarus-games.org/downloads/solarus/
DISTNAME=	solarus-${PORTVERSION}-src

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Zelda-like 2D game engine

LIB_DEPENDS=	libphysfs.so:${PORTSDIR}/devel/physfs \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		liblua-5.1.so:${PORTSDIR}/lang/lua \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg

USE_SDL=	sdl ttf image

PLIST_FILES=	bin/solarus

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		cmake openal

.include <bsd.port.mk>
