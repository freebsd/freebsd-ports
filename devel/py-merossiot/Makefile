PORTNAME=	merossiot
PORTVERSION=	0.4.9.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MerossIot-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Python library for accessing Meross IoT devices
WWW=		https://github.com/albertogeniola/MerossIot

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paho-mqtt>=2.1.0:net/py-paho-mqtt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.7.4:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>=3.20.0:security/py-pycryptodomex@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	albertogeniola
GH_PROJECT=	MerossIot

USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
