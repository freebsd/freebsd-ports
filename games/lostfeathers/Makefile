# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lostfeathers
PORTVERSION=	1.0b
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Help a bird to recover his magical feathers

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	avbin>=0:${PORTSDIR}/multimedia/avbin

USES=		python shebangfix zip
SHEBANG_FILES=	run_game.py
USE_GNOME=	pygtk2 librsvg2

PORTDOCS=	README.txt
OPTIONS_DEFINE=	DOCS

# Wrong versioning upstream
PORTSCOUT=	skipv:1.0

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="The Lost Feathers" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in cocos data gamelib pyglet
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
.for f in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
