# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	bubbros
PORTVERSION=	1.6.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/bub-n-bros/bub-n-bros/${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer clone of the famous Bubble Bobble game

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYGAME}
BUILD_DEPENDS=	${PYGAME}

USES=		python:2.7 shebangfix xorg
SHEBANG_FILES=	BubBob.py
USE_XORG=	x11 xext

PORTDOCS=	*.html

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Bub-n-Bros" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/display/setup.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete -or -name "*.orig" -delete \
		-or -name "*.cvsignore" -delete
	@${FIND} ${WRKSRC} -name CVS -print0 | ${XARGS} -0 ${RM} -r

do-build:
	# Compile the statesaver extension module
	cd ${WRKSRC}/bubbob; ${PYTHON_CMD} setup.py build_ext -i
	# Compile the X-window client extension module
	cd ${WRKSRC}/display; ${PYTHON_CMD} setup.py build_ext -i
.for d in bubbob display
	@(cd ${WRKSRC}/${d} && ${RM} -r build)
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for d in bubbob common display http2 java metaserver
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/BubBob.py ${STAGEDIR}${DATADIR}
	# build different colors
	@${FIND} ${STAGEDIR}${DATADIR} -name "*.ppm" -exec ${CHMOD} u+w {} \;
	@${PYTHON_CMD} ${STAGEDIR}${DATADIR}/bubbob/images/buildcolors.py
	${LN} -sf ${DATADIR}/http2/data/bob.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.for l in bubbob/statesaver.so display/xshm.so
	@${CHMOD} u+w ${STAGEDIR}${DATADIR}/${l}
	@${STRIP_CMD} ${STAGEDIR}${DATADIR}/${l}
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
