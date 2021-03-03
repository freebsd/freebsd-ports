# $FreeBSD$

PORTNAME=	google-cloud-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.0
PORTREVISION=	3
CATEGORIES=	devel
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amzo1337@gmail.com
COMMENT=	C++ Idiomatic Clients for Google Cloud Platform services

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

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
GH_ACCOUNT=	GoogleCloudPlatform
GH_TUPLE=	googleapis:googleapis:370e9f9ac14dbc73f56e15257bccc06dfebd4196:googleapis
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DGOOGLE_CLOUD_CPP_CXX_STANDARD=17 \
		-DGOOGLE_CLOUD_CPP_DEPENDENCY_PROVIDER=package
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING GOOGLE_CLOUD_CPP_ENABLE_CXX_EXCEPTIONS

CFLAGS+=	-I${BUILD_WRKSRC}/external/googleapis/src/googleapis_project-build
LDFLAGS+=	-L${BUILD_WRKSRC}/external/googleapis/src/googleapis_project-build

post-extract:
	@${MKDIR} ${BUILD_WRKSRC}/external/googleapis/src/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_googleapis} \
		${BUILD_WRKSRC}/external/googleapis/src/370e9f9ac14dbc73f56e15257bccc06dfebd4196.tar.gz

.include <bsd.port.mk>
