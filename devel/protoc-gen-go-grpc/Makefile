PORTNAME=	protoc-gen-go-grpc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.74.2
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Go implementaion of gRPC
WWW=		https://github.com/grpc/grpc-go/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	grpc
GH_PROJECT=	grpc-go
GH_TUPLE=	\
		golang:net:v0.35.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.30.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.22.0:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:1a7da9e5054f:google_go_genproto/vendor/google.golang.org/genproto/googleapis/rpc \
		grpc:grpc-go:v1.70.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		open-telemetry:opentelemetry-go:v1.34.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		protocolbuffers:protobuf-go:v1.36.6:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_TARGET=	./cmd/protoc-gen-go-grpc

PLIST_FILES=	bin/protoc-gen-go-grpc

.include <bsd.port.mk>
