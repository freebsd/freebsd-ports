PORTNAME=	dogpile.cache
PORTVERSION=	1.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dogpile_cache-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Caching front-end based on the Dogpile lock
WWW=		https://dogpilecache.sqlalchemy.org/en/latest/ \
		https://github.com/sqlalchemy/dogpile.cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=4.0.0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdbm>=0:databases/py-gdbm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=3.0.0:devel/py-stevedore@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	BMEMCACHED MEMCACHED PYMEMCACHE REDIS VALKEY
BMEMCACHED_DESC=Memcached support via python-binary-memcached
MEMCACHED_DESC=	Memcached support via python-memcached
PYMEMCACHE_DESC=Memcached support via pymemcache
VALKEY_DESC=	Valkey key-value store database support

BMEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-binary-memcached>=0:databases/py-python-binary-memcached@${PY_FLAVOR}
MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=0:databases/py-python-memcached@${PY_FLAVOR}
PYMEMCACHE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymemcache>=0:databases/py-pymemcache@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis@${PY_FLAVOR}
VALKEY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}valkey>=0:databases/py-valkey@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.1:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
