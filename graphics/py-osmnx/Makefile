PORTNAME=	osmnx
PORTVERSION=	2.1.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Download, model, analyze, and visualize street networks and other geospatial features from OpenStreetMap
WWW=		https://osmnx.readthedocs.io/en/stable/ \
		https://github.com/gboeing/osmnx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geopandas>=1.0.1:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.5,2:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.5,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.30:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=2.0:devel/py-shapely@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SOURCE_DATE_EPOCH=315532800 # 1980-01-01 00:00:00 UTC
NO_ARCH=	yes

.include <bsd.port.mk>
