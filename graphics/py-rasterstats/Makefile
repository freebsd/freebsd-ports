PORTNAME=	rasterstats
PORTVERSION=	0.21.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Summarize geospatial raster datasets based on vector geometries
WWW=		https://github.com/perrygeo/python-rasterstats

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}affine>=0:math/py-affine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cligj>=0.4:devel/py-cligj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.9,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyogrio>=0:graphics/py-pyogrio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rasterio>=1.0:graphics/py-rasterio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	FIONA PROGRESS
FIONA_DESC=	Fiona as optional engine
PROGRESS_DESC=	Progress bar for interactive use

PROGRESS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR}
FIONA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fiona>=0:graphics/py-fiona@${PY_FLAVOR}

.include <bsd.port.mk>
