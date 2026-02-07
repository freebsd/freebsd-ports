PORTNAME=	hangman
PORTVERSION=	0.9.2
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://www.shiftygames.com/hangman/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Challenge your spelling skills in the old western style
WWW=		http://www.shiftygames.com/hangman/hangman.html

CONFLICTS=	bsdgames

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		gmake sdl
USE_CSTD=	gnu89
USE_SDL=	sdl mixer image ttf

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
CPPFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS+=	`${SDL_CONFIG} --libs`

PLIST_FILES=	bin/${PORTNAME} share/man/man6/${PORTNAME}.6.gz
PORTDATA=	*

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
