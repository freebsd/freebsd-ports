PORTNAME=	libprotobuf-mutator
PORTVERSION=	1.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for structured fuzzing with protobuffers
WWW=		https://github.com/google/libprotobuf-mutator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake:testing localbase:ldflags

CMAKE_ARGS=	-DLOCALBASE=${LOCALBASE} \
		-DPKG_CONFIG_PATH=libdata/pkgconfig
CMAKE_OFF=	LIB_PROTO_MUTATOR_DOWNLOAD_PROTOBUF \
		LIB_PROTO_MUTATOR_EXAMPLES \
		LIB_PROTO_MUTATOR_EXAMPLES_USE_LATEST \
		LIB_PROTO_MUTATOR_MSVC_STATIC_RUNTIME \
		LIB_PROTO_MUTATOR_TESTING \
		LIB_PROTO_MUTATOR_WITH_ASAN
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	LIB_PROTO_MUTATOR_TESTING
LDFLAGS+=	-labsl_hash \
		-labsl_log_internal_message \
		-labsl_log_internal_nullguard

USE_GITHUB=	yes
GH_ACCOUNT=	google

.include <bsd.port.mk>
