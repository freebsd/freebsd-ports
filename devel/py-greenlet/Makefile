# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	greenlet
PORTVERSION=	0.4.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Light-weight microthreads for Python

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64 i386
USE_PYTHON=	autoplist concurrent distutils
USES=		python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/greenlet.so

regression-test test: build
	cd ${WRKSRC}/ && ${PYTHON_CMD} run-tests.py

.include <bsd.port.mk>
