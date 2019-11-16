# Created by: Carlo Strub <cs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protobuf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Protocol Buffers for Go with Gadgets

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	gogo
GH_SUBDIR=	src/github.com/gogo/protobuf

GO_TARGET=	./protoc-gen-combo \
		./protoc-gen-gofast \
		./protoc-gen-gogo \
		./protoc-gen-gogofast \
		./protoc-gen-gogofaster \
		./protoc-gen-gogoslick \
		./protoc-gen-gogotypes \
		./protoc-gen-gostring \
		./protoc-min-version

.include <bsd.port.mk>
