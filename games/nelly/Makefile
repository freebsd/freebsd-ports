# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	nelly
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	http://www.partiallydisassembled.net/nelly/ \
		http://media.pyweek.org/dl/2/rushed/ \
		SF/nemysisfreebsdp/games/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Nelly's Rooftop Garden, physics-based puzzle game

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl

USE_PYTHON_RUN=	yes
NO_BUILD=	yes

PORTDOCS=	README

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Nelly's Rooftop Garden" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/*.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}

.for d in fonts levels textures
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
