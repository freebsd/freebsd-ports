# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chromium-bsu
PORTVERSION=	0.9.15.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Chromium%20B.S.U.%20source%20code/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade-style, top-scrolling space shooter

LIB_DEPENDS=	libglpng.so:graphics/glpng \
		libftgl.so:graphics/ftgl \
		libfontconfig.so:x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USES=		localbase pkgconfig
USE_GL=		gl glu
CONFIGURE_ARGS=	--disable-glc
INSTALLS_ICONS=	yes

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SINGLE=	AUDIO VIDEO
OPTIONS_SINGLE_AUDIO=	OPENAL SDL_MIXER
OPTIONS_SINGLE_VIDEO=	SDL GLUT
OPTIONS_DEFAULT=	OPENAL SDL
OPTIONS_SUB=	yes

VIDEO_DESC=	Video output selection
AUDIO_DESC=	Audio output selection
OPENAL_DESC=	Use OpenAL for audio
SDL_MIXER_DESC=	Use SDL_mixer for audio
SDL_DESC=	Use SDL for video output
GLUT_DESC=	Use GLUT for video output

SDL_MIXER_USE=		SDL=mixer
SDL_MIXER_CONFIGURE_ENABLE=sdlmixer
OPENAL_USES=		openal:al,alut
OPENAL_CONFIGURE_ENABLE=openal
GLUT_USE=		GL=glut
GLUT_CONFIGURE_ENABLE=	glut
SDL_USE=		SDL=sdl,image
SDL_CONFIGURE_ENABLE=	sdl sdlimage
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
