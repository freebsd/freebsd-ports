PORTNAME=	llvmlite
DISTVERSION=	0.41.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Lightweight LLVM python binding for writing JIT compilers
WWW=		https://github.com/numba/llvmlite

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
RUN_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

USES=		compiler:c++11-lib python fortran
USE_PYTHON=	distutils autoplist pytest # many tests fail, see https://github.com/numba/llvmlite/issues/1015

CXXFLAGS=	-fPIC

MAKE_ENV=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VER}

LLVM_VER=	14 # see the compatibility table https://github.com/numba/llvmlite#compatibility

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/llvmlite/binding/libllvmlite*.so

.include <bsd.port.mk>
