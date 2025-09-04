PORTNAME=	protobuf-go
DISTVERSIONPREFIX=	v
DISTVERSION=	1.36.8
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Go support for Protocol Buffers
WWW=		https://github.com/protocolbuffers/protobuf-go

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	google.golang.org/protobuf
GO_TARGET=	./cmd/protoc-gen-go

CONFLICTS_INSTALL=	goprotobuf

PLIST_FILES=	bin/protoc-gen-go

.include <bsd.port.mk>
