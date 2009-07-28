# New ports collection makefile for:	concentration
# Date created:				10 Nov 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	concentration
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.shiftygames.com/concentration/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Find all matching pairs of icons as fast as possible

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image ttf

CONFIGURE_ENV=	LDFLAGS="`${SDL_CONFIG} --libs`" \
		CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		SDL_CONFIG="${SDL_CONFIG}"

MAN6=		concentration.6

post-patch:
	@${REINPLACE_CMD} -e 's|-std=gnu99 ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
