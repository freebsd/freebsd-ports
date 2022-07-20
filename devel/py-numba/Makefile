PORTNAME=	numba
DISTVERSION=	0.51.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Optimizing compiler for Python using LLVM

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>1.11,1:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libtbb.so:devel/tbb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}llvmlite>=0.31.0:devel/py-llvmlite@${PY_FLAVOR}

USES=		compiler:c++11-lang python:3.6+ fortran localbase
USE_PYTHON=	distutils concurrent autoplist

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
