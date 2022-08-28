PORTNAME=	surelog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.36
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog 2017 Pre-processor, Parser, Elaborator, etc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	compilation fails: Creating OVM precompiled package... Segmentation fault (core dumped) # update to the current revision might help but it has C++ errors
BROKEN_armv6=	compilation fails: Creating OVM precompiled package... libunwind: personality function returned unknown result 5

BUILD_DEPENDS=	utf8cpp>0:devel/utf8cpp \
		${PYTHON_PKGNAMEPREFIX}orderedmultidict>0:devel/py-orderedmultidict@${PY_FLAVOR}
LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

USES=		cmake compiler:c++17-lang localbase:ldflags tcl:86,build
USE_JAVA=	17
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	chipsalliance
GH_PROJECT=	Surelog
GH_TUPLE=	alainmarcel:antlr4:2846660:antlr4/third_party/antlr4 \
		chipsalliance:UHDM:75eb335:UHDM/third_party/UHDM \
		capnproto:capnproto:14f24a4:UHDM_capnproto/third_party/UHDM/third_party/capnproto \
		google:googletest:25cc577:googletest/third_party/googletest \
		google:flatbuffers:799cc8f:flatbuffers/third_party/flatbuffers

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DFREEBSD_JAVA_VERSION=${USE_JAVA}

CONFLICTS_INSTALL=	capnproto capnproto080 uhdm # bin/uhdm-dump lib/libcapnp.so

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_CMAKE_BOOL=	SURELOG_WITH_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_PYTHON_DISTVERSION=${PYTHON_DISTVERSION}

.include <bsd.port.mk>
