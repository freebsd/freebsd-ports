PORTNAME=	buf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.32.1
PORTREVISION=	10
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI tool for working with Protocol Buffers
WWW=		https://buf.build/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	jq:textproc/jq

USES=		go:modules

GO_MODULE=	github.com/bufbuild/buf
GO_TARGET=	./cmd/buf \
		./cmd/protoc-gen-buf-breaking \
		./cmd/protoc-gen-buf-lint

PLIST_FILES=	bin/buf \
		bin/protoc-gen-buf-breaking \
		bin/protoc-gen-buf-lint

.include <bsd.port.mk>
