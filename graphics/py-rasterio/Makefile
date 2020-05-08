# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rasterio
PORTVERSION=	1.1.4
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and direct raster I/O for use with Numpy and SciPy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	gdal>=1.11:graphics/gdal \
		${PYNUMPY}
RUN_DEPENDS=	gdal>=1.11:graphics/gdal \
		${PYTHON_PKGNAMEPREFIX}affine>=0:math/py-affine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=4.0<8:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-plugins>=0:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cligj>=0.5:devel/py-cligj@${PY_FLAVOR} \
		${PY_ENUM34} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}snuggs>=1.4.1:math/py-snuggs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython distutils

.include <bsd.port.mk>
