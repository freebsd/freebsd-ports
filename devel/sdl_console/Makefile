# New ports collection makefile for:	SDL Console
# Date created:				2008-04-27
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_console
PORTVERSION=	2.1
CATEGORIES=	devel
MASTER_SITES=	SF/sdlconsole/sdlconsole-source/sdlconsole-${PORTVERSION}
DISTNAME=	sdlconsole-${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A drop down console that can be easily added to any SDL application

USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS=	SDL_IMAGE "SDL Image support" Off

post-patch:
	@${REINPLACE_CMD} -e '/objformat/s/aout/elf/' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>

.if defined(WITH_SDL_IMAGE)
USE_SDL+=	image
.endif

.include <bsd.port.post.mk>
