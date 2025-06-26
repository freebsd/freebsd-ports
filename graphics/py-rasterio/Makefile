PORTNAME=	rasterio
PORTVERSION=	1.3.11
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and direct raster I/O for use with Numpy and SciPy
WWW=		https://rasterio.readthedocs.io/en/stable/ \
		https://github.com/rasterio/rasterio

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	gdal>=3.1:graphics/gdal \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libgdal.so:graphics/gdal
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}affine>=0:math/py-affine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=4.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-plugins>=0:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cligj>=0.5:devel/py-cligj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snuggs>=1.4.1:math/py-snuggs@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist concurrent cython3 pep517

OPTIONS_DEFINE=	PLOT S3
PLOT_DESC=	Plotting support
S3_DESC=	Amazon S3 support

PLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto3>=1.2.4:www/py-boto3@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
