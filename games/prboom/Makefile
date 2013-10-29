# Created by: Jordan DeLong <fracture@allusion.net>
# $FreeBSD$

PORTNAME=	prboom
PORTVERSION=	2.5.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer-capable and modified version of ID's classic DOOM game

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_GMAKE=	yes
USE_SDL=	mixer net sdl

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	OPENGL
OPTIONS_DEFAULT=	OPENGL

MAN5=		boom.cfg.5
MAN6=		prboom.6 prboom-game-server.6

DATADIR=	${DMDIR}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

NO_STAGE=	yes
.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		yes
.else
CONFIGURE_ARGS+=--disable-gl
.endif

.include <bsd.port.mk>
