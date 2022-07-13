# Created by: Carlo Strub <cs@FreeBSD.org>

PORTNAME=	protobuf
DISTVERSION=	1.3.2
PORTREVISION=	3
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Protocol Buffers for Go with Gadgets

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go

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

CPE_VENDOR=	golang

.include <bsd.port.mk>
