# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	pythonchess
PORTVERSION=	0.7
CATEGORIES=	games
MASTER_SITES=	http://sites.google.com/site/purplesaguaroinc/myfiles/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	${PORTNAME:S/p/P/:S/c/C/}_v${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME:S/p/P/:S/c/C/}_v${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small program for playing chess against the computer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

WRKSRC=		${WRKDIR}/${PORTNAME:S/p/P/:S/c/C/}

USES=		dos2unix python:2 zip
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Python Chess" "" "${PORTNAME}" \
                "${PORTNAME}" "Game;BoardGame;" ""

post-patch:
	@${FIND} ${WRKDIR} -name Thumbs.db -or -name pygame2exe_Chess.py | \
		${XARGS} ${RM} -r
	@${REINPLACE_CMD} -e 's|^.*#!.*python.*$$|#!${PYTHON_CMD}|' \
		${WRKSRC}/*.py
	@(cd ${WRKSRC} && ${RM} *.py.bak)

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@(cd ${WRKSRC} && ${COPYTREE_SHARE} images ${STAGEDIR}${DATADIR})
.for f in *.py *.pyc *.py
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
