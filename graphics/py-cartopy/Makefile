PORTNAME=	cartopy
PORTVERSION=	0.23.0
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cartopy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cartographic library with Matplotlib support for visualisation
WWW=		https://github.com/SciTools/cartopy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=40.6.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7.0.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.4:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=3.1.0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyshp>=2.1:devel/py-pyshp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=1.7:devel/py-shapely@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

OPTIONS_DEFINE=	OWS PLOTTING SPEEDUPS
OWS_DESC=	OGC Web Service support
PLOTTING_DESC=	Plotting support
SPEEDUPS_DESC=	Speed up

OWS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}OWSLib>=0.20.0:graphics/py-OWSLib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=6.1.0:graphics/py-pillow@${PY_FLAVOR}
PLOTTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=6.1.0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scipy>=1.3.1:science/py-scipy@${PY_FLAVOR}
SPEEDUPS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fiona>=0:graphics/py-fiona@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pykdtree>=0:devel/py-pykdtree@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
