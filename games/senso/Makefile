# New ports collection makefile for:	senso
# Date created:				2002-01-09
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	senso
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.v-i-t.de/mirkos_hp/pub/
EXTRACT_SUFX=	.py

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game to challenge short-term memory

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}

do-extract:
	${MKDIR} ${WRKDIR}

do-build:
	${SED} -e "s:/usr/bin:${PREFIX}/bin:" < ${_DISTDIR}/${DISTFILES} \
		> ${WRKDIR}/senso
	${ECHO_CMD} "bin/senso" > ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/senso ${PREFIX}/bin/

.include <bsd.port.mk>
