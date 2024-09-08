PORTNAME=	yosys
DISTVERSION=	0.45
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Yosys Open SYnthesis Suite
WWW=		https://yosyshq.net/yosys/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	abc:cad/abc \
		bash:shells/bash \
		gawk:lang/gawk
LIB_DEPENDS=	libffi.so:devel/libffi
RUN_DEPENDS=	xdot:x11/py-xdot@${PY_FLAVOR} \
		bash:shells/bash

TEST_DEPENDS=	iverilog:cad/iverilog

USES=		bison compiler:c++11-lang gmake pkgconfig python readline \
		shebangfix tcl

SHEBANG_FILES=	backends/smt2/smtbmc.py \
		misc/yosys-config.in
SHEBANG_GLOB=	*.sh *.py

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}
MAKE_ARGS=	ABCEXTERNAL=abc
MAKE_ENV=	MAKE=${GMAKE}

TEST_TARGET=	test # some tests fail, see https://github.com/YosysHQ/yosys/issues/3731

OPTIONS_GROUP=		SOLVERS
OPTIONS_GROUP_SOLVERS=	CVC5 YICES Z3
OPTIONS_DEFINE=		TCMALLOC
OPTIONS_DEFAULT=	TCMALLOC YICES # YICES: same as the default in C++ code ; TCMALLOC: should be the same default as in cad/surelog, cad/uhdm because surelog's lib is used in the yosys plugin cad/yosys-systemverilog

SOLVERS_DESC=		Install SAT solvers
CVC5_DESC=		CVC SAT Solver
YICES_DESC=		Yices SAT Solver
Z3_DESC=		Z3 SAT Solver

CVC5_RUN_DEPENDS=	cvc5:math/cvc5
YICES_RUN_DEPENDS=	yices_smt2:math/yices
Z3_RUN_DEPENDS=		z3:math/z3

TCMALLOC_LDFLAGS=	`pkg-config --libs libtcmalloc`
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

post-patch:
	${REINPLACE_CMD} -e '/^CXX =/d; s/^LD = .*/LD = $$(CXX)/' \
		-e '/^CONFIG/s/clang/${CHOSEN_COMPILER_TYPE}/' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/yosys

.include <bsd.port.mk>
