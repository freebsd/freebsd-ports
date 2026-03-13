PORTNAME=	llvmlite
DISTVERSION=	0.46.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Lightweight LLVM python binding for writing JIT compilers
WWW=		https://github.com/numba/llvmlite

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

# llvm compatibility table https://github.com/numba/llvmlite#compatibility
USES=		cmake:indirect fortran llvm:20,lib python
USE_PYTHON=	autoplist pep517 pytest # many tests fail, see https://github.com/numba/llvmlite/issues/1015

MAKE_ENV=	LLVM_CONFIG=${LLVM_CONFIG} \
		LLVMLITE_SHARED=ON \
		CMAKE_ARGS=-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-patch:
# Use required LLVM if multiple variants are present.
	${REINPLACE_CMD} "s,%%LLVM_PREFIX%%,${LLVM_PREFIX}," ${WRKSRC}/ffi/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/llvmlite/binding/libllvmlite*.so

.include <bsd.port.mk>
