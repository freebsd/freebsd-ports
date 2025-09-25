PORTNAME=	cvise
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.0
CATEGORIES=	devel python

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

USES=		cmake compiler llvm:min=16,build,run python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	marxin
USE_PYTHON=	pytest

SHEBANG_FILES=	cvise-delta.py cvise.py

CMAKE_ARGS+=	-DLLVM_DIR:PATH=${LLVM_PREFIX}/lib/cmake/llvm
CMAKE_ARGS+=	-DClang_DIR:PATH=${LLVM_PREFIX}/lib/cmake/clang

.include <bsd.port.mk>
