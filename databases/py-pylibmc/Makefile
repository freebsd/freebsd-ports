# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	pylibmc
PORTVERSION=	1.5.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Quick and small memcached client for Python

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libmemcached.so:databases/libmemcached
TEST_DEPENDS=	memcached:databases/memcached \
		nosetests:devel/py-nose

USES=		python
USE_PYTHON=	autoplist distutils

MAKE_ENV+=	LIBMEMCACHED="${LOCALBASE}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_pylibmc.so

# Note: memcached needs to be running first for this to work

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
