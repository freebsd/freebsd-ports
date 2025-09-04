PORTNAME=	goprotobuf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.4
PORTREVISION=	13
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Go support for Google's protocol buffers
WWW=		https://github.com/golang/protobuf/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	protoc:devel/protobuf

USES=		go:modules
GO_MODULE=	github.com/golang/protobuf
GO_TARGET=	./protoc-gen-go

PLIST_FILES=	bin/protoc-gen-go

.include <bsd.port.mk>
