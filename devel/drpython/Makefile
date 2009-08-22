# New ports collection makefile for:	drpython
# Date created:		2005-07-22
# Whom:			vsevolod
#
# $FreeBSD$
#

PORTNAME=	drpython
PORTVERSION=	3.11.0
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/DrPython%20Current/${PORTVERSION}
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly customizable cross-platform ide to aid programming in Python

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	DrPython
USE_WX=		2.6+
WX_COMPS=	python

post-install:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/drpython.sh
	@${ECHO_CMD} '(cd ${PYTHONPREFIX_SITELIBDIR}/drpython && ${PYTHON_CMD} drpython.py)' >> ${WRKDIR}/drpython.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/drpython.sh ${PREFIX}/bin/drpython

.include <bsd.port.mk>
