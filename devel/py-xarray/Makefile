PORTNAME=	xarray
PORTVERSION=	2025.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	N-D labeled arrays and datasets in Python
WWW=		https://xarray.dev/ \
		https://github.com/pydata/xarray

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2,1:math/py-pandas@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cartopy>=0.23:graphics/py-cartopy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cfgrib>=0:science/py-cfgrib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cftime>=0:devel/py-cftime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>=0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>=1.6.0:science/py-netCDF4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rasterio>=0:graphics/py-rasterio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seaborn>=0:math/py-seaborn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sparse>=0.15:devel/py-sparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zarr>=2.18:devel/py-zarr@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
