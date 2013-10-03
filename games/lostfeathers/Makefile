# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lostfeathers
PORTVERSION=	1.0b
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Help a bird to recover his magical feathers

LICENSE=	BSD

RUN_DEPENDS=	avbin>=0:${PORTSDIR}/multimedia/avbin

USE_ZIP=	yes
USE_GNOME=	pygtk2 librsvg2
USE_PYTHON=	yes

PORTDOCS=	README.txt

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="The Lost Feathers" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in cocos data gamelib pyglet
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/run_game.py ${STAGEDIR}${DATADIR}

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
