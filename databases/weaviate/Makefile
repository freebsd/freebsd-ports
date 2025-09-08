PORTNAME=	weaviate
DISTVERSIONPREFIX=	v
DISTVERSION=	1.30.17
PORTREVISION=	1
CATEGORIES=	databases # artificial-intelligence

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vector database that stores both objects and vectors
WWW=		https://weaviate.io/ \
		https://github.com/weaviate/weaviate

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	build error: no error messages printed

USES=		go:modules

GO_MODULE=	github.com/weaviate/weaviate
GO_TARGET=	./cmd/weaviate-server

PLIST_FILES=	bin/${PORTNAME}-server

# how to start: https://docs.weaviate.io/deploy/installation-guides/docker-installation#run-weaviate-with-default-settings

.include <bsd.port.mk>
