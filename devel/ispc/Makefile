# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	ispc
PORTVERSION=	1.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	yuri@rawbw.com
COMMENT=	Intel's compiler for high-performance SIMD programming

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	clang${CLANG_VERSION}:lang/clang${CLANG_VERSION}

USE_GITHUB=	yes

USES=		bison gmake python:build shebangfix
ALL_TARGET=	default
MAKE_ENV=	LLVM_HOME="${LOCALBASE}"
CLANG_VERSION=	38
SHEBANG_FILES=	*.py

MAKE_ARGS=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${CLANG_VERSION} \
		CLANG=clang${CLANG_VERSION} CXX=clang++${CLANG_VERSION}

PLIST_FILES=	bin/ispc

post-patch:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}| ; s|@$$(C|$$(C|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/alloca\.h/d' ${WRKSRC}/util.cpp

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
