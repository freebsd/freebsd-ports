PORTNAME=	aioredis
PORTVERSION=	1.3.1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Python asyncio (PEP 3156) Redis client library
WWW=		https://github.com/aio-libs/aioredis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async_timeout>0:devel/py-async_timeout@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=	HIREDIS

HIREDIS_DESC=	High performance response parser (via hiredis)

HIREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>0:databases/py-hiredis@${PY_FLAVOR}

.include <bsd.port.mk>
