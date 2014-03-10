# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pyfits
PORTVERSION=	3.1.2
PORTREVISION=	2
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tonymaher@optusnet.com.au
COMMENT=	Python Interface to FITS Formatted Files

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}d2to1>=0:${PORTSDIR}/devel/py-d2to1 \
		${PYTHON_PKGNAMEPREFIX}stsci.distutils>=0:${PORTSDIR}/devel/py-stsci.distutils
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}d2to1>=0:${PORTSDIR}/devel/py-d2to1

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
