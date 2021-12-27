PORTNAME=	surelog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0-3924
DISTVERSIONSUFFIX=	-g53d571844
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog 2017 Pre-processor, Parser, Elaborator, etc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	utf8cpp>0:devel/utf8cpp
LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

USES=		cmake compiler:c++17-lang localbase:ldflags python:build tcl:86,build
USE_JAVA=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	chipsalliance
GH_PROJECT=	Surelog
GH_TUPLE=	\
		alainmarcel:antlr4:18ca2ee:antlr4/third_party/antlr4 \
		chipsalliance:UHDM:a8be019:UHDM/third_party/UHDM \
		capnproto:capnproto:14f24a4:UHDM_capnproto/third_party/UHDM/third_party/capnproto \
		google:googletest:1b18723:googletest/third_party/googletest \
		google:flatbuffers:f28c2b2:flatbuffers/third_party/flatbuffers

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}

.include <bsd.port.mk>
