PORTNAME=	numba
DISTVERSION=	0.59.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Optimizing compiler for Python using LLVM
WWW=		https://numba.pydata.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

# numpy version is checked at runtime
# https://github.com/numba/numba/blob/main/numba/__init__.py#L13
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21,1<=1.26,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR}
LIB_DEPENDS=	libtbb.so:devel/onetbb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}llvmlite>=0.31.0:devel/py-llvmlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21,1<=1.26,1:math/py-numpy@${PY_FLAVOR} \

USES=		compiler:c++11-lang python fortran localbase
USE_PYTHON=	distutils concurrent autoplist unittest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/numba/tests

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

do-test: # tests run for a very long time
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m numba.runtests

.include <bsd.port.mk>
