PORTNAME=	aiomcache
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Minimal asyncio memcached client
WWW=		https://github.com/aio-libs/aiomcache/

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist distutils cython

NO_ARCH=	yes

post-extract:
	@${MV} ${WRKSRC}/tests ${WRKSRC}/aiomcache/

.include <bsd.port.mk>
