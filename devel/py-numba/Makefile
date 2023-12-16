PORTNAME=	numba
DISTVERSION=	0.56.2
PORTREVISION=	6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Optimizing compiler for Python using LLVM
WWW=		https://numba.pydata.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>1.11,1:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libtbb.so:devel/onetbb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}llvmlite>=0.31.0:devel/py-llvmlite@${PY_FLAVOR}

USES=		compiler:c++11-lang python fortran localbase
USE_PYTHON=	distutils concurrent autoplist unittest

MAKE_ENV=	NUMBA_DISABLE_TBB=1 # workaround for: not compatible with onetbb-2021.6.0, see https://github.com/numba/numba/issues/8487
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/numba/tests

post-patch:
	@${SED} -i.bak 's#1\.24#1\.26#g' ${WRKSRC}/setup.py

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

do-test: # tests run for a very long time
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m numba.runtests

.include <bsd.port.mk>
