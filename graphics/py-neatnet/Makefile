PORTNAME=	neatnet
PORTVERSION=	0.1.6
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Street geometry processing toolkit
WWW=		https://uscuni.org/neatnet/ \
		https://github.com/uscuni/neatnet

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}esda>=2.6.0:science/py-esda@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geopandas>=1.0.1:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.12.1:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}momepy>=0.9.0:graphics/py-momepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=3.3,2:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.3,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.2.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.14.1,1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=2.0.6:devel/py-shapely@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
