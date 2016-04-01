# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	doomsday
PORTVERSION=	1.15.8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/deng/Doomsday%20Engine/${PORTVERSION}
DISTNAME=	${PORTNAME}-stable-${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Enhanced Doom, Heretic, and Hexen source port

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libassimp.so:multimedia/assimp
RUN_DEPENDS=	timidity:audio/timidity

USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_SDL=	sdl2 mixer2 net2
USE_XORG=	x11
USES=		compiler:c++11-lib execinfo pkgconfig python:build qmake:outsource
USE_QT4=	corelib network opengl moc_build
QMAKE_SOURCE_PATH=	${WRKSRC}/doomsday
QMAKE_ARGS+=	QMAKE_LFLAGS+="-Wl,--export-dynamic" \
		CONFIG+="deng_notools deng_nosnowberry" \
		SCRIPT_PYTHON=${PYTHON_CMD}
LDFLAGS+=	-lm

OPTIONS_DEFINE=	OPENAL
OPTIONS_SUB=	yes

OPENAL_DESC=	Build OpenAL sound plugin
OPENAL_USES=	openal:al
OPENAL_QMAKE_ON=	CONFIG+=deng_openal
OPENAL_QMAKE_OFF=	CONFIG+=deng_noopenal

PORTSCOUT=	limit:^\d+\.\d+\.\d+$$

post-patch:
	@${REINPLACE_CMD} 's,share/man,man,' \
		${WRKSRC}/doomsday/client/client.pro \
		${WRKSRC}/doomsday/server/server.pro
	# Removing (three) non-ascii bytes from the beginning of the file
	@LANG=C ${REINPLACE_CMD} '1s,^...,,' \
		${WRKSRC}/doomsday/client/src/client/cl_sound.cpp

.include <bsd.port.mk>
