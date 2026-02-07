PORTNAME=	shootingstar
PORTVERSION=	1.2.0
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://www.2ndpoint.fi/projektit.xml/shootingstar/files/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SDL/OpenGL top-down shooter
WWW=		http://www.2ndpoint.fi/ss

GNU_CONFIGURE=	yes
USES=		gl gmake sdl
USE_GL=		gl
USE_SDL=	sdl mixer image

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

.include <bsd.port.mk>
