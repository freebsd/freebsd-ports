# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cartopy
PORTVERSION=	0.17.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cartopy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cartographic library with Matplotlib support for visualisation

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	geos>=3.3.3:graphics/geos \
		proj>=4.9.0:graphics/proj \
		${PYNUMPY}
LIB_DEPENDS=	libgeos.so:graphics/geos \
		libproj.so:graphics/proj
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyshp>=1.1.4:devel/py-pyshp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>=1.5.6:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.3.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython distutils

.include <bsd.port.mk>
