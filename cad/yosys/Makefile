PORTNAME=	yosys
DISTVERSIONPREFIX=	v
DISTVERSION=	0.57
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Yosys Open SYnthesis Suite
WWW=		https://yosyshq.net/yosys/ \
		https://github.com/YosysHQ/yosys

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	abc:cad/abc \
		bash:shells/bash \
		cxxopts>0:devel/cxxopts \
		gawk:lang/gawk
LIB_DEPENDS=	libffi.so:devel/libffi
RUN_DEPENDS=	bash:shells/bash \
		xdot:x11/py-xdot@${PY_FLAVOR}

TEST_DEPENDS=	iverilog:cad/iverilog

USES=		bison compiler:c++11-lang gmake pkgconfig python readline \
		shebangfix tcl

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ

SHEBANG_FILES=	backends/smt2/smtbmc.py misc/yosys-config.in
SHEBANG_GLOB=	*.py *.sh

MAKE_ARGS=	ABCEXTERNAL=abc
MAKE_ENV=	MAKE=${GMAKE}

TEST_TARGET=	test

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}

OPTIONS_DEFINE=		TCMALLOC
OPTIONS_DEFAULT=	TCMALLOC YICES # YICES: same as the default in C++ code ; TCMALLOC: should be the same default as in cad/surelog, cad/uhdm because surelog's lib is used in the yosys plugin cad/yosys-systemverilog
OPTIONS_GROUP=		SOLVERS
OPTIONS_GROUP_SOLVERS=	CVC5 YICES Z3

CVC5_DESC=	CVC SAT Solver
SOLVERS_DESC=	Install SAT solvers
YICES_DESC=	Yices SAT Solver
Z3_DESC=	Z3 SAT Solver

CVC5_RUN_DEPENDS=	cvc5:math/cvc5
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools
TCMALLOC_LDFLAGS=	`pkg-config --libs libtcmalloc`
YICES_RUN_DEPENDS=	yices_smt2:math/yices
Z3_RUN_DEPENDS=		z3:math/z3

post-patch:
	${REINPLACE_CMD} -e '/^CXX =/d; s/^LD = .*/LD = $$(CXX)/' \
		-e '/^CONFIG/s/clang/${CHOSEN_COMPILER_TYPE}/' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/yosys

.include <bsd.port.mk>
