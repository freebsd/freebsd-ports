# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goprotobuf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Go support for Google's protocol buffers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	protoc:devel/protobuf

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_PROJECT=	protobuf
GH_SUBDIR=	src/github.com/golang/protobuf
GH_TUPLE=	google:go-genproto:02b4e95:genproto/src/google.golang.org/genproto

GO_TARGET=	./protoc-gen-go

PLIST_FILES=	bin/protoc-gen-go

.include <bsd.port.mk>
