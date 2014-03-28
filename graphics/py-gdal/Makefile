# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	1.10.1
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	http://download.osgeo.org/gdal/ \
		ftp://ftp.remotesensing.org/pub/gdal/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for GDAL

LICENSE=	MIT

LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal

OPTIONS_DEFINE=	NUMPY
NUMPY_DESC=	Enable array support via NumPy

PYDISTUTILS_AUTOPLIST=	yes
USE_PYDISTUTILS=yes
USE_PYTHON=	yes
USES=		shebangfix

WRKSRC=		${WRKDIR}/${DISTNAME}/swig/python

SHEBANG_FILES=	scripts/*.py
python_OLD_CMD=	${SETENV} python
python_CMD=	${PYTHON_CMD}

NUMPY_BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.0.0:${PORTSDIR}/math/py-numpy
NUMPY_RUN_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.0.0:${PORTSDIR}/math/py-numpy

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.py ${STAGEDIR}${PREFIX}/bin/
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/osgeo/*.so

.include <bsd.port.mk>
