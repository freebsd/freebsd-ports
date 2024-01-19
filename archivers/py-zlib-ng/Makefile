PORTNAME=	zlib-ng
DISTVERSION=	0.4.0
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	osidorkin@gmail.com
COMMENT=	Python bindings for the zlib-ng library
WWW=		https://github.com/pycompression/python-zlib-ng

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=51:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake-core

USES=		python:3.7+
USE_PYTHON=	autoplist pep517

INSTALL_TARGET=install-strip

.include <bsd.port.mk>
