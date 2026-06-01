PORTNAME=	openroad
DISTVERSION=	26Q2
PORTEPOCH=	1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ASIC physical design tool
WWW=		https://theopenroadproject.org \
		https://github.com/The-OpenROAD-Project

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

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
		libbzip2.so:misc/vxl \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClpSolver.so:math/clp \
		libcoinasl.so:math/asl \
		libcoinmumps.so:math/coin-or-mumps \
		libCoinUtils.so:math/coinutils \
		libcudd.so:math/cudd \
		libfmt.so:devel/libfmt \
		libhighs.so:math/highs \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libortools.so:math/or-tools \
		libOsi.so:math/osi \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2 \
		libspdlog.so:devel/spdlog \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd
LIB_DEPENDS+=	libgtest.so:devel/googletest # because third-party/abc looks for it
LIB_DEPENDS+=	libicudata.so:devel/icu

TEST_DEPENDS=	${LOCALBASE}/lib/tcllib/json/json.tcl:devel/tcllib

USES=		bison compiler:c++20-lang cmake eigen:3 qt:5 \
		localbase:ldflags pkgconfig python:build readline tcl:86
USE_QT=		core gui widgets buildtools:build qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	The-OpenROAD-Project
GH_PROJECT=	OpenROAD
GH_TUPLE=	The-OpenROAD-Project:OpenSTA:43177bb:The_OpenROAD_Project_OpenSTA/src/sta \
		The-OpenROAD-Project:abc:17cadca:abc/third-party/abc

CMAKE_OFF=	BUILD_PYTHON \
		ENABLE_TESTS
CMAKE_ON=	BUILD_TCL
CMAKE_ARGS=	-DFREEBSD_TCL_VER=${TCL_VER:S/.//} -DFREEBSD_TCL_INCLUDEDIR=${TCL_INCLUDEDIR}

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3 \
		-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH} make=${GMAKE}

PLIST_FILES=	bin/openroad \
		bin/sta

PORTSCOUT=	limit:^[0-9][0-9]Q

post-patch: # override the TCL version to be the same as USES=tcl sets
	@${FIND} ${WRKSRC} -name FindTCL.cmake \
		| ${XARGS} ${REINPLACE_CMD} -e ' \
			s|set(TCL_POSSIBLE_NAMES |set(TCL_POSSIBLE_NAMES tcl$${FREEBSD_TCL_VER} |; \
			s|PATHS $${TCL_LIB_PARENT1}|PATHS $${FREEBSD_TCL_INCLUDEDIR} $${TCL_LIB_PARENT1}|'

post-install: # unnecessarily installs bundled OpenSTA project: https://github.com/The-OpenROAD-Project/OpenROAD/issues/597
	${RM} -r ${STAGEDIR}${PREFIX}/include/sta ${STAGEDIR}${PREFIX}/lib/libOpenSTA.a

do-test: # some tests are known to fail
	@${MKDIR} ${WRKSRC}/build/bin
	@[ -f ${WRKSRC}/build/bin/openroad ] || ${LN} ${STAGEDIR}${PREFIX}/bin/openroad ${WRKSRC}/build/bin/openroad
	@${ECHO} "==> Unit tests"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} test/regression
	@${ECHO} "==> Flow tests"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} test/regression flow

.include <bsd.port.mk>
