# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	2.4.3
CATEGORIES=	graphics python
MASTER_SITES=	https://download.osgeo.org/gdal/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for GDAL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE.TXT

LIB_DEPENDS=	libgdal.so:graphics/gdal

OPTIONS_DEFINE=	NUMPY
NUMPY_DESC=	Enable array support via NumPy

USES=		compiler:c++11-lang python shebangfix tar:xz
USE_PYTHON=	autoplist concurrent distutils

USE_CXXSTD=	c++11
WRKSRC_SUBDIR=	swig/python

SHEBANG_FILES=	scripts/*.py

NUMPY_BUILD_DEPENDS=	${PYNUMPY}
NUMPY_RUN_DEPENDS=	${PYNUMPY}
NUMPY_USES=		fortran

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/osgeo/*.so

.include <bsd.port.mk>
