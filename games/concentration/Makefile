# New ports collection makefile for:	concentration
# Date created:				10 Nov 2005
# Whom:					Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	concentration
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://www.shiftygames.com/concentration/

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Find all matching pairs of icons as fast as possible

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image ttf

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LDFLAGS="`${SDL_CONFIG} --libs`" \
		CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		SDL_CONFIG="${SDL_CONFIG}"

MAN6=		concentration.6

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|g' ${WRKSRC}/configure ${WRKSRC}/src/sound.c
	@${REINPLACE_CMD} -e 's|-std=gnu99 ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
