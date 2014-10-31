# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	secrettower
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	games python
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Save princess Ericia in this 2D platform game

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYGAME}

USE_GITHUB=	yes
GH_ACCOUNT=	dusty141
GH_PROJECT=	TheSecretTower
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ecf13e4

USES=		python:2 shebangfix
SHEBANG_FILES= 	TheSecretTower.py server.py

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} pkg-deinstall

DESKTOP_ENTRIES="The Secret Tower" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for d in data img sound
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
.for f in *.py *.pyc *.pyo
	@(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${f} ${STAGEDIR}${DATADIR})
.endfor
	${LN} -sf ${DATADIR}/img/perso_small.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} -R 775 data)

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
