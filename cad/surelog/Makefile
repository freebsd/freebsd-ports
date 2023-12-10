PORTNAME=	surelog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.82
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog 2017 Pre-processor, Parser, Elaborator, etc
WWW=		https://github.com/chipsalliance/Surelog

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	compilation fails: Creating OVM precompiled package... Segmentation fault (core dumped) # update to the current revision might help but it has C++ errors
BROKEN_armv6=	compilation fails: Creating OVM precompiled package... libunwind: personality function returned unknown result 5
BROKEN_i386=	compilation fails: conversion function cannot be redeclared, see https://github.com/chipsalliance/Surelog/issues/3206

BUILD_DEPENDS=	utf8cpp>0:devel/utf8cpp \
		${PYTHON_PKGNAMEPREFIX}orderedmultidict>0:devel/py-orderedmultidict@${PY_FLAVOR}
BUILD_DEPENDS+=	googletest>0:devel/googletest # workaround for https://github.com/chipsalliance/Surelog/issues/3826
LIB_DEPENDS=	libcapnp.so:devel/capnproto \
		libuhdm.so:cad/uhdm
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang localbase:ldflags tcl:86,build
USE_JAVA=	17 # Java selection fails in cmake when Java 11 is also installed, see https://gitlab.kitware.com/cmake/cmake/-/issues/24674
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/surelog

JAVA_BUILD=	yes
JAVA_RUN=	no

USE_GITHUB=	yes
GH_ACCOUNT=	chipsalliance
GH_PROJECT=	Surelog
GH_TUPLE=	alainmarcel:antlr4:a27cf84:antlr4/third_party/antlr4 \
		nlohmann:json:788e546:json/third_party/json

CMAKE_ON=	BUILD_SHARED_LIBS \
		SURELOG_USE_HOST_UHDM \
		SURELOG_USE_HOST_CAPNP \
		SURELOG_USE_HOST_GTEST
CMAKE_OFF=	SURELOG_BUILD_TESTS
CMAKE_ARGS=	-DFREEBSD_JAVA_VERSION=${USE_JAVA} \
		-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_TESTING_ON=	SURELOG_BUILD_TESTS # 2 tests fail, see https://github.com/chipsalliance/Surelog/issues/3545
CMAKE_TESTING_TARGET=	UnitTests

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}

CONFLICTS_BUILD=	openjdk8 openjdk11 openjdk18 openjdk19

OPTIONS_DEFINE=		PYTHON TCMALLOC
OPTIONS_DEFAULT=	PYTHON TCMALLOC # should be the same TCMALLOC default as in cad/yosys, cad/uhdm because surelog's lib is used in the yosys plugin cad/yosys-systemverilog
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_BUILD_DEPENDS=	swig:devel/swig
PYTHON_CMAKE_BOOL=	SURELOG_WITH_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_PYTHON_DISTVERSION=${PYTHON_DISTVERSION}

TCMALLOC_CMAKE_BOOL=	SURELOG_WITH_TCMALLOC
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

PORTSCOUT=	limit:^.*[0-9]\.[0-9] # prevent tags like 'show'

post-install: # workaround for https://github.com/chipsalliance/Surelog/issues/3596
	@${RMDIR} \
		${STAGEDIR}${DATADIR}/pkg/work \
		${STAGEDIR}${DATADIR}/pkg \
		${STAGEDIR}${DATADIR}

post-test:
	cd ${BUILD_WRKSRC} && ctest

.include <bsd.port.mk>
