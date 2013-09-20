# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	penguin-command
PORTVERSION=	1.6.11
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A clone of the classic game Missile Command

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_SDL=	mixer image sdl
GNU_CONFIGURE=	yes

MAN6=		penguin-command.6 penguin-command.ja.6

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's| -lSDL | |g' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's|LIBS="-lSDL_image|LIBS="-lSDL_image $$SDL_LIBS|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
