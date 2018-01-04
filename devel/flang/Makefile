# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flang
DISTVERSION=	5.0-20171225
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Fortran compiler targeting LLVM

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	llvm50>=0:devel/llvm50 \
		flang-clang>=0:devel/flang-clang
RUN_DEPENDS=	llvm50>=0:devel/llvm50 \
		flang-clang>=0:devel/flang-clang

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON_amd64=	for now only builds and is supported on amd64

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	build unit tests for flang

USE_LDCONFIG=	${PREFIX}/flang/lib
USES=		cmake:outsource,noninja compiler:c++11-lib libedit perl5 tar:xz \
		shebangfix
_USES_PYTHON?=	python:build
USES+=		${_USES_PYTHON}

USE_GITHUB=	yes
GH_ACCOUNT=	flang-compiler
GH_TAGNAME=	64189a1

CMAKE_ARGS+=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config50 \
		-DCMAKE_CXX_COMPILER=${LOCALBASE}flang/bin/clang++ \
		-DCMAKE_C_COMPILER=${LOCALBASE}/flang/bin/clang \
		-DCMAKE_Fortran_COMPILER=${LOCALBASE}/flang/bin/flang \
		-DFLANG_LIBOMP=${LOCALBASE}/llvm50/lib/libomp.so

CMAKE_INSTALL_PREFIX=	${PREFIX}/flang

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MTESTS}
CMAKE_ARGS+=	-DFLANG_INCLUDE_TESTS=ON
.endif

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${CP} -r  ${WRKSRC}/tools/flang2/flang2exe/x86_64-Linux ${WRKSRC}/tools/flang2/flang2exe/x86_64-FreeBSD

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/flang.in > \
		${WRKDIR}/flang
	${INSTALL_SCRIPT} ${WRKDIR}/flang ${STAGEDIR}/${PREFIX}/bin/flang

.include <bsd.port.mk>
