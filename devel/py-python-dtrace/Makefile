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

USES=		python zip
USE_PYTHON=	autoplist distutils cython cython_run

.if !exists(${SRC_BASE}/sys/cddl/contrib/opensolaris/uts/common/dtrace.h)
IGNORE=		you must have "device dtrace" included in your kernel to build this package
.endif

.include <bsd.port.mk>
