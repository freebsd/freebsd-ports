# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	maelstrom
PORTVERSION=	3.0.6
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://slouken.libsdl.org/projects/Maelstrom/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTNAME=	Maelstrom-${PORTVERSION}
DISTFILES=	Maelstrom-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	Maelstrom-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Asteroids-style game for X Window System

LICENSE=	GPLv2

USE_SDL=	sdl net
USE_XORG=	xpm
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/Maelstrom
DOCSDIR=	${PREFIX}/share/doc/Maelstrom

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Maelstrom" "" ${PORTNAME} \
		"Maelstrom" "Game;ArcadeGame;" ""

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|prefix = @prefix@|prefix = $${DESTDIR}@prefix@| ; \
		s|$$(DESTDIR)$$(bindir)|$$(bindir)|' \
		${WRKSRC}/Makefile.in

	@(cd ${WRKSRC} ; ${REINPLACE_CMD} \
		-e 's|@CFLAGS@|@CFLAGS@ -w| ; \
		s|$$(CXXFLAGS)|$$(CXXFLAGS) -w|' \
		Makefile.in maclib/Makefile.in \
		netlogic/Makefile.in screenlib/Makefile.in)

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install install_gamedocs
.endif

post-install:
	${CHOWN} root:games ${STAGEDIR}${PREFIX}/bin/Maelstrom
	${CHMOD} 2755 ${STAGEDIR}${PREFIX}/bin/Maelstrom
	${CHMOD} 664 ${STAGEDIR}${PREFIX}/share/Maelstrom/Maelstrom-Scores
	${CHOWN} root:games \
		${STAGEDIR}${PREFIX}/share/Maelstrom/Maelstrom-Scores
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
