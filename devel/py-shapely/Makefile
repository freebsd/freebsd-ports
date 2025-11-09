PORTNAME=	shapely
PORTVERSION=	2.1.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/shapely/shapely/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Package for Manipulation 2D Geospatial Geometry
WWW=		https://shapely.readthedocs.io/en/stable/ \
		https://github.com/shapely/shapely

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.25,1<3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libgeos_c.so:graphics/geos
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21,1:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
