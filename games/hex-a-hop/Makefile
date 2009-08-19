# New ports collection makefile for:	hex-a-hop
# Date created:				21 February 2006
# Whom:					jamie
#
# $FreeBSD$
#

PORTNAME=	hex-a-hop
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://ftp.bishopston.net/freebsd/distfiles/ \
		ftp://ftp.bishopston.net/freebsd/distfiles/ \
		http://critical.ch/distfiles/

MAINTAINER=	jamie@bishopston.net
COMMENT=	A puzzle game based on hexagonal tiles

USE_SDL=	sdl
MAKEFILE=	Makefile.FreeBSD
ALL_TARGET=	${PORTNAME}

MAKE_ARGS+=	SYSTEM_INSTALL_DIR="${DATADIR}/"
DESKTOP_ENTRIES="Hex-a-Hop" "A puzzle game based on hexagonal tiles" \
		"${DATADIR}/graphics/icon.bmp" \
		"hex-a-hop" "Application;LogicGame;Game;" false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hex-a-hop ${PREFIX}/bin
	${MKDIR} ${DATADIR}/graphics
	${INSTALL_DATA} ${WRKSRC}/graphics/* ${DATADIR}/graphics/
	${INSTALL_DATA} ${WRKSRC}/levels.dat ${DATADIR}/

.include <bsd.port.mk>
