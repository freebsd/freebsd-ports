# New ports collection makefile for:	py-gdal
# Date created:		2012-03-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdal
PORTVERSION=	1.9.1
CATEGORIES=	graphics python
MASTER_SITES=	http://download.osgeo.org/gdal/ \
		ftp://ftp.remotesensing.org/pub/gdal/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for GDAL

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal

OPTIONS=	NUMPY	"Enable array support via NumPy" off

PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME:U}
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
WRKSRC=		${WRKDIR}/${DISTNAME}/swig/python

.include <bsd.port.options.mk>

.if defined(WITH_NUMPY)
BUILD_DEPENDS+=	${PKGNAMEPREFIX}numpy>=1.0.0:${PORTSDIR}/math/py-numpy
RUN_DEPENDS+=	${PKGNAMEPREFIX}numpy>=1.0.0:${PORTSDIR}/math/py-numpy
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.py ${PREFIX}/bin/

.include <bsd.port.mk>
