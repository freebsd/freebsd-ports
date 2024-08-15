PORTNAME=	protobuf
PORTVERSION=	27.3
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/protocolbuffers/protobuf/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data interchange format library
WWW=		https://protobuf.dev/ \
		https://github.com/protocolbuffers/protobuf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	abseil>=20230802.2:devel/abseil
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libjsoncpp.so:devel/jsoncpp
TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++17-lang cpe localbase pathfix pkgconfig

CMAKE_ARGS=	-Dprotobuf_ABSL_PROVIDER=package \
		-Dprotobuf_JSONCPP_PROVIDER=package
CMAKE_OFF=	protobuf_BUILD_CONFORMANCE \
		protobuf_BUILD_EXAMPLES \
		protobuf_BUILD_EXAMPLES_MULTITEST \
		protobuf_BUILD_TESTS \
		protobuf_DISABLE_RTTI \
		protobuf_INSTALL_EXAMPLES \
		protobuf_MODULE_COMPATIBLE \
		protobuf_REMOVE_INSTALLED_HEADERS
CMAKE_ON=	protobuf_ABSOLUTE_TEST_PLUGIN_PATH \
		protobuf_ALLOW_CCACHE \
		protobuf_BUILD_LIBPROTOC \
		protobuf_BUILD_PROTOBUF_BINARIES \
		protobuf_BUILD_PROTOC_BINARIES \
		protobuf_BUILD_SHARED_LIBS \
		protobuf_INSTALL \
		protobuf_USE_EXTERNAL_GTEST \
		protobuf_VERBOSE \
		protobuf_WITH_ZLIB
CMAKE_TESTING_ON=	protobuf_BUILD_TESTS
PATHFIX_CMAKELISTSTXT=	CMakeLists.txt install.cmake
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	google

.include <bsd.port.mk>
