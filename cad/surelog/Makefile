PORTNAME=	surelog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.51
PORTREVISION=	1
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
LIB_DEPENDS=	libcapnp.so:devel/capnproto \
		libtcmalloc.so:devel/google-perftools \
		libuhdm.so:cad/uhdm

USES=		cmake:testing compiler:c++17-lang localbase:ldflags tcl:86,build
USE_JAVA=	17 # Java selection fails in cmake when Java 11 is also installed, see https://gitlab.kitware.com/cmake/cmake/-/issues/24674
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/surelog

USE_GITHUB=	yes
GH_ACCOUNT=	chipsalliance
GH_PROJECT=	Surelog
GH_TUPLE=	alainmarcel:antlr4:3143e88:antlr4/third_party/antlr4 \
		google:googletest:e1ee0fa:googletest/third_party/googletest \
		google:flatbuffers:32a6744:flatbuffers/third_party/flatbuffers

CMAKE_ON=	BUILD_SHARED_LIBS SURELOG_USE_HOST_UHDM
CMAKE_OFF=	SURELOG_BUILD_TESTS
CMAKE_ARGS=	-DFREEBSD_JAVA_VERSION=${USE_JAVA} \
		-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_TESTING_ON=	SURELOG_BUILD_TESTS # unclear how to run tests, see https://github.com/chipsalliance/Surelog/issues/3545
CMAKE_TESTING_TARGET=	UnitTests

CONFLICTS_INSTALL=	capnproto capnproto080

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_CMAKE_BOOL=	SURELOG_WITH_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_PYTHON_DISTVERSION=${PYTHON_DISTVERSION}

PORTSCOUT=	limit:^.*[0-9]\.[0-9] # prevent tags like 'show'

post-install:
	@${RMDIR} \
		${STAGEDIR}${PREFIX}/bin/pkg/work \
		${STAGEDIR}${PREFIX}/bin/pkg

post-test:
	cd ${BUILD_WRKSRC} && ctest

.include <bsd.port.mk>
