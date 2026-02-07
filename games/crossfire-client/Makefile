PORTNAME=	crossfire-client
DISTVERSION=	1.75.5
CATEGORIES=	games
MASTER_SITES=	SF/crossfire/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Cooperative multiplayer graphical RPG and adventure game
WWW=		https://crossfire.real-time.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png

USES=		cmake gnome perl5 pkgconfig sdl vala:build xorg
USE_GNOME=	gtk20
USE_PERL5=	build
USE_SDL=	mixer2 sdl2
USE_XORG=	ice sm x11 xext

CMAKE_ON=	METASERVER2 SOUND
CMAKE_OFF=	LUA

.include <bsd.port.mk>
