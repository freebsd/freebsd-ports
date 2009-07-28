# New ports collection makefile for:	pengupop
# Date created:		14 Jun 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	pengupop
PORTVERSION=	2.2.5
CATEGORIES=	games
MASTER_SITES=	http://www.junoplay.com/files/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Online multiplayer clone of Bust a Move

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		LDFLAGS="`${SDL_CONFIG} --libs`"

PLIST_FILES=	bin/pengupop

post-patch:
	@${REINPLACE_CMD} -e 's|-lSDL||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
