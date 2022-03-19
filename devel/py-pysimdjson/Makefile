# Created by: thierry@pompo.net

PORTNAME=	pysimdjson
PORTVERSION=	4.0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python bindings for the simdjson project

LICENSE=	MIT

USES=		python:3.7+
USE_PYTHON=	cython distutils

.if ! defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
