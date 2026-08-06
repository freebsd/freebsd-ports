PORTNAME=	murmurhash
DISTVERSION=	1.0.15
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython bindings for MurmurHash2
WWW=		https://github.com/explosion/murmurhash

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=3.0:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/murmurhash/tests
TEST_ARGS=	-p no:black -p no:mypy -p no:cov

pre-test: # tests fail to run with __init__.py: they can't find the murmurhash module
	@${RM} ${TEST_WRKSRC}/__init__.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/murmurhash/mrmr*.so

# tests as of 1.0.15: 2 passed in 8.13s

.include <bsd.port.mk>
