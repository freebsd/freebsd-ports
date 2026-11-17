PORTNAME=	pylibmc
DISTVERSION=	1.7.1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Quick and small memcached client for Python
WWW=		https://sendapatch.se/projects/pylibmc

LICENSE=	BSD-3-Clause-Clear
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libmemcached.so:databases/libmemcached
TEST_DEPENDS=	memcached:databases/memcached

USES=		python
USE_PYTHON=	autoplist nose pep517

MAKE_ENV+=	LIBMEMCACHED="${LOCALBASE}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_pylibmc*.so

# Note: memcached needs to be running first for this to work
#do-test:

.include <bsd.port.mk>
