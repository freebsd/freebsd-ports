# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	gevent
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python co-routine networking library based on greenlet/libevent

LICENSE=	MIT

LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}greenlet>=0:${PORTSDIR}/devel/py-greenlet
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}greenlet>=0:${PORTSDIR}/devel/py-greenlet \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	2
USE_PYDISTUTILS=yes

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|' ${WRKSRC}/${PYSETUP}

post-build:
	@${STRIP_CMD} ${WRKSRC}/gevent/_semaphore.so ${WRKSRC}/gevent/_util.so ${WRKSRC}/gevent/ares.so ${WRKSRC}/gevent/core.so

regression-test test: build
	cd ${WRKSRC}/greentest/ && ${SETENV} PYTHONPATH=../ ${PYTHON_CMD} testrunner.py

.include <bsd.port.mk>
