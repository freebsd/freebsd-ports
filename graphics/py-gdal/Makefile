# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	1.10.1
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

PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME:U}
USE_PYTHON=	-2.7
USE_PYDISTUTILS=easy_install
WRKSRC=		${WRKDIR}/${DISTNAME}/swig/python

NUMPY_BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.0.0:${PORTSDIR}/math/py-numpy
NUMPY_RUN_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.0.0:${PORTSDIR}/math/py-numpy

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.py ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
