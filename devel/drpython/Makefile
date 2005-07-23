# New ports collection makefile for:	drpython
# Date created:		2005-07-22
# Whom:			vsevolod
#
# $FreeBSD$
#

PORTNAME=	drpython
PORTVERSION=	3.10.13
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Highly customizable cross-platform ide to aid programming in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wx-2.6-gtk2-ansi/wx/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython26

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${ECHO} '#!/bin/sh' > ${WRKDIR}/drpython.sh
	@${ECHO} '(cd ${PYTHONPREFIX_SITELIBDIR}/drpython && ${PYTHON_CMD} drpython.py)' >> ${WRKDIR}/drpython.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/drpython.sh ${PREFIX}/bin/drpython

.include <bsd.port.mk>
