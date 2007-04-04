# New ports collection makefile for:	py-pp
# Date created:		Feb. 28, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	pp
PORTVERSION=	1.4
CATEGORIES=	devel python
MASTER_SITES=	http://www.parallelpython.com/downloads/pp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Parallel python execution server

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	${REINPLACE_CMD} -e 's,^#!/usr/bin/python,#!${PYTHON_CMD},' ${WRKSRC}/ppserver.py

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ppserver.py ${TARGETDIR}/bin/

.include <bsd.port.mk>
