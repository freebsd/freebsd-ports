# New ports collection makefile for:	pythonchess
# Date created:				24 November 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	pythonchess
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	http://www.kolumbus.fi/jyrki.alakuijala/
EXTRACT_SUFX=	.tgz

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Small program for playing chess against the computer

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes

do-build:
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} "cd ${DATADIR} && ${PYTHON_CMD} board.py") \
	  > ${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.for f in *.gif *.py *.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

.include <bsd.port.mk>
