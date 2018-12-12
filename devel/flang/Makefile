# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flang
DISTVERSION=	6.0-g20180904
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Fortran compiler targeting LLVM

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	llvm60>=0:devel/llvm60 \
		flang-clang>=0:devel/flang-clang
RUN_DEPENDS=	llvm60>=0:devel/llvm60 \
		flang-clang>=0:devel/flang-clang
LIB_DEPENDS=	libpgmath.so:math/libpgmath

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	build unit tests for flang

USES=		cmake:outsource,noninja compiler:c++11-lib libedit perl5 tar:xz \
		shebangfix
_USES_PYTHON?=	python:build
USES+=		${_USES_PYTHON}
USE_LDCONFIG=	${PREFIX}/flang/lib

USE_GITHUB=	yes
GH_ACCOUNT=	flang-compiler
GH_TAGNAME=	53e368b

CMAKE_ARGS+=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config60 \
		-DCMAKE_CXX_COMPILER=${LOCALBASE}flang/bin/clang++ \
		-DCMAKE_C_COMPILER=${LOCALBASE}/flang/bin/clang \
		-DCMAKE_Fortran_COMPILER=${LOCALBASE}/flang/bin/flang \
		-DFLANG_LIBOMP=${LOCALBASE}/llvm60/lib/libomp.so \
		-DLIBPGMATH="${LOCALBASE}/lib/libpgmath.a" \
		-WWITH_ERROR=OFF

CMAKE_INSTALL_PREFIX=	${PREFIX}/flang

.include <bsd.port.options.mk>
TESTS_CMAKE_ON=	FLANG_INCLUDE_TESTS

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${CP} -r  ${WRKSRC}/tools/flang2/flang2exe/x86_64-Linux ${WRKSRC}/tools/flang2/flang2exe/x86_64-FreeBSD

.include <bsd.port.mk>
