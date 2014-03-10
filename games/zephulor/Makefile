# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	zephulor
PORTVERSION=	1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/apz/apz/stable/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-source${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-source${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Side scrolling arcade game

LICENSE=	LGPL20

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}tkinter>=0:${PORTSDIR}/x11-toolkits/py-tkinter

WRKSRC=		${WRKDIR}/zephulor-source

USE_PYTHON=	2
NO_BUILD=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt manual.txt readme-*.txt

DOCSRCDIR2=	${WRKSRC}/maptool
DOCSDIR2=	${DOCSDIR}/maptool
DOC_FILES2=	manual.txt

DESKTOP_ENTRIES="Adventures on Planet Zephulor" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

SUB_FILES=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|#!.*python|#!${PYTHON_CMD}|' \
		${WRKSRC}/*.py ${WRKSRC}/maptool/*.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}/maptool/
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/maptool/*.py ${STAGEDIR}${DATADIR}/maptool/

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
