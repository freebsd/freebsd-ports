PORTNAME=	nanobind
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny and efficient C++/Python bindings
WWW=		https://github.com/wjakob/nanobind

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake-core
TEST_DEPENDS=	cmake:devel/cmake-core

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	wjakob
GH_TUPLE=	Tessil:robin-map:188c455:robin_map/ext/robin_map

TEST_WRKSRC=	${WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

pre-test: # build test extensions
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} cmake . && \
		${SETENV} ${MAKE_ENV} ${MAKE} -j${MAKE_JOBS_NUMBER}

.include <bsd.port.mk>
