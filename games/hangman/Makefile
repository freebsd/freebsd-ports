# New ports collection makefile for:	hangman
# Date created:				10 Nov 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	hangman
PORTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.shiftygames.com/hangman/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Challenge your spelling skills in the old western style

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image ttf

CONFIGURE_ENV=	LDFLAGS="`${SDL_CONFIG} --libs`" \
		CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		SDL_CONFIG="${SDL_CONFIG}"

MAN6=		hangman.6

.include <bsd.port.pre.mk>

.if defined(WITH_DICTIONARY)
DICTIONARY=${WITH_DICTIONARY}
.else
DICTIONARY=/usr/share/dict/words

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may want to use different dictionary instead of the default one,"
	@${ECHO} "which is /usr/share/dict/words. If so, use the following option:"
	@${ECHO} ""
	@${ECHO} "	WITH_DICTIONARY=/path/to/your/dictionary"
	@${ECHO} ""
.endif

.if !exists(${DICTIONARY})
pre-configure:
	@${ECHO} ""
	@${ECHO} "Dictionary ${DICTIONARY} does not exist"
	@${ECHO} "Please, specify correct one with WITH_DICTIONARY option"
	@${FALSE}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/dict/words|${DICTIONARY}|g' ${WRKSRC}/src/hangman.c
	@${REINPLACE_CMD} -e 's|-std=gnu99||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
