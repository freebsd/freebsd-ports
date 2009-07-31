# New ports collection makefile for:	scramble
# Date created:				10 Nov 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	scramble
PORTVERSION=	0.9.5
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.shiftygames.com/scramble/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	From 6 letters you are to create as many words as you can

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image ttf

CONFIGURE_ENV=	LDFLAGS="`${SDL_CONFIG} --libs`" \
		CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		SDL_CONFIG="${SDL_CONFIG}"

MAN6=		scramble.6

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

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|cpp|h|txt)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

.if !exists(${DICTIONARY})
pre-configure:
	@${ECHO} ""
	@${ECHO} "Dictionary ${DICTIONARY} does not exist"
	@${ECHO} "Please, specify correct one with WITH_DICTIONARY option"
	@${FALSE}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-std=gnu99 ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/share/dict/words|${DICTIONARY}|g' ${WRKSRC}/src/scramble.c

.include <bsd.port.post.mk>
