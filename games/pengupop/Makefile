# New ports collection makefile for:	pengupop
# Date created:		14 Jun 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	pengupop
PORTVERSION=	2.1.9
CATEGORIES=	games
MASTER_SITES=	http://www.junoplay.com/files/ \
		http://www.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Online multiplayer clone of Bust a Move

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GCC=	3.4+
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		LDFLAGS="`${SDL_CONFIG} --libs`"

PLIST_FILES=	bin/pengupop

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not build on FreeBSD 4.x: lack of swprintf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lSDL||' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
