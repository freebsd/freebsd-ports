# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xgalaga++
PORTVERSION=	0.9
CATEGORIES=	games
MASTER_SITES=	http://marc.mongenet.ch/OSS/XGalaga/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Classic single screen vertical shoot em up

LICENSE=	GPLv2

USES=		gmake xorg
USE_XORG=	x11 xpm

ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="XGalaga++" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|CXX =|CXX ?=|; \
		s|HIGH_SCORES_FILE=/var|#HIGH_SCORES_FILE=/var|; \
		s|#HIGH_SCORES_FILE=.xgalaga++|HIGH_SCORES_FILE=.xgalaga++|; \
		s|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6x \
		${STAGEDIR}${MAN6PREFIX}/man/man6/${PORTNAME}.6
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
