# Created by: David Kalliecharan <dave@dal.ca>
# $FreeBSD$

PORTNAME=	numba
DISTVERSION=	0.40.1
PORTREVISION=	8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Optimizing compiler for Python using LLVM

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>1.7,1:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libomp.so:devel/openmp \
		libtbb.so:devel/tbb
RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}llvmlite>=0.12:devel/py-llvmlite@${PY_FLAVOR}
py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}singledispatch>0:devel/py-singledispatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}funcsigs>0:devel/py-funcsigs@${PY_FLAVOR}

USES=		python fortran localbase
USE_PYTHON=	distutils concurrent autoplist

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
