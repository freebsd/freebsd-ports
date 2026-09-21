PORTNAME=	nanobind
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	942e75d927e3884e56d607e77c026bb4a72a4763.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny and efficient C++/Python bindings
WWW=		https://github.com/wjakob/nanobind

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10:devel/py-scikit-build-core@${PY_FLAVOR}
TEST_DEPENDS=	cmake:devel/cmake-core

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	wjakob
GH_TUPLE=	Tessil:robin-map:188c455:robin_map/ext/robin_map

TEST_WRKSRC=	${BUILD_WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

pre-test: # build test extensions
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} cmake -DPython_EXECUTABLE=${PYTHON_CMD} . && \
		${SETENV} ${MAKE_ENV} ${MAKE} -j${MAKE_JOBS_NUMBER}

.include <bsd.port.mk>
