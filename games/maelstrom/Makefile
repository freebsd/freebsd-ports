# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	maelstrom
PORTVERSION=	3.0.6
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://slouken.libsdl.org/projects/Maelstrom/src/ \
		SF/nemysisfreebsdp/:icons
DISTNAME=	Maelstrom-${PORTVERSION}
DISTFILES=	Maelstrom-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	Maelstrom-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Asteroids-style game for X Window System

LICENSE=	GPLv2

USE_SDL=	sdl net
USE_XORG=	xpm
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/Maelstrom
DOCSDIR=	${PREFIX}/share/doc/Maelstrom
PORTDOCS=	*

DESKTOP_ENTRIES="Maelstrom" "${COMMENT}" ${PORTNAME} \
		"Maelstrom" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install install_gamedocs
.endif

post-install:
	${CHOWN} root:games ${PREFIX}/bin/Maelstrom
	${CHMOD} 2755 ${PREFIX}/bin/Maelstrom
	${CHMOD} 664 ${PREFIX}/share/Maelstrom/Maelstrom-Scores
	${CHOWN} root:games ${PREFIX}/share/Maelstrom/Maelstrom-Scores
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
