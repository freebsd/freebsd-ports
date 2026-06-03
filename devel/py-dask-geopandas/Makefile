PORTNAME=	dask-geopandas
PORTVERSION=	0.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dask_geopandas-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parallel GeoPandas with Dask
WWW=		https://dask-geopandas.readthedocs.io/en/stable/ \
		https://github.com/geopandas/dask-geopandas

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dask>=2025.1.0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geopandas>=0.14.3:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=2.0:devel/py-shapely@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
