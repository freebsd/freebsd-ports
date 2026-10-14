PORTNAME=	pysimdjson
PORTVERSION=	6.0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python bindings for the simdjson project
WWW=		https://pysimdjson.tkte.ch/

LICENSE=	MIT

#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}	\
#		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	TkTech
USE_PYTHON=	concurrent cython distutils

# The PyPI sdist ships csimdjson.cpp from Cython 3.0.2, which fails with
# Python 3.13, but not csimdjson.pyx.  Use the GitHub tag and rebuild it.
MAKE_ENV+=	BUILD_WITH_CYTHON=1 \
		FORCE_REBUILD=1

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
