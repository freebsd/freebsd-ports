# New ports collection makefile for:	py-biopython
# Date created:		28 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	biopython
PORTVERSION=	0.90.d03
CATEGORIES=	biology python
MASTER_SITES=	http://www.biopython.org/Download/
PKGNAMEPREFIX=	py-
DISTNAME=	biopython-0.90-d03

MAINTAINER=	johann@egenetics.com

USE_PYTHON=	yes

BUILD_DEPENDS=	${PYDISTUTILS} \
		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/numpy

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install)

.include <bsd.port.mk>
