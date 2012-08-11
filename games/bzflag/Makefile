# New ports collection makefile for: bzflag
# Date created:		2000/08/12
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	bzflag
PORTVERSION=	2.4.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source/${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	A multiplayer 3D tank battle game

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GL=		glew
USE_SDL=	sdl

CONFIGURE_ARGS=	--enable-ares-build
CPPFLAGS+=	-I ${LOCALBASE}/include

DESKTOP_ENTRIES=	"BZFlag" "Battle enemy tanks" \
			"${DATADIR}/bzflag-256x256.png" \
			"bzflag" "Game;ActionGame;" false

MAN5=	bzw.5
MAN6=	bzadmin.6 bzflag.6 bzfs.6

.include <bsd.port.mk>
