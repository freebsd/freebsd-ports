# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	2.2.0
CATEGORIES=	graphics python
MASTER_SITES=	http://download.osgeo.org/gdal/${PORTVERSION}/ \
		ftp://ftp.remotesensing.org/pub/gdal/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for GDAL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE.TXT

LIB_DEPENDS=	libgdal.so:graphics/gdal

OPTIONS_DEFINE=	NUMPY
NUMPY_DESC=	Enable array support via NumPy

USE_PYTHON=	autoplist concurrent distutils
USES=		python shebangfix tar:xz

WRKSRC_SUBDIR=	swig/python

SHEBANG_FILES=	scripts/*.py

NUMPY_BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy
NUMPY_RUN_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.0.0,1:math/py-numpy
NUMPY_USES=		fortran

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.py ${STAGEDIR}${PREFIX}/bin/
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/osgeo/*.so

.include <bsd.port.mk>
