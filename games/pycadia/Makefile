# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pycadia
PORTVERSION=	0.5.1
PORTREVISION=	6
CATEGORIES=	games python
MASTER_SITES=	GENTOO/distfiles \
		SF/nemysisfreebsdp/games/
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Home to vector gaming, Python style

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		python:2
USE_GNOME=	pygtk2 libgnomeui

PORTDOCS=	CHANGELOG README gravity.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Pycadia" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

SUB_FILES=	${PORTNAME}.sh

post-patch:
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.for d in glade pixmaps sounds
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
.for f in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} 555 \
		 ${PORTNAME}.py spacewarpy.py vektoroids.py)
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf ${STAGEDIR}${DATADIR}

	${INSTALL_DATA} ${WRKSRC}/pixmaps/pysteroids.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
