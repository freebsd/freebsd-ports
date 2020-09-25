# $FreeBSD$

PORTNAME=	openroad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0-beta-637
DISTVERSIONSUFFIX=	-gc3706485
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
LIB_DEPENDS=	libcudd.so:math/cudd

USES=		bison compiler:c++17-lang cmake eigen:3 qt:5 tcl:86 # the code asks for tcl-87, but build fails: https://github.com/The-OpenROAD-Project/OpenROAD/issues/508
USE_GITHUB=	yes
GH_ACCOUNT=	The-OpenROAD-Project
GH_PROJECT=	OpenROAD
USE_QT=		core gui widgets buildtools_build qmake_build
GH_TUPLE=	\
		The-OpenROAD-Project:OpenSTA:ab2b1924e80f979bd6e606f8325a0d06b9d0bb5c:The_OpenROAD_Project_OpenSTA/src/OpenSTA \
		The-OpenROAD-Project:OpenDB:27d2a50961685b37a5a1b738a3cfd147ee7b9103:The_OpenROAD_Project_OpenDB/src/OpenDB \
		The-OpenROAD-Project:flute3:0c7d532bca351fae86de2d306dfcbe1060ecab01:The_OpenROAD_Project_flute3/src/flute3 \
		The-OpenROAD-Project:OpenRCX:cd6f1f3477851801df7ad199a37e0dacc1620bec:The_OpenROAD_Project_OpenRCX/src/OpenRCX \
		The-OpenROAD-Project:lef:fc84e83ef4cde0c4145655565641098d688a0fe1:The_OpenROAD_Project_lef/src/OpenDB/src/lef \
		The-OpenROAD-Project:def:c0fe2837a89f2a0947c2e8e10cef64e704214035:The_OpenROAD_Project_def/src/OpenDB/src/def

CMAKE_ARGS=	-DFREEBSD_TCL_VER=${TCL_VER:S/.//} -DFREEBSD_TCL_INCLUDEDIR=${TCL_INCLUDEDIR}

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3

BINARY_ALIAS=	tclsh=${TCLSH}

post-patch: # override the TCL version to be the same as USES=tcl sets
	@${FIND} ${WRKSRC} -name FindTCL.cmake \
		| ${XARGS} ${REINPLACE_CMD} -e ' \
			s|set(TCL_POSSIBLE_NAMES |set(TCL_POSSIBLE_NAMES tcl$${FREEBSD_TCL_VER} |; \
			s|PATHS $${TCL_LIB_PARENT1}|PATHS $${FREEBSD_TCL_INCLUDEDIR} $${TCL_LIB_PARENT1}|'

post-configure: # perhaps -ltcl leaks from some other project's cmake file
	@${REINPLACE_CMD} 's| -ltcl | |' ${BUILD_WRKSRC}/build.ninja

.include <bsd.port.mk>
