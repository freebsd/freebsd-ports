# ex:ts=8
# New ports collection makefile for:	SDLmm
# Date created:			Jun 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdlmm
PORTVERSION=	0.1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	SDLmm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${SDL_CONFIG}
INSTALLS_SHLIB=	yes

MAN3=	SDLmm.3 SDLmm__Audio.3 SDLmm__BaseSurface.3 SDLmm__CD.3 \
	SDLmm__Display.3 SDLmm__Event.3 SDLmm__EventHandler.3 \
	SDLmm__Joystick.3 SDLmm__SRect.3 SDLmm__Surface.3 SDLmm__Timer.3 \
	SDLmm__VideoInfo.3

.include <bsd.port.mk>
