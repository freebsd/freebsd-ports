PORTNAME=	cvise
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.0
PORTREVISION=	2
CATEGORIES=	devel python

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	68262f7d6de584b6474801827cb7dfc68011de25.patch:-p1 # Add support for LLVM 21 as of 2025.06.24 (#183)
PATCHFILES+=	42da06fd108c351c5f4a42657c16208300121545.patch:-p1 # clang_delta: Add tests for replace-dependent-typedef (#275)
PATCHFILES+=	59e9058c43b12b802893bde668113c8b3b3525b7.patch:-p1 # clang_delta: Skip non-dep typedefs in replace-dependent-typedef (#276)
PATCHFILES+=	fa1be9523d569adfe207c85a1e44f074172bc305.patch:-p1 # Support for LLVM 22 (#373)
PATCHFILES+=	b17bbacdb279babd87dc9ef24756f3003746717c.patch:-p1 # clang_delta: Support for LLVM 22 20251014 (#430)
PATCHFILES+=	c7f9642340eb61c09a05c96498fd21c9b7293770.patch:-p1 # Support for LLVM 22 updated, as of 2025-10-25 (#439)

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C-Vise is a super-parallel Python port of the C-Reduce
WWW=		https://github.com/marxin/cvise

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pebble>0:devel/py-pebble@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}
RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}pebble>0:devel/py-pebble@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-flake8>=0:devel/py-pytest-flake8@${PY_FLAVOR}
#		gcc:lang/gcc
# gcc required for tests to pass. framework errors:
# Error: lang/gcc should not be depended upon. Instead, use USE_GCC.
# but doesn't support gcc as a test only depends
# once this is installed, all tests pass for me:
# 260 passed, 1 skipped in 64.82 seconds

USES=		cmake compiler llvm:min=16,build,run,clang python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	marxin
USE_PYTHON=	pytest

SHEBANG_FILES=	cvise-delta.py cvise.py

CMAKE_ARGS+=	-DLLVM_DIR:PATH=${LLVM_PREFIX}/lib/cmake/llvm
CMAKE_ARGS+=	-DClang_DIR:PATH=${LLVM_PREFIX}/lib/cmake/clang

.include <bsd.port.mk>
