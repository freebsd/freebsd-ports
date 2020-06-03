# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpc
PORTVERSION=	1.22.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2-based RPC framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yasm:devel/yasm
LIB_DEPENDS=	libgflags.so:devel/gflags \
		libprotobuf.so:devel/protobuf \
		libcares.so:dns/c-ares

USES=		cmake go:no_targets localbase:ldflags perl5 pkgconfig ssl

USE_GITHUB=	yes
GH_TUPLE=	google:benchmark:v1.4.1:benchmark/third_party/benchmark
USE_LDCONFIG=	yes
USE_PERL5=	build
PLIST_SUB+=	SOVERSION=${PORTVERSION}
LDFLAGS+=	-lcares

CMAKE_ARGS=	-DgRPC_ZLIB_PROVIDER:STRING="package" \
		-DgRPC_PROTOBUF_PROVIDER:STRING="package" \
		-DgRPC_GFLAGS_PROVIDER:STRING="package" \
		-DgRPC_SSL_PROVIDER:STRING="package" \
		-DgRPC_CARES_PROVIDER:STRING="package" \
		-DgRPC_BENCHMARK_PROVIDER:STRING="module" \
		-DBENCHMARK_USE_LIBCXX=ON \
		-DBENCHMARK_ENABLE_TESTING=OFF \
		-DBUILD_SHARED_LIBS=ON

.include <bsd.port.mk>
