# $FreeBSD$

PORTNAME=	openroad
DISTVERSION=	2021_03_09
DISTVERSIONSUFFIX=	_stable
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ASIC physical design tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	C++ issue on i386, should be resolved in the next update

BUILD_DEPENDS=	base64:converters/base64 \
		boost-libs>0:devel/boost-libs \
		coin-or-lemon>0:math/lemon \
		swig:devel/swig
LIB_DEPENDS=	libcudd.so:math/cudd \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog

USES=		bison compiler:c++17-lang cmake eigen:3 qt:5 localbase:ldflags tcl:86 # the code asks for tcl-87, but build fails: https://github.com/The-OpenROAD-Project/OpenROAD/issues/508
USE_QT=		core gui widgets buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	The-OpenROAD-Project
GH_PROJECT=	OpenROAD
GH_TUPLE=	The-OpenROAD-Project:OpenSTA:181a9f2:The_OpenROAD_Project_OpenSTA/src/sta

CMAKE_OFF=	BUILD_PYTHON FREEBSD_BUILD_TESTS
CMAKE_ON=	BUILD_TCL
CMAKE_ARGS=	-DFREEBSD_TCL_VER=${TCL_VER:S/.//} -DFREEBSD_TCL_INCLUDEDIR=${TCL_INCLUDEDIR}

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3

BINARY_ALIAS=	tclsh=${TCLSH}

PLIST_FILES=	bin/openroad \
		bin/sta

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
