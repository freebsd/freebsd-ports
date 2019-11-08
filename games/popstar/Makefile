# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	popstar
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/popstar/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple puzzle game involving floating stars

LICENSE=	GPLv2+ CC-BY-SA-2.5 CC-BY-3.0
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/docs/COPYING-CC-Attrib30.txt

USES=		gmake sdl
USE_SDL=	image mixer sdl

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Pop Star" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in images music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
