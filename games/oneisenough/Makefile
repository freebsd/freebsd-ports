# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oneisenough
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://hectigo.net/games/oneisenough/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	${PORTNAME}_a${PORTVERSION:S/.//g}_src${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}_a${PORTVERSION:S/.//g}_src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Economic development in the land of the balls

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/"one is enough"

USES=		dos2unix python:2.7 shebangfix zip
DOS2UNIX_FILES=	*.txt bin/*.py
DOS2UNIX_REGEX= .*.[^pt][^nt][^gf]
SHEBANG_FILES=	run_game.py bin/mainmenu.py
NO_ARCH=	yes

PORTDOCS=	README.txt
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="One Is Enough" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

post-extract:
	@${FIND} ${WRKSRC} \
		-name "Thumbs.db" -delete -or -name "pack.bat" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC}/bin && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/bin)
.for f in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
