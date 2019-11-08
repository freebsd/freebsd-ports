# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	entombed
PORTVERSION=	2007.07.04
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/entombed/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	One- or two-player maze game based on the Entombed

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

USES=		gmake sdl
USE_SDL=	image mixer sdl

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Entombed" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in embedded images images_halfsize music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
