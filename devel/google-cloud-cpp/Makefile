PORTNAME=	google-cloud-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	3.13.0
PORTREVISION=	1
CATEGORIES=	devel
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
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
		libcurl.so:ftp/curl \
		libgrpc.so:devel/grpc \
		libopentelemetry_trace.so:devel/opentelemetry-cpp \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2

USES=		cmake compiler:c++17-lang pathfix pkgconfig ssl
PATHFIX_CMAKELISTSTXT=	AddPkgConfig.cmake CMakeLists.txt CompileProtos.cmake
USE_CXXSTD=	c++17
USE_GITHUB=	yes
GH_ACCOUNT=	googleapis
GH_TUPLE=	googleapis:googleapis:${GOOGLEAPI_GH_TAG}:googleapis
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DGOOGLE_CLOUD_CPP_OVERRIDE_GOOGLEAPIS_URL=file://${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_googleapis}
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING \
		GOOGLE_CLOUD_CPP_ENABLE_CXX_EXCEPTIONS \
		GOOGLE_CLOUD_CPP_WITH_MOCKS

GOOGLEAPI_GH_TAG=	14a161a98ef045be80c12ab69d924504a756f109

.include <bsd.port.mk>
