# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cartopy
PORTVERSION=	0.19.0
DISTVERSIONSUFFIX=	.post1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cartopy-${DISTVERSIONFULL}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cartographic library with Matplotlib support for visualisation

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	geos>=3.3.3:graphics/geos \
		proj>=4.9.0,1:graphics/proj \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.13.3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	libgeos.so:graphics/geos \
		libproj.so:graphics/proj
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.13.3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyshp>=2:devel/py-pyshp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>=1.5.6:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.3.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent cython distutils

CPPFLAGS+=	-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H

OPTIONS_DEFINE=	EPSG OWS PLOTTING
EPSG_DESC=	EPSG database support
OWS_DESC=	OGC Web Service support
PLOTTING_DESC=	Plotting support

EPSG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyepsg>=0.4.0:graphics/py-pyepsg@${PY_FLAVOR}
OWS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}OWSLib>=0.8.11:graphics/py-OWSLib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=1.7.8:graphics/py-pillow@${PY_FLAVOR}
PLOTTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdal>=1.10.0:graphics/py-gdal@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.1:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=1.7.8:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scipy>=0.10:science/py-scipy@${PY_FLAVOR}

.include <bsd.port.mk>
