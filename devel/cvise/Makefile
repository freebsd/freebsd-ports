PORTNAME=	cvise
PORTVERSION=	2.7.0
DISTVERSIONPREFIX=	v
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
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flake8>=0:devel/py-pytest-flake8@${PY_FLAVOR}
#		gcc:lang/gcc
# gcc required for tests to pass. framework errors:
# Error: lang/gcc should not be depended upon. Instead, use USE_GCC.
# but doesn't support gcc as a test only depends
# once this is installed, all tests pass for me:
# 260 passed, 1 skipped in 64.82 seconds

USES=		cmake compiler llvm:min=15,build,run python:3.6+ shebangfix
CMAKE_ARGS+=	-DLLVM_DIR:PATH=${LLVM_PREFIX}/lib/cmake/llvm
CMAKE_ARGS+=	-DClang_DIR:PATH=${LLVM_PREFIX}/lib/cmake/clang
SHEBANG_FILES=	cvise-delta.py cvise.py
USE_GITHUB=	yes
GH_ACCOUNT=	marxin

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ff4e51e093a53615362f77c956d90f0f728c12e5.patch:-p1
PATCHFILES+=	80476310943053aa97969d6410743bddb2d1c770.patch:-p1
PATCHFILES+=	c560ef24eae3946573317d20759938209fb882fa.patch:-p1
PATCHFILES+=	222313aa5467d22ba58d3fdc3198abdf75a07f0e.patch:-p1

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "clang" && ${COMPILER_VERSION} < 150
CPP=		clang-cpp${LLVM_VERSION}
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/cvise.py

do-test:
	cd ${BUILD_WRKSRC} && pytest

.include <bsd.port.post.mk>
