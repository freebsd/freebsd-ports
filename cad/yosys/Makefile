PORTNAME=	yosys
DISTVERSIONPREFIX=	v
DISTVERSION=	0.69
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Yosys Open SYnthesis Suite
WWW=		https://yosyshq.net/yosys/ \
		https://github.com/YosysHQ/yosys

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	abc:cad/abc \
		bash:shells/bash \
		gawk:lang/gawk \
		gm4:devel/m4 \
		${LOCALBASE}/include/toml++/toml.hpp:devel/tomlplusplus
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libffi.so:devel/libffi \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	bash:shells/bash \
		vcd2fst:cad/gtkwave \
		xdot:x11/py-xdot@${PY_FLAVOR}
TEST_DEPENDS=	iverilog:cad/iverilog

USES=		bison cmake:testing compiler:c++20-lang pkgconfig python readline \
		shebangfix tcl

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ
GH_TUPLE=	fmtlib:fmt:a00f82c6b6:fmt/libs/fmt \
		jarro2783:cxxopts:4bf61f0869:cxxopts/libs/cxxopts \
		YosysHQ:symfpu:5d5e508674:symfpu/libs/symfpu

SHEBANG_FILES=	backends/smt2/smtbmc.py misc/yosys-config.in
SHEBANG_GLOB=	*.py *.sh

CMAKE_ARGS=	-DYOSYS_ABC_EXECUTABLE=${LOCALBASE}/bin/abc \
		-DYOSYS_WITHOUT_SLANG=ON \
		-DBISON_M4_EXECUTABLE=${LOCALBASE}/bin/gm4 \
		-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_TESTING_ON=	YOSYS_ENABLE_UNIT_TESTS
CMAKE_TESTING_TARGET=	test-unit

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

post-patch: # fix shebangs in cmake files
	@${REINPLACE_CMD} -e 's|/usr/bin/env python3|${PYTHON_CMD}|' ${WRKSRC}/cmake/YosysLinkTarget.cmake

post-install:
.for f in yosys yosys-filterlib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$f
.endfor

# tests as of 0.69: 100% tests passed, 0 tests failed out of 121

.include <bsd.port.mk>
