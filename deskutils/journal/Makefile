# New ports collection makefile for:	Jose Devezas
# Date created:				3 November 2003
# Whom:					Jose Devezas <jose.devezas@fe.up.pt>
#
# $FreeBSD$
#

PORTNAME=	journal
PORTVERSION=	0.4
CATEGORIES=	deskutils
MASTER_SITES=	http://soapbox.fissure.org/journal/

MAINTAINER=	jose.devezas@fe.up.pt
COMMENT=	Journal is a tool for replacing the traditional text-based diary

NO_BUILD=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes

do-patch:
	${REINPLACE_CMD} -e "s,#!/usr/bin/python,#!${PYTHON_CMD}," ${WRKSRC}/journal.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/journal.py ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/journ_classes.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
