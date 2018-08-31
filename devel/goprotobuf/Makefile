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

BUILD_DEPENDS=	go:lang/go
RUN_DEPENDS=	protoc:devel/protobuf

USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_PROJECT=	protobuf
GH_SUBDIR=	src/github.com/golang/protobuf
GH_TUPLE=	google:go-genproto:02b4e95:genproto/src/google.golang.org/genproto

PLIST_FILES=	bin/protoc-gen-go

do-build:
	@cd ${WRKSRC}/protoc-gen-go && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/protoc-gen-go/protoc-gen-go ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
