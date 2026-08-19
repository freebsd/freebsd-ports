PORTNAME=	momepy
PORTVERSION=	1.0.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI \
		https://github.com/pysal/momepy/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Urban Morphology Measuring Toolkit
WWW=		https://docs.momepy.org/en/stable/ \
		https://github.com/pysal/momepy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geopandas>=1.1:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.12.1:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=3.4,2:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.3,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=2.1:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.67:misc/py-tqdm@${PY_FLAVOR}

USES=		python:3.12+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PLUS
PLUS_DESC=	Extra features

PLUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}esda>=0:science/py-esda@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}inequality>=0:science/py-inequality@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mapclassify>=0:graphics/py-mapclassify@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}neatnet>=0:graphics/py-neatnet@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numba>=0.60:devel/py-numba@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}osmnx>=0:graphics/py-osmnx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rioxarray>=0:graphics/py-rioxarray@${PY_FLAVOR}

.include <bsd.port.mk>
