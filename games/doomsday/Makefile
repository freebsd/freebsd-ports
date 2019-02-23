# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	doomsday
PORTVERSION=	2.1.1
CATEGORIES=	games
MASTER_SITES=	SF/deng/Doomsday%20Engine/${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Enhanced Doom, Heretic, and Hexen source port

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libassimp.so:multimedia/assimp \
		libfluidsynth.so:audio/fluidsynth
RUN_DEPENDS=	timidity:audio/timidity

USES=		cmake compiler:c++11-lib gl localbase:ldflags ninja openal pkgconfig \
		python:2.7,build qt:5 sdl

USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_SDL=	sdl2 mixer2
USE_XORG=	x11 sm ice xext xrandr xxf86vm
USE_QT=		buildtools_build core gui network widgets qmake_build opengl x11extras
CMAKE_ARGS+=	-DDENG_ENABLE_COTIRE=OFF -DDENG_ASSIMP_EMBEDDED=OFF
LDFLAGS+=	-lexecinfo

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}

PORTSCOUT=	limit:^\d+\.\d+\.\d+$$

post-patch:
	# Removing (three) non-ascii bytes from the beginning of the file
	@${REINPLACE_CMD} '1s,^...,,' \
		${WRKSRC}/apps/client/src/client/cl_sound.cpp
	@${REINPLACE_CMD} -E 's|(DENG_DISTRIB_DIR /usr)|\1/local|' \
		${WRKSRC}/cmake/Config.cmake

.include <bsd.port.mk>
