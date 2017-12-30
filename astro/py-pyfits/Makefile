# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pyfits
PORTVERSION=	3.4
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Interface to FITS Formatted Files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Use astro/py-astropy instead
EXPIRATION_DATE=2018-01-31

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}d2to1>=0:devel/py-d2to1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stsci.distutils>=0:devel/py-stsci.distutils@${FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}d2to1>=0:devel/py-d2to1@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyfits/compression.so

.include <bsd.port.mk>
