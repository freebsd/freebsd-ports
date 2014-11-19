# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	maelstrom
PORTVERSION=	3.0.6
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://slouken.libsdl.org/projects/Maelstrom/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTNAME=	Maelstrom-${PORTVERSION}
DISTFILES=	Maelstrom-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	Maelstrom-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Asteroids-style game for X Window System

LICENSE=	GPLv2

USE_SDL=	sdl net
USE_XORG=	xpm
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/Maelstrom
DOCSDIR=	${PREFIX}/share/doc/Maelstrom

PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

DOCS_INSTALL_TARGET=install install_gamedocs

DESKTOP_ENTRIES="Maelstrom" "" ${PORTNAME} \
		"Maelstrom" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|@prefix@|$${DESTDIR}@prefix@|; \
		s|$$(DESTDIR)$$(bindir)|$$(bindir)|' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
