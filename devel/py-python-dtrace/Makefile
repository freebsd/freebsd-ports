# $FreeBSD$

PORTNAME=	python-dtrace
PORTVERSION=	0.0.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gcj21@cl.cam.ac.uk
COMMENT=	DTrace consumer for Python based on libdtrace

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: dtrace_cython/consumer.c:476:20: dtrace.h: No such file or directory

USES=		python zip
USE_PYTHON=	autoplist distutils cython cython_run

.include <bsd.port.mk>
