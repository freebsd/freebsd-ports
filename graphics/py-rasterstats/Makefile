PORTNAME=	rasterstats
PORTVERSION=	0.17.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Summarize geospatial raster datasets based on vector geometries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}affine>=0<3.0:math/py-affine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cligj>=0.4:devel/py-cligj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Fiona>=0:graphics/py-fiona@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.9,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rasterio>=1.0:graphics/py-rasterio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>=0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
