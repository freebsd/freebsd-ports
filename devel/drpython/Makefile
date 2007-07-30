# New ports collection makefile for:	drpython
# Date created:		2005-07-22
# Whom:			vsevolod
#
# $FreeBSD$
#

PORTNAME=	drpython
PORTVERSION=	3.10.13
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly customizable cross-platform ide to aid programming in Python

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	DrPython
USE_WX=		2.6
WX_COMPS=	python

post-install:
	@${ECHO} '#!/bin/sh' > ${WRKDIR}/drpython.sh
	@${ECHO} '(cd ${PYTHONPREFIX_SITELIBDIR}/drpython && ${PYTHON_CMD} drpython.py)' >> ${WRKDIR}/drpython.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/drpython.sh ${PREFIX}/bin/drpython

.include <bsd.port.mk>
