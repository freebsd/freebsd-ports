PORTNAME=	pysimdjson
PORTVERSION=	6.0.2
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python bindings for the simdjson project
WWW=		https://pysimdjson.tkte.ch/

LICENSE=	MIT

#TEST_DEPENDS=	${PYNUMPY}	\
#		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		python
USE_PYTHON=	cython3 distutils

CFLAGS_powerpc64=	-mpower8-vector

.if ! defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
