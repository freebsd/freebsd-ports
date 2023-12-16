PORTNAME=	google-cloud-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.13.0
PORTREVISION=	3
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

USES=		cmake compiler:c++17-lang pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	googleapis
GH_TUPLE=	googleapis:googleapis:${GOOGLEAPI_GH_TAG}:googleapis
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DGOOGLE_CLOUD_CPP_CXX_STANDARD=17 \
		-DGOOGLE_CLOUD_CPP_DEPENDENCY_PROVIDER=package
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING GOOGLE_CLOUD_CPP_ENABLE_CXX_EXCEPTIONS
USE_CXXSTD=	c++17

GOOGLEAPI_GH_TAG=	d39c91b3ac0abec1490ef00010107355a4dae317

post-extract:
	${MKDIR} ${BUILD_WRKSRC}/external/googleapis/src/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_googleapis} \
		${BUILD_WRKSRC}/external/googleapis/src/${GOOGLEAPI_GH_TAG}.tar.gz

.include <bsd.port.mk>
