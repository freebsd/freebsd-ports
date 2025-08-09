PORTNAME=	openroad
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0-20250216
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ASIC physical design tool
WWW=		https://theopenroadproject.org \
		https://github.com/The-OpenROAD-Project

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	C++ issue on i386, should be resolved in the next update
.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	base64:converters/base64 \
		bash:shells/bash \
		boost-libs>0:devel/boost-libs \
		coin-or-lemon>0:math/lemon \
		gmake:devel/gmake \
		swig:devel/swig
LIB_DEPENDS=	libabsl_flags_parse.so:devel/abseil \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClpSolver.so:math/clp \
		libcoinasl.so:math/asl \
		libcoinmumps.so:math/coin-or-mumps \
		libCoinUtils.so:math/coinutils \
		libcudd.so:math/cudd \
		libfmt.so:devel/libfmt \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libortools.so:math/or-tools \
		libOsi.so:math/osi \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2 \
		libspdlog.so:devel/spdlog
LIB_DEPENDS+=	libgtest.so:devel/googletest # because third-party/abc looks for it

USES=		bison compiler:c++17-lang cmake eigen:3 qt:5 \
		localbase:ldflags pkgconfig python:build readline tcl:86 # the code asks for tcl-87, but build fails: https://github.com/The-OpenROAD-Project/OpenROAD/issues/508
USE_QT=		core gui widgets buildtools:build qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	The-OpenROAD-Project
GH_PROJECT=	OpenROAD
GH_TAGNAME=	888a3207a
GH_TUPLE=	The-OpenROAD-Project:OpenSTA:6e95d93:The_OpenROAD_Project_OpenSTA/src/sta \
		The-OpenROAD-Project:abc:5c9448c:abc/third-party/abc

CMAKE_OFF=	BUILD_PYTHON \
		ENABLE_TESTS
CMAKE_ON=	BUILD_TCL
CMAKE_ARGS=	-DFREEBSD_TCL_VER=${TCL_VER:S/.//} -DFREEBSD_TCL_INCLUDEDIR=${TCL_INCLUDEDIR}

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3 \
		-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH} make=${GMAKE}

PLIST_FILES=	bin/openroad \
		bin/sta

PORTSCOUT=	limit:^[0-9]\. # prevent 2021_*

post-patch: # override the TCL version to be the same as USES=tcl sets
	@${FIND} ${WRKSRC} -name FindTCL.cmake \
		| ${XARGS} ${REINPLACE_CMD} -e ' \
			s|set(TCL_POSSIBLE_NAMES |set(TCL_POSSIBLE_NAMES tcl$${FREEBSD_TCL_VER} |; \
			s|PATHS $${TCL_LIB_PARENT1}|PATHS $${FREEBSD_TCL_INCLUDEDIR} $${TCL_LIB_PARENT1}|'

post-install: # unnecessarily installs bundled OpenSTA project: https://github.com/The-OpenROAD-Project/OpenROAD/issues/597
	${RM} -r ${STAGEDIR}${PREFIX}/include/sta ${STAGEDIR}${PREFIX}/lib/libOpenSTA.a

do-test: # some tests are known to fail
	@${MKDIR} ${WRKSRC}/build/src
	@[ -f ${WRKSRC}/build/src/openroad ] || ${LN} ${STAGEDIR}${PREFIX}/bin/openroad ${WRKSRC}/build/src/openroad
	@${ECHO} "==> Unit tests"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} test/regression
	@${ECHO} "==> Flow tests"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} test/regression flow

.include <bsd.port.mk>
