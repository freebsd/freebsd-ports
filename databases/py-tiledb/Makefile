# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiledb
PORTVERSION=	0.5.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the TileDB array storage manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.5.4:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30:devel/py-wheel@${PY_FLAVOR} \
		${RUN_DEPENDS}
LIB_DEPENDS=	libtiledb.so:databases/tiledb
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang localbase python:3.5+
USE_PYTHON=	autoplist cython distutils

.include <bsd.port.mk>
