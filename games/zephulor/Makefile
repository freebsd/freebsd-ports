# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	zephulor
PORTVERSION=	1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/apz/apz/stable/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-source${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-source${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Side scrolling arcade game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR}

WRKSRC=		${WRKDIR}/zephulor-source

USES=		python:2
NO_BUILD=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Adventures on Planet Zephulor" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

SUB_FILES=	${PORTNAME}

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
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"README.txt manual.txt readme-*.txt maptool/manual.txt" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
