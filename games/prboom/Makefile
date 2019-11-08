# Created by: Jordan DeLong <fracture@allusion.net>
# $FreeBSD$

PORTNAME=	prboom
PORTVERSION=	2.5.0
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION}

MAINTAINER=	thiagohero501@gmail.com
COMMENT=	Multiplayer-capable and modified version of ID's classic DOOM game

LICENSE=	GPLv2

LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg

USES=		gmake sdl
USE_SDL=	mixer net sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-i386-asm
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	OPENGL
OPTIONS_DEFAULT=	OPENGL

DATADIR=	${LOCALBASE}/share/doom
PLIST_SUB=	PORTVERSION=${PORTVERSION}

SUB_FILES=	pkg-message

OPENGL_CONFIGURE_ENABLE=	gl
OPENGL_USES=	gl
OPENGL_USE=	GL=glu

.include <bsd.port.mk>
