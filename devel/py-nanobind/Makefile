PORTNAME=	nanobind
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny and efficient C++/Python bindings
WWW=		https://github.com/wjakob/nanobind

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		cmake:insource,testing python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	wjakob
GH_TUPLE=	Tessil:robin-map:188c455:robin_map/ext/robin_map

CMAKE_OFF=	NB_TEST
CMAKE_TESTING_ON=	NB_TEST
CMAKE_TESTING_TARGET=

NO_ARCH=	yes

post-test: # run-tests
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest .

.include <bsd.port.mk>
