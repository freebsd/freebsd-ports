# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	pycadia
PORTVERSION=	0.5.1
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_GENTOO:S/%SUBDIR%/distfiles/} \
		SF/nemysisfreebsdp/games/
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Home to vector gaming, Python style

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	pygtk2 libgnomeui
USE_PYTHON=	yes

PORTDOCS=	CHANGELOG README TODO gravity.txt

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
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.for d in glade pixmaps sounds
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

.for d in  *.py *.pyc *.pyo
	@(cd ${WRKSRC} ; ${INSTALL_SCRIPT} ${d} ${STAGEDIR}${DATADIR})
.endfor

	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} 555 ${PORTNAME}.py spacewarpy.py vektoroids.py)
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf ${STAGEDIR}${DATADIR}

	${INSTALL_DATA} ${WRKSRC}/pixmaps/pysteroids.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
