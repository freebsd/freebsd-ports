PORTNAME=	cartopy
PORTVERSION=	0.20.3
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cartopy-${DISTVERSIONFULL}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cartographic library with Matplotlib support for visualisation

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	geos>=3.7.2:graphics/geos \
		proj>=8.0.0,1:graphics/proj \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.18,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	libgeos.so:graphics/geos \
		libproj.so:graphics/proj
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.18,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=3.0.0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyshp>=2.1:devel/py-pyshp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>=1.6.4:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.3.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent cython distutils

OPTIONS_DEFINE=	OWS PLOTTING
OWS_DESC=	OGC Web Service support
PLOTTING_DESC=	Plotting support

OWS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}OWSLib>=0.18.0:graphics/py-OWSLib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=6.1.0:graphics/py-pillow@${PY_FLAVOR}
PLOTTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdal>=2.3.2:graphics/py-gdal@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=6.1.0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scipy>=1.3.1:science/py-scipy@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
