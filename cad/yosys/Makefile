PORTNAME=	yosys
DISTVERSIONPREFIX=	yosys-
DISTVERSION=	0.25
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
RUN_DEPENDS=	xdot:x11/py-xdot@${PY_FLAVOR}
TEST_DEPENDS=	bash:shells/bash \
		iverilog:cad/iverilog

USES=		bison compiler:c++11-lang gmake pkgconfig python:3.6+ readline \
		shebangfix tcl

SHEBANG_FILES=	backends/smt2/smtbmc.py \
		misc/yosys-config.in
SHEBANG_GLOB=	*.sh *.py

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}
MAKE_ARGS=	ABCEXTERNAL=abc
MAKE_ENV=	MAKE=${GMAKE}

TEST_TARGET=	test # some tests fail, see https://github.com/YosysHQ/yosys/issues/3505

OPTIONS_GROUP=		SOLVERS
OPTIONS_GROUP_SOLVERS=	CVC5 YICES Z3
OPTIONS_DEFAULT=	YICES # same as the default in C++ code

SOLVERS_DESC=		Install SAT solvers
CVC5_DESC=		CVC SAT Solver
YICES_DESC=		Yices SAT Solver
Z3_DESC=		Z3 SAT Solver

CVC5_RUN_DEPENDS=	cvc5:math/cvc5
YICES_RUN_DEPENDS=	yices_smt2:math/yices
Z3_RUN_DEPENDS=		z3:math/z3

post-patch:
	${REINPLACE_CMD} -e '/^CXX =/d; s/^LD = .*/LD = $$(CXX)/' \
		-e '/^CONFIG/s/clang/${CHOSEN_COMPILER_TYPE}/' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/yosys

.include <bsd.port.mk>
