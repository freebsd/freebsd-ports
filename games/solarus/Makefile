# $FreeBSD$

PORTNAME=	solarus
PORTVERSION=	1.0.4
CATEGORIES=	games
MASTER_SITES=	http://www.zelda-solarus.com/zs/download/
DISTNAME=	solarus-src
EXTRACT_SUFX=

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Zelda-like 2D game engine

LIB_DEPENDS=	libphysfs.so:${PORTSDIR}/devel/physfs \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		liblua-5.1.so:${PORTSDIR}/lang/lua \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libopenal.so:${PORTSDIR}/audio/openal \
		libogg.so:${PORTSDIR}/audio/libogg

USE_SDL=	sdl ttf image

PLIST_FILES=	bin/solarus

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		cmake

.include <bsd.port.mk>
