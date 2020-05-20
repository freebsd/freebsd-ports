# $FreeBSD$

PORTNAME=	google-cloud-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0.g20190710 # the upstream master branch is mis-versioned: https://github.com/googleapis/google-cloud-cpp/issues/2871
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/nlohmann/json/releases/download/v3.4.0/:json # should use the package: https://github.com/googleapis/google-cloud-cpp/issues/2874
DISTFILES=	json.hpp:json
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amzo1337@gmail.com
COMMENT=	C++ Idiomatic Clients for Google Cloud Platform services

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protobuf>=3.7.1:devel/protobuf \
		grpc>=1.19.1:devel/grpc
LIB_DEPENDS=	libcrc32c.so:devel/crc32c \
		libcurl.so:ftp/curl \
		libgrpc.so:devel/grpc \
		libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++11-lang ssl
USE_GITHUB=	yes
GH_TAGNAME=	4dff795ca
GH_ACCOUNT=	GoogleCloudPlatform
GH_TUPLE=	googleapis:googleapis:a8ee1416f4c588f2ab92da72e7c1f588c784d3e6:googleapis
USE_LDCONFIG=	yes

CFLAGS+=	-I${BUILD_WRKSRC}/external/googleapis/src/googleapis_project-build
LDFLAGS+=	-L${BUILD_WRKSRC}/external/googleapis/src/googleapis_project-build

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING GOOGLE_CLOUD_CPP_ENABLE_CXX_EXCEPTIONS
CMAKE_ARGS=	-DGOOGLE_CLOUD_CPP_DEPENDENCY_PROVIDER=package

post-extract:
	@${MKDIR} ${BUILD_WRKSRC}/external/nlohmann_json/src/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/json.hpp ${BUILD_WRKSRC}/external/nlohmann_json/src/json.hpp
	@${MKDIR} ${BUILD_WRKSRC}/external/googleapis/src/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_googleapis} \
		${BUILD_WRKSRC}/external/googleapis/src/a8ee1416f4c588f2ab92da72e7c1f588c784d3e6.tar.gz

post-patch: # workaround for https://github.com/googleapis/google-cloud-cpp/issues/2875, also see files/patch-cmake_external_googleapis.cmake
	@${REINPLACE_CMD} "s#%%LOCALBASE%%#${LOCALBASE}#" ${WRKSRC}/cmake/external/googleapis.cmake

.include <bsd.port.mk>
