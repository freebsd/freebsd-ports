# New ports collection makefile for:	penguin-command
# Date created:			Apr 4, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	penguin-command
PORTVERSION=	1.6.11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	A clone of the classic game Missile Command

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_SDL=	mixer image sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man --program-prefix=""

MAN6=		penguin-command.6 penguin-command.ja.6

post-patch:
	@${REINPLACE_CMD} 's| -lSDL | |g' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's|LIBS="-lSDL_image|LIBS="-lSDL_image $$SDL_LIBS|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
