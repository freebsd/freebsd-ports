PORTNAME=	gdal
PORTVERSION=	3.11.3
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for GDAL
WWW=		https://gdal.org/ \
		https://github.com/OSGeo/gdal

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libgdal.so:graphics/gdal

USES=		compiler:c++11-lang cpe python
USE_PYTHON=	autoplist concurrent pep517

CPE_VENDOR=	osgeo

OPTIONS_DEFINE=	NUMPY
OPTIONS_DEFAULT=NUMPY
NUMPY_DESC=	Enable array support via NumPy

NUMPY_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy@${PY_FLAVOR}
NUMPY_MAKE_ENV=		GDAL_PYTHON_BINDINGS_WITHOUT_NUMPY=no
NUMPY_MAKE_ENV_OFF=	GDAL_PYTHON_BINDINGS_WITHOUT_NUMPY=yes
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy@${PY_FLAVOR}
NUMPY_USES=		fortran

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
