# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oneisenough
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://hectigo.net/games/oneisenough/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	${PORTNAME}_a${DISTVERSION:S/.//g}_src${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}_a${DISTVERSION:S/.//g}_src${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Economic development in the land of the balls

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/"one is enough"

USES=		dos2unix zip
DOS2UNIX_FILES=	README.txt bin/*.py
DOS2UNIX_REGEX= .*.[^pt][^nt][^gf]
USE_PYTHON=	2

PORTDOCS=	README.txt

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="One Is Enough" "" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-extract:
	@${FIND} ${WRKSRC} \
		-name "Thumbs.db" -delete -or -name "pack.bat" -delete

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/run_game.py

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in  *.py *.pyc *.pyo
	@(cd ${WRKSRC} ; ${INSTALL_SCRIPT} ${d} ${STAGEDIR}${DATADIR})
.endfor

	@(cd ${WRKSRC}/bin && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/bin)

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
