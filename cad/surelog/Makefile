PORTNAME=	surelog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0-3950
DISTVERSIONSUFFIX=	-g88ae53316
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog 2017 Pre-processor, Parser, Elaborator, etc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	utf8cpp>0:devel/utf8cpp \
		${PYTHON_PKGNAMEPREFIX}orderedmultidict>0:devel/py-orderedmultidict@${PY_FLAVOR}
LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

USES=		cmake compiler:c++17-lang localbase:ldflags tcl:86,build
USE_JAVA=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	chipsalliance
GH_PROJECT=	Surelog
GH_TUPLE=	\
		alainmarcel:antlr4:18ca2ee:antlr4/third_party/antlr4 \
		chipsalliance:UHDM:5a72785:UHDM/third_party/UHDM \
		capnproto:capnproto:14f24a4:UHDM_capnproto/third_party/UHDM/third_party/capnproto \
		google:googletest:1b18723:googletest/third_party/googletest \
		google:flatbuffers:f28c2b2:flatbuffers/third_party/flatbuffers

CMAKE_ON=	BUILD_SHARED_LIBS

CONFLICTS_INSTALL=	capnproto capnproto080 uhdm # bin/uhdm-dump lib/libcapnp.so

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}

OPTIONS_DEFINE=	PYTHON

PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_CMAKE_BOOL=	SURELOG_WITH_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_PYTHON_DISTVERSION=${PYTHON_DISTVERSION}
PYTHON_BROKEN=		see https://github.com/chipsalliance/Surelog/issues/2373

.include <bsd.port.mk>
