# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdlmm
PORTVERSION=	0.1.8
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/SDLmm/${PORTVERSION}
DISTNAME=	SDLmm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ Wrapper for the SDL (Simple DirectMedia Layer)

USE_AUTOTOOLS=	libtool
USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=	SDLmm.3 SDLmm_Audio.3 SDLmm_BaseSurface.3 SDLmm_CD.3 SDLmm_ColorRGB.3 \
	SDLmm_ColorRGBA.3 SDLmm_Display.3 SDLmm_Event.3 SDLmm_EventHandler.3 \
	SDLmm_Joystick.3 SDLmm_PixelFormat.3 SDLmm_SPoint.3 SDLmm_SRect.3 \
	SDLmm_Surface.3 SDLmm_Timer.3 SDLmm_VideoInfo.3 SDLmm_todo.3 sdlmm.h.3

NO_STAGE=	yes
.include <bsd.port.mk>
