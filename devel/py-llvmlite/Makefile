PORTNAME=	llvmlite
DISTVERSION=	0.42.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Lightweight LLVM python binding for writing JIT compilers
WWW=		https://github.com/numba/llvmlite

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# llvm compatibility table https://github.com/numba/llvmlite#compatibility
USES=		compiler:c++11-lib fortran llvm:14,build,run python
USE_PYTHON=	distutils autoplist pytest # many tests fail, see https://github.com/numba/llvmlite/issues/1015

CXXFLAGS=	-fPIC

MAKE_ENV=	LLVM_CONFIG=${LLVM_CONFIG}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/llvmlite/binding/libllvmlite*.so

.include <bsd.port.mk>
