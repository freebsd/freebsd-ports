PORTNAME=	rioxarray
PORTVERSION=	0.22.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geospatial xarray extension powered by rasterio
WWW=		https://corteva.github.io/rioxarray/stable/ \
		https://github.com/corteva/rioxarray

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=3.3:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rasterio>=1.4.3:graphics/py-rasterio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray>=2026.2:devel/py-xarray@${PY_FLAVOR}

USES=		python:3.12+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
