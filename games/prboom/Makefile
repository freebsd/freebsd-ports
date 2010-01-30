# New ports collection makefile for:	prboom
# Date created:				10 June 2001
# Whom:					Jordan DeLong <fracture@allusion.net>
#
# $FreeBSD$
#

PORTNAME=	prboom
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiplayer-capable and modified version of ID's classic DOOM game

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_GMAKE=	yes
USE_SDL=	mixer net sdl

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	GL "Enable OpenGL support" on

MAN5=		boom.cfg.5
MAN6=		prboom.6 prboom-game-server.6

DATADIR=	${DMDIR}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_GL)
USE_GL=		yes
.else
CONFIGURE_ARGS+=--disable-gl
.endif

.include <bsd.port.post.mk>
