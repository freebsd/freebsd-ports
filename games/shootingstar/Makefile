# New ports collection makefile for:	shootingstar
# Date created:				20 Nov 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	shootingstar
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.2ndpoint.fi/projektit.xml/shootingstar/files/ \
		http://www.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	SDL/OpenGL top-down shooter

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl mixer image

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		SDL_CONFIG="${SDL_CONFIG}"

.include <bsd.port.mk>
