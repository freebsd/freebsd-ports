# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	super_mario_bros_python
PORTVERSION=	0.1
CATEGORIES=	games python
MASTER_SITES=	SF/supermariobrosp/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	Super-Mario-Bros-Python-v${DISTVERSION}release${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	Super-Mario-Bros-Python-v${DISTVERSION}release${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Clone of the original Super Mario Bros

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/Super-Mario-Bros-Python-v${DISTVERSION}release

USES=		zip
USE_PYTHON=	2

PORTDOCS=	changelog.txt readme.txt

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Super Mario Bros. Python" "" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -i '' -e '1d' ${WRKSRC}/start.py
	@${FIND} ${WRKSRC} -name "*.py~" -delete -or -name "*.sav~" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in data gamelib
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

.for d in  *.py *.pyc *.pyo
	@(cd ${WRKSRC} ; ${INSTALL_SCRIPT} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
