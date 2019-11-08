# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fightorperish
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/fop/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	fop-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	fop-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dungeon-crawling game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

WRKSRC=		${WRKDIR}/fop-${DISTVERSION}

USES=		gmake sdl
USE_SDL=	image mixer sdl

PORTDOCS=	CHANGES.txt README.txt

DESKTOP_ENTRIES="Fight or Perish" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/data/|' \
		 ${WRKSRC}/src/fop.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fop ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "images maps sounds" \
		${STAGEDIR}${DATADIR}/data)
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
