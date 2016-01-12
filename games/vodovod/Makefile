# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vodovod
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/vodovod/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Cross-platform pipe connecting action puzzle game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-src

USES=		gmake
USE_SDL=	image mixer sdl

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CHANGES

DOCSRCDIR2=	${WRKSRC}/html
DOCSDIR2=	${DOCSDIR}/html
DOC_FILES2=	*.gif *.png *.jpg *.html

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Vodovod" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX=/usr|PREFIX=${PREFIX}|' \
		-e 's|CC = g++|CC ?= g++|' \
		-e 's|CC|CXX|' \
		-e 's|sdl-config|$(SDL_CONFIG)|' \
		-e '/^MY_CFLAGS/ s| = | = ${CXXFLAGS} |' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data icon.ico" ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
