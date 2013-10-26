# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pyfits
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	astro python
MASTER_SITES=	http://www.stsci.edu/resources/software_hardware/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tonymaher@optusnet.com.au
COMMENT=	Python Interface to FITS Formatted Files

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:${PORTSDIR}/math/py-numpy
RUN_DEPENDS:=	${BUILD_DEPENDS}
NO_STAGE=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
