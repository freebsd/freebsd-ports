# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	ispc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel's compiler for high-performance SIMD programming

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	only available for these architectures

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		m4:devel/m4
LIB_DEPENDS=	libLLVM.so:devel/llvm${LLVM_VERSION}

USES=		bison cmake compiler:c++14-lang python:build,test shebangfix
USE_GITHUB=	yes
SHEBANG_FILES=	*.py

LLVM_VERSION=	-devel # Release notes https://github.com/ispc/ispc/blob/master/docs/ReleaseNotes.txt list compatible LLVM versions, but they assume that extra patches are applied to LLVM
		# LLVM build script: https://github.com/ispc/ispc/blob/master/scripts/build.sh

CONFIGURE_ENV=	PATH=${LOCALBASE}/llvm${LLVM_VERSION}/bin:${PATH}
CMAKE_OFF=	ISPC_NO_DUMPS ISPC_INCLUDE_EXAMPLES

BINARY_ALIAS=	flex=${LOCALBASE}/bin/flex python=${PYTHON_CMD} m4=${LOCALBASE}/bin/gm4

PLIST_FILES=	bin/ispc \
		bin/check_isa

do-test: # some tests fail: https://github.com/ispc/ispc/issues/1868
	@cd ${WRKSRC} && ISPC_HOME=${BUILD_WRKSRC}/bin ./run_tests.py

test-check-all: # the upstream claims that some of these checks are broken without using their patched llvm version, hence using llvm-devel
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check-all

run-examples: build
	@[ -f ${LOCALBASE}/lib/libtbb.so ] || ! echo "ERROR run-examples target requires devel/tbb package installed"
.for e in simple sort mandelbrot stencil
	@cd ${WRKSRC}/examples/${e} && \
	${ECHO} "===> Running example ${e}" && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && \
	./${e}
.endfor

.include <bsd.port.mk>
