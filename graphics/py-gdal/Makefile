# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	gdal
PORTVERSION=	3.5.0
CATEGORIES=	graphics python
MASTER_SITES=	https://download.osgeo.org/gdal/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for GDAL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE.TXT

LIB_DEPENDS=	libgdal.so:graphics/gdal

USES=		compiler:c++14-lang cpe python:3.8+ tar:xz
USE_PYTHON=	autoplist concurrent distutils

USE_CXXSTD=	c++14
WRKSRC_SUBDIR=	swig/python

CPE_VENDOR=	osgeo

OPTIONS_DEFINE=	NUMPY
NUMPY_DESC=	Enable array support via NumPy

NUMPY_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy@${PY_FLAVOR}
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy@${PY_FLAVOR}
NUMPY_USES=		fortran

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
