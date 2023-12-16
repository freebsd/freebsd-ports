PORTNAME=	gdal
PORTVERSION=	3.8.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	GDAL-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for GDAL
WWW=		https://gdal.org/ \
		https://github.com/OSGeo/gdal

LICENSE=	MIT

LIB_DEPENDS=	libgdal.so:graphics/gdal

USES=		compiler:c++11-lang cpe python
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	osgeo

OPTIONS_DEFINE=	NUMPY
NUMPY_DESC=	Enable array support via NumPy

NUMPY_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy@${PY_FLAVOR}
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy@${PY_FLAVOR}
NUMPY_USES=		fortran

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
