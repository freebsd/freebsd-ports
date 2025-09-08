PORTNAME=	redis
PORTVERSION=	6.4.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python client for Redis key-value store
WWW=		https://redis.readthedocs.io/en/latest/ \
		https://github.com/redis/redis-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}redis[0-9]

OPTIONS_DEFINE=	HIREDIS JWT OCSP
HIREDIS_DESC=	High performance response parser
JWT_DESC=	Authentication token
OCSP_DESC=	Online Certificate Status Protocol support

HIREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>=3.2.0:databases/py-hiredis@${PY_FLAVOR}
JWT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyjwt>=2.9.0:www/py-pyjwt@${PY_FLAVOR}
OCSP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=20.0.1,1:security/py-openssl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR}
OCSP_USE=		PYTHON=cryptography

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31103
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}async_timeout>=4.0.3:devel/py-async_timeout@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
