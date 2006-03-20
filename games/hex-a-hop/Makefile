# New ports collection makefile for:	hex-a-hop
# Date created:				21 February 2006
# Whom:					jamie
#
# $FreeBSD$
#

PORTNAME=	hex-a-hop
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	http://ftp.bishopston.net/freebsd/distfiles/ \
		ftp://ftp.bishopston.net/freebsd/distfiles/

MAINTAINER=	jamie@bishopston.net
COMMENT=	A puzzle game based on hexagonal tiles

USE_SDL=	sdl

MAKEFILE=	Makefile.FreeBSD
ALL_TARGET=	${PORTNAME}

MAKE_ARGS+=	SYSTEM_INSTALL_DIR="${PREFIX}/games/hex-a-hop/"
DESKTOP_ENTRIES="Hex-a-Hop" "A puzzle game based on hexagonal tiles" \
		"${PREFIX}/games/hex-a-hop/graphics/icon.bmp" \
		"hex-a-hop" "Application;LogicGame;Game;" false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hex-a-hop ${PREFIX}/bin
	${MKDIR} ${PREFIX}/games/hex-a-hop/graphics/
	${INSTALL_DATA} ${WRKSRC}/graphics/* ${PREFIX}/games/hex-a-hop/graphics
	${INSTALL_DATA} ${WRKSRC}/levels.dat ${PREFIX}/games/hex-a-hop

.include <bsd.port.mk>
