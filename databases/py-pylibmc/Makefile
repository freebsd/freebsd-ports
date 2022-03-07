# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	pylibmc
PORTVERSION=	1.6.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick and small memcached client for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmemcached.so:databases/libmemcached
TEST_DEPENDS=	memcached:databases/memcached \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

MAKE_ENV+=	LIBMEMCACHED="${LOCALBASE}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_pylibmc*.so

# Note: memcached needs to be running first for this to work

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
