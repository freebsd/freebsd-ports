# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	torrent
PORTVERSION=	0.8.2
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.shiftygames.com/torrent/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Score points without letting the tiles touch the top of the board

GNU_CONFIGURE=	yes
USES=		gmake sdl
USE_SDL=	sdl mixer image ttf

CPPFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS+=	`${SDL_CONFIG} --libs`

PLIST_FILES=	bin/${PORTNAME} man/man6/torrent.6.gz
PORTDATA=	*

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|cpp|h|txt)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

post-patch:
	@${REINPLACE_CMD} -e 's|-std=gnu99 ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
