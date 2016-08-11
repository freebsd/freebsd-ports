# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	greenlet
PORTVERSION=	0.4.10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Light-weight microthreads for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DO_MAKE_TEST=	${PYTHON_CMD}
ONLY_FOR_ARCHS=	amd64 i386
TEST_TARGET=	run-tests.py
USE_PYTHON=	autoplist concurrent distutils
USES=		python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/greenlet.so

.include <bsd.port.mk>
