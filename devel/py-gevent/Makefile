# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	gevent
PORTVERSION=	1.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python co-routine networking library based on greenlet

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcares.so:dns/c-ares \
		libev.so:devel/libev
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}greenlet>=0.4.14:devel/py-greenlet@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent distutils

DO_MAKE_TEST=	${SETENV} PYTHONPATH=../ ${PYTHON_CMD}
MAKE_ENV=	CARES_EMBED=0 LIBEV_EMBED=0
TEST_TARGET=	testrunner.py
TEST_WRKSRC=	${WRKSRC}/greentest

.include <bsd.port.pre.mk>

post-patch:
.if ${PYTHON_REL} >= 3000
	@${RM} ${WRKSRC}/src/gevent/_util_py2.py
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gevent/*.so ${STAGEDIR}${PYTHON_SITELIBDIR}/gevent/libev/corecext.so

.include <bsd.port.post.mk>
