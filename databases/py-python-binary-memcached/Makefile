PORTNAME=	python-binary-memcached
PORTVERSION=	0.33.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_binary_memcached-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure python module to access memcached via its binary protocol
WWW=		https://python-binary-memcached.readthedocs.io/en/latest/ \
		https://github.com/jaysonsantos/python-binary-memcached

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uhashring>=0:security/py-uhashring@${PY_FLAVOR}
TEST_DEPENDS=	memcached:databases/memcached \
		${PYTHON_PKGNAMEPREFIX}trustme>=0:security/py-trustme@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
TEST_ENV=	MEMCACHED_HOST=localhost

.include <bsd.port.mk>
