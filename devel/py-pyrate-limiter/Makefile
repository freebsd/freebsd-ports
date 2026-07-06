PORTNAME=	pyrate-limiter
PORTVERSION=	4.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyrate_limiter-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Rate-Limiter using Leaky-Bucket Algorithm
WWW=		https://pyratelimiter.readthedocs.io/en/latest/ \
		https://github.com/vutran1710/PyrateLimiter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL
ALL_DESC=	All optional dependencies

ALL_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}filelock>=3.0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.2.9:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=6.2.0:databases/py-redis@${PY_FLAVOR}

.include <bsd.port.mk>
