# Created by: Carlo Strub <cs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tools
DISTVERSION=	20180726
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Go Tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_TUPLE=	golang:tools:bfb5194:DEFAULT \
		golang:crypto:3cb0727:crypto/vendor/golang.org/x/crypto \
		golang:net:b6d7b13:net/vendor/golang.org/x/net

GO_PKGNAME=	golang.org/x/tools
GO_TARGET=	./cmd/benchcmp ./cmd/bundle ./cmd/callgraph ./cmd/compilebench \
		./cmd/cover ./cmd/digraph ./cmd/eg ./cmd/fiximports ./cmd/getgo \
		./cmd/go-contrib-init ./cmd/godex ./cmd/godoc ./cmd/goimports \
		./cmd/gomvpkg ./cmd/gorename ./cmd/gotype ./cmd/goyacc ./cmd/guru \
		./cmd/heapview ./cmd/html2article ./cmd/present ./cmd/ssadump \
		./cmd/stress ./cmd/stringer ./cmd/tip ./cmd/toolstash

.include <bsd.port.mk>
