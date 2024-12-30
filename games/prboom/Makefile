PORTNAME=	prboom
DISTVERSION=	2.5.0
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION}

MAINTAINER=	thiagohero501@gmail.com
COMMENT=	Multiplayer-capable and modified version of ID's classic DOOM game
WWW=		https://prboom.sourceforge.net/

LICENSE=	GPLv2

DEPRECATED=	Unmaintained, use games/prboom-plus instead
EXPIRATION_DATE=	2025-01-30

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake localbase:ldflags sdl
USE_GL=		gl
USE_SDL=	mixer net sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-i386-asm

DATADIR=	${LOCALBASE}/share/doom
SUB_FILES=	pkg-message

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	OPENGL
OPTIONS_DEFAULT=	OPENGL

OPENGL_USES=	gl
OPENGL_USE=	GL=glu
OPENGL_CONFIGURE_ENABLE=	gl

.include <bsd.port.mk>
