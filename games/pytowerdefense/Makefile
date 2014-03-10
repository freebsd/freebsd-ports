# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytowerdefense
PORTVERSION=	0.5
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/PyTowerDefense0.5/Source%20%28Python%202.5%20or%202.6%20and%20Pygame%29/
DISTNAME=	${PORTNAME}${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Tower Defense Game

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

USES=		zip
USE_PYTHON=	2
INSTALLS_ICONS=	yes

PORTDOCS=	README modding.txt

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="PyTowerDefense" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DATADIR}

.for d in  *.py *.pyc *.pyo
	@(cd ${WRKSRC} ; ${INSTALL_SCRIPT} ${d} ${STAGEDIR}${DATADIR})
.endfor

.for d in audio images
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${LN} -sf ${DATADIR}/images/tower_square.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
