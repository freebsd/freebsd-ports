# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpc
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	HTTP/2-based RPC framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go
LIB_DEPENDS=	libgflags.so:devel/gflags \
		libprotobuf.so:devel/protobuf \
		libcares.so:dns/c-ares

USE_GITHUB=	yes
GH_TUPLE=	grpc:grpc:v${PORTVERSION} \
		boringssl:boringssl:ebcb5be:boringssl/third_party/boringssl \
		google:benchmark:v1.1.0:benchmark/third_party/benchmark

USES=		cmake perl5 pkgconfig
USE_LDCONFIG=	yes
USE_PERL5=	build
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpthread -lcares -lm
CMAKE_ARGS=	-DgRPC_ZLIB_PROVIDER:STRING="package" \
		-DgRPC_PROTOBUF_PROVIDER:STRING="package" \
		-DgRPC_GFLAGS_PROVIDER:STRING="package" \
		-DgRPC_SSL_PROVIDER:STRING="module" \
		-DgRPC_CARES_PROVIDER:STRING="package" \
		-DgRPC_BENCHMARK_PROVIDER:STRING="module" \
		-DBENCHMARK_USE_LIBCXX=ON \
		-DBUILD_SHARED_LIBS=ON

.include <bsd.port.mk>
