# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	greenlet
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Light-weight microthreads for Python

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64 i386
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_ZIP=	yes

post-build:
	@${STRIP_CMD} ${WRKSRC}/greenlet.so

regression-test test: build
	cd ${WRKSRC}/ && ${PYTHON_CMD} run-tests.py

.include <bsd.port.mk>
