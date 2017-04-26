# Created by: vanilla@
# $FreeBSD$

PORTNAME=	grpc
PORTVERSION=	1.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Super fast C++ logging library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgflags.so:devel/gflags \
		libprotobuf.so:devel/protobuf

USE_GITHUB=	yes
GH_ACCOUNT=	grpc

USES=		cmake ssl
USE_LDCONFIG=	yes
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpthread -lm
CMAKE_ARGS=	-DgRPC_ZLIB_PROVIDER:STRING="package" \
		-DgRPC_PROTOBUF_PROVIDER:STRING="package" \
		-DgRPC_GFLAGS_PROVIDER:STRING="package" \
		-DgRPC_SSL_PROVIDER:STRING="package" \
		-DBUILD_SHARED_LIBS=ON \
		-DBUILD_STATIC_LIBS=ON

.include <bsd.port.mk>
