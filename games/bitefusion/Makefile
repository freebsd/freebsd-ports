# New ports collection makefile for:	bitefusion
# Date created:		14 Jun 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	bitefusion
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.junoplay.com/files/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A snake game with 8 levels

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		LDFLAGS="`${SDL_CONFIG} --libs`"

PLIST_FILES=	bin/bitefusion

post-patch:
	@${REINPLACE_CMD} -e 's|-linux-gnu|-portbld-freebsd|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lSDL||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
