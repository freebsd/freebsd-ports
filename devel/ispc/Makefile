# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	ispc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel's compiler for high-performance SIMD programming

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	only available for x86 architectures

LIB_DEPENDS=	libLLVM.so:devel/llvm${LLVM_DEFAULT}

USES=		bison gmake python:build shebangfix
USE_GITHUB=	yes

ALL_TARGET=	default
MAKE_ENV=	LLVM_HOME="${LOCALBASE}"
SHEBANG_FILES=	*.py

MAKE_ARGS=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT} \
		CLANG=clang${LLVM_DEFAULT} CXX=clang++${LLVM_DEFAULT}

PLIST_FILES=	bin/ispc

post-patch:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}| ; s|@$$(C|$$(C|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/alloca\.h/d' ${WRKSRC}/src/util.cpp
	@${REINPLACE_CMD} -e '/^LLVM_LIBS=/s|$$| -lexecinfo|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ispc ${STAGEDIR}${PREFIX}/bin

do-test:
	@cd ${WRKSRC} && ISPC_HOME=${WRKSRC} ./run_tests.py

run-examples:
	@[ -f ${LOCALBASE}/lib/libtbb.so ] || ! echo "ERROR run-examples target requires devel/tbb package installed"
.for e in simple sort mandelbrot stencil
	@cd ${WRKSRC}/examples/${e} && \
	${ECHO} "===> Running example ${e}" && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && \
	./${e}
.endfor

.include <bsd.port.mk>
