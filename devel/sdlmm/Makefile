# ex:ts=8
# New ports collection makefile for:	SDLmm
# Date created:			Jun 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdlmm
PORTVERSION=	0.1.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	SDLmm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ Wrapper for the SDL (Simple DirectMedia Layer)

USE_SDL=	sdl
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=	SDLmm.3 SDLmm_Audio.3 SDLmm_BaseSurface.3 SDLmm_CD.3 SDLmm_ColorRGB.3 \
	SDLmm_ColorRGBA.3 SDLmm_Display.3 SDLmm_Event.3 SDLmm_EventHandler.3 \
	SDLmm_Joystick.3 SDLmm_PixelFormat.3 SDLmm_SPoint.3 SDLmm_SRect.3 \
	SDLmm_Surface.3 SDLmm_Timer.3 SDLmm_VideoInfo.3 SDLmm_todo.3 sdlmm.h.3

.include <bsd.port.mk>
