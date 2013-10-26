# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	duckmaze
DISTVERSION=	0.3r34
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	SF/nemysisfreebsdp/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game about a duck that is in a maze

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}/trunk

USES=		shebangfix
SHEBANG_FILES=	*.py mopelib/mopelib.py
USE_PYTHON=	yes

PORTDOCS=	TODO.txt index.html style.css

SUB_FILES=	${PORTNAME}.sh

DESKTOP_ENTRIES="duckmaze" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

post-extract:
	${MV} ${WRKSRC}/doc/*.png ${WRKSRC}/images/

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images levels mopelib music sounds" ${STAGEDIR}${DATADIR})
.for d in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor
.for d in duckmazerc.txt version
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
