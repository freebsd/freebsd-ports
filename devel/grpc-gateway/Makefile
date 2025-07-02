PORTNAME=	grpc-gateway
DISTVERSIONPREFIX=	v
DISTVERSION=	2.27.1
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	gRPC to JSON proxy generator following the gRPC HTTP spec
WWW=		https://github.com/grpc-ecosystem/grpc-gateway/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/grpc-ecosystem/grpc-gateway/v2
GO_TARGET=	./protoc-gen-grpc-gateway \
			./protoc-gen-openapiv2

PLIST_FILES=	bin/protoc-gen-grpc-gateway \
			bin/protoc-gen-openapiv2

.include <bsd.port.mk>
