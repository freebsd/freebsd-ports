# New ports collection makefile for:	cuyo
# Date created:				1 June 2009
# Whom:					Matthew Gibson <mdg583@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	cuyo
PORTVERSION=	2.1.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://mirror.publicns.net/pub/nongnu/cuyo/
DISTNAME=	${PORTNAME}-2.~-1.1

MAINTAINER=	mdg583@gmail.com
COMMENT=	Nice, innovative, challenging Tetris-like game

LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib mikmod.2:${PORTSDIR}/audio/libmikmod

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	mixer image
USE_XORG=	xdmcp xau x11
USE_ICONV=	yes
INSTALLS_ICONS=	yes

MAN6=		cuyo.6 cual.6

post-install:
	@${ECHO} Installing ${PREFIX}/share/pixmaps/cuyo.png
	@${INSTALL_DATA} ${WRKSRC}/icons/cuyo-32x32.png ${PREFIX}/share/pixmaps/cuyo.png

.include <bsd.port.mk>
