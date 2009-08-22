# New ports collection makefile for:    bub-n-bros
# Date created:         		26 January 2005
# Whom:                 		Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	bubbros
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/bub-n-bros/bub-n-bros/${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Multiplayer clone of the famous Bubble Bobble game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PYTHON=	yes
USE_BZIP2=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/display/setup.py

do-build:
	# Compile the statesaver extension module
	cd ${WRKSRC}/bubbob; ${PYTHON_CMD} setup.py build_ext -i
	# Compile the X-window client extension module
	cd ${WRKSRC}/display; ${PYTHON_CMD} setup.py build_ext -i

do-install:
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}; tar --exclude build --exclude "*.orig" --exclude "*.bak" -cf - bubbob common display http2 java metaserver BubBob.py) | \
		(cd ${DATADIR}; tar --unlink -xf -)
	@${PRINTF} "#!/bin/sh\ncd ${DATADIR} && \
		exec ${PYTHON_CMD} ${DATADIR}/BubBob.py\n" > ${WRKDIR}/bubbros.sh
	# build different colors
	@${PYTHON_CMD} ${DATADIR}/bubbob/images/buildcolors.py
	@${INSTALL_SCRIPT} ${WRKDIR}/bubbros.sh ${PREFIX}/bin/bubbros

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc; tar -cf - .) | \
		(cd ${DOCSDIR}; tar --unlink -xf -)
.endif

.include <bsd.port.mk>
