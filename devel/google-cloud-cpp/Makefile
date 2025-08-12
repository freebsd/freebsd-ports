PORTNAME=	google-cloud-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.27.0
PORTREVISION=	19
CATEGORIES=	devel
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amzo1337@gmail.com
COMMENT=	C++ Idiomatic Clients for Google Cloud Platform services
WWW=		https://github.com/googleapis/google-cloud-cpp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386 powerpc

BUILD_DEPENDS=	grpc>=1.19.1:devel/grpc \
		nlohmann-json>0:devel/nlohmann-json \
		protobuf>=3.7.1:devel/protobuf
LIB_DEPENDS=	libabsl_strings.so:devel/abseil \
		libcares.so:dns/c-ares \
		libcrc32c.so:devel/crc32c \
		libcurl.so:ftp/curl \
		libgrpc.so:devel/grpc \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2

USES=		cmake compiler:c++17-lang pathfix pkgconfig ssl
PATHFIX_CMAKELISTSTXT=	AddPkgConfig.cmake CMakeLists.txt CompileProtos.cmake
USE_CXXSTD=	c++17
USE_GITHUB=	yes
GH_ACCOUNT=	googleapis
GH_TUPLE=	googleapis:googleapis:${GOOGLEAPI_GH_TAG}:googleapis
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DGOOGLE_CLOUD_CPP_CXX_STANDARD=17 \
		-DGOOGLE_CLOUD_CPP_DEPENDENCY_PROVIDER=package
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING \
		GOOGLE_CLOUD_CPP_ENABLE_CXX_EXCEPTIONS \
		GOOGLE_CLOUD_CPP_WITH_MOCKS

GOOGLEAPI_GH_TAG=	e3838fbf057c3b69efc1e0b8e1a5a288ee91a00d

post-extract:
	${MKDIR} ${BUILD_WRKSRC}/external/googleapis/src/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_googleapis} \
		${BUILD_WRKSRC}/external/googleapis/src/${GOOGLEAPI_GH_TAG}.tar.gz

.include <bsd.port.mk>
