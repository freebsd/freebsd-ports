# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	gevent
PORTVERSION=	20.6.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python co-routine networking library based on greenlet

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	c-ares>=1.15.0:dns/c-ares \
		libev>=4.31:devel/libev \
		libuv>=1.34.0:devel/libuv \
		${RUN_DEPENDS}
LIB_DEPENDS=	libcares.so:dns/c-ares \
		libev.so:devel/libev \
		libuv.so:devel/libuv
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}greenlet>=0.4.16:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent distutils

DO_MAKE_TEST=	${SETENV} PYTHONPATH=../ ${PYTHON_CMD}
MAKE_ENV=	GEVENTSETUP_EMBED_CARES=0 GEVENTSETUP_EMBED_LIBEV=0 GEVENTSETUP_EMBED_LIBUV=0
TEST_TARGET=	testrunner.py
TEST_WRKSRC=	${WRKSRC}/greentest

.include <bsd.port.pre.mk>

post-patch:
.if ${PYTHON_REL} >= 3000
	@${RM} ${WRKSRC}/src/gevent/_util_py2.py
.endif
# Clean up bundled libraries
	@${RM} -fr ${WRKSRC}/deps/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
