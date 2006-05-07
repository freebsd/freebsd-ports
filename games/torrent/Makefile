# New ports collection makefile for:	torrent
# Date created:		10 Nov 2005
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	torrent
PORTVERSION=	0.8.2
CATEGORIES=	games
MASTER_SITES=	http://www.shiftygames.com/torrent/

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Score points without letting the tiles touch the top of the board

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image ttf

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LDFLAGS="`${SDL_CONFIG} --libs`" \
		CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		SDL_CONFIG="${SDL_CONFIG}"

MAN6=		torrent.6

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|cpp|h|txt)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|g; s|-std=gnu99 ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
