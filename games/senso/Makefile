# New ports collection makefile for:	senso
# Date created:				2002-01-09
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	senso
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://stud.fbi.fh-darmstadt.de/~koenig/pub/
EXTRACT_SUFX=	.py

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Game to challenge short-term memory

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}

do-extract:
	${MKDIR} ${WRKDIR}

pre-install:
	${ECHO_CMD} "bin/senso" > ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${_DISTDIR}/${DISTFILES} ${PREFIX}/bin/senso

.include <bsd.port.mk>
