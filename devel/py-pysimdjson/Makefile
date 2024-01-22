PORTNAME=	pysimdjson
PORTVERSION=	5.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python bindings for the simdjson project
WWW=		https://pysimdjson.tkte.ch/

LICENSE=	MIT

USES=		python
USE_PYTHON=	cython distutils

CFLAGS_powerpc64=	-mpower8-vector

.if ! defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
