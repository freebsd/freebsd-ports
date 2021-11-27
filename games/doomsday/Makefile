# Created by: Igor Pokrovsky <ip@doom.homeunix.org>

PORTNAME=	doomsday
PORTVERSION=	2.3.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/deng/Doomsday%20Engine/${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Enhanced Doom, Heretic, and Hexen source port

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libassimp.so:multimedia/assimp \
		libfluidsynth.so:audio/fluidsynth
RUN_DEPENDS=	timidity:audio/timidity

USES=		cmake compiler:c++11-lib gl localbase:ldflags ncurses ninja openal pkgconfig \
		python:3.5+,build qt:5 sdl xorg

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
	@${REINPLACE_CMD} -E -e 's|(DENG_DISTRIB_DIR /usr)|\1/local|' \
		-e 's|python3|${PYTHON_VERSION}|' \
		${WRKSRC}/cmake/Config.cmake
	@cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete

.include <bsd.port.mk>
