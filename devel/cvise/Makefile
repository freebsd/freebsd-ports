PORTNAME=	cvise
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python

MAINTAINER=	swills@FreeBSD.org
COMMENT=	C-Vise is a super-parallel Python port of the C-Reduce

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pebble>0:devel/py-pebble@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}pebble>0:devel/py-pebble@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flake8>=0:devel/py-pytest-flake8@${PY_FLAVOR}
#		gcc:lang/gcc
# gcc required for tests to pass. framework errors:
# Error: lang/gcc should not be depended upon. Instead, use USE_GCC.
# but doesn't support gcc as a test only depends
# once this is installed, all tests pass for me:
# 260 passed, 1 skipped in 64.82 seconds

USES=		cmake python:3.6+ shebangfix
CMAKE_ARGS+=	-DClang_DIR:PATH=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/clang
LLVM_VER=	13
SHEBANG_FILES=	cvise-delta.py cvise.py
USE_GITHUB=	yes
GH_ACCOUNT=	marxin

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/cvise.py

do-test:
	cd ${BUILD_WRKSRC} && pytest

.include <bsd.port.mk>
