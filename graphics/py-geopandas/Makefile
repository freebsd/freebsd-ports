PORTNAME=	geopandas
PORTVERSION=	1.1.3
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Python tools for geographic data
WWW=		https://geopandas.org/ \
		https://github.com/geopandas/geopandas

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy1>=1.24:math/py-numpy1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.0.0,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyogrio>=0.7.2:graphics/py-pyogrio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=3.5.0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=2.0.0:devel/py-shapely@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython pep517

NO_ARCH=	yes

.include <bsd.port.mk>
