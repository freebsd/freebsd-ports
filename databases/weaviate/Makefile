PORTNAME=	weaviate
DISTVERSIONPREFIX=	v
DISTVERSION=	1.34.0
CATEGORIES=	databases # artificial-intelligence

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vector database that stores both objects and vectors
WWW=		https://weaviate.io/ \
		https://github.com/weaviate/weaviate

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# https://github.com/weaviate/weaviate/issues/9692
NOT_FOR_ARCHS=	armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	port seems to not support 32 bit platforms

USES=		go:modules

GO_MODULE=	github.com/weaviate/weaviate
GO_TARGET=	./cmd/weaviate-server

PLIST_FILES=	bin/${PORTNAME}-server

# how to start: https://docs.weaviate.io/deploy/installation-guides/docker-installation#run-weaviate-with-default-settings

.include <bsd.port.mk>
