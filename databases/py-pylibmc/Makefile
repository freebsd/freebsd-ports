PORTNAME=	pylibmc
PORTVERSION=	1.6.3
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Quick and small memcached client for Python
WWW=		https://sendapatch.se/projects/pylibmc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmemcached.so:databases/libmemcached
TEST_DEPENDS=	memcached:databases/memcached

USES=		python
USE_PYTHON=	autoplist distutils nose

MAKE_ENV+=	LIBMEMCACHED="${LOCALBASE}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_pylibmc*.so

# Note: memcached needs to be running first for this to work
#do-test:

.include <bsd.port.mk>
