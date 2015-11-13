# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	schwarzweiss
PORTVERSION=	20110806
PORTREVISION=	2
CATEGORIES=	games python
MASTER_SITES=	SF/nemysisfreebsdp/games/:icons
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tank game for 2 players

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/gpl.txt

RUN_DEPENDS=	${PYGAME}

USE_GITHUB=	yes
GH_ACCOUNT=	horstjens
GH_TAGNAME=	d95263f

USES=		python:2 shebangfix
SHEBANG_FILES=	schwarzweiss_start.py data/*.py

PORTDOCS=	readme.txt
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="SchwarzWeiss" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})
.for f in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
