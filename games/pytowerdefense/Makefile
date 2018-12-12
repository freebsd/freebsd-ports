# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytowerdefense
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/PyTowerDefense0.5/Source%20%28Python%202.5%20or%202.6%20and%20Pygame%29/
DISTNAME=	${PORTNAME}${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tower Defense Game

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

USES=		python:2.7 shebangfix zip
SHEBANG_FILES=	pyconsole.py
INSTALLS_ICONS=	yes
NO_ARCH=	yes

PORTDOCS=	README modding.txt
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="PyTowerDefense" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in audio images
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
.for f in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

	${LN} -sf ${DATADIR}/images/tower_square.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
