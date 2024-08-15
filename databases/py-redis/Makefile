PORTNAME=	redis
PORTVERSION=	5.0.8
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python client for Redis key-value store
WWW=		https://github.com/redis/redis-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}redis[0-9]

OPTIONS_DEFINE=	HIREDIS
HIREDIS_DESC=	High performance response parser

HIREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>=1.0.0:databases/py-hiredis@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31103
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}async_timeout>=4.0.3:devel/py-async_timeout@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
