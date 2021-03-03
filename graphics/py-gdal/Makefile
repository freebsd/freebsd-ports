# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	https://download.osgeo.org/gdal/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for GDAL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE.TXT

LIB_DEPENDS=	libgdal.so:graphics/gdal

USES=		compiler:c++14-lang python:3.6+ shebangfix tar:xz
USE_PYTHON=	autoplist concurrent distutils

USE_CXXSTD=	c++14
WRKSRC_SUBDIR=	swig/python

SHEBANG_FILES=	scripts/*.py

OPTIONS_DEFINE=	NUMPY
NUMPY_DESC=	Enable array support via NumPy

NUMPY_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy@${PY_FLAVOR}
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy@${PY_FLAVOR}
NUMPY_USES=		fortran

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/osgeo/*.so

.include <bsd.port.mk>
