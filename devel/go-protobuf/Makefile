PORTNAME=	protobuf
DISTVERSION=	1.3.2
DISTVERSIONPREFIX=	v
PORTREVISION=	20
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Protocol Buffers for Go with Gadgets
WWW=		https://github.com/gogo/protobuf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream officially deprecated this project
EXPIRATION_DATE=2024-06-30

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
