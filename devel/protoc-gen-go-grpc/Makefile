PORTNAME=	protoc-gen-go-grpc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.78.0
PORTREVISION=	9
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Go implementaion of gRPC
WWW=		https://github.com/grpc/grpc-go/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
#USES=		go:modules
#GO_MODULE=	google.golang.org/grpc/cmd/protoc-gen-go-grpc
USE_GITHUB=	yes
GH_ACCOUNT=	grpc
GH_PROJECT=	grpc-go
GH_TAGNAME=	3d0dd1e
GH_TUPLE=	\
		golang:net:v0.51.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.42.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.34.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:a57be14db171:google_go_genproto/vendor/google.golang.org/genproto/googleapis/rpc \
		grpc:grpc-go:v1.81.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		protocolbuffers:protobuf-go:v1.36.11:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_TARGET=	./cmd/protoc-gen-go-grpc

PLIST_FILES=	bin/protoc-gen-go-grpc

.include <bsd.port.mk>
