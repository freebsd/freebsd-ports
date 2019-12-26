# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	ispc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel's compiler for high-performance SIMD programming

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	only available for x86 architectures

LIB_DEPENDS=	libLLVM.so:devel/llvm${LLVM_DEFAULT}

USES=		bison cmake python:build shebangfix
USE_GITHUB=	yes
SHEBANG_FILES=	*.py

CONFIGURE_ENV=	PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/bin:${PATH}
CMAKE_OFF=	ISPC_INCLUDE_EXAMPLES

BINARY_ALIAS=	python=${PYTHON_CMD}

PLIST_FILES=	bin/ispc \
		bin/check_isa

do-test: # tests are broken with python-3.6
	@cd ${WRKSRC} && ISPC_HOME=${WRKSRC} ./run_tests.py

run-examples:
	@[ -f ${LOCALBASE}/lib/libtbb.so ] || ! echo "ERROR run-examples target requires devel/tbb package installed"
.for e in simple sort mandelbrot stencil
	@cd ${WRKSRC}/examples/${e} && \
	${ECHO} "===> Running example ${e}" && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && \
	./${e}
.endfor

.include <bsd.port.options.mk>

.if ${LLVM_DEFAULT:S,-devel,990,} >= 90
LLVM_DEFAULT=	80
.endif

.include <bsd.port.mk>
