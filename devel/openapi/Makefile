PORTNAME=	openapi
PORTVERSION=	1.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of packages and tools for working with OpenAPI
WWW=		https://github.com/speakeasy-api/openapi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/speakeasy-api/openapi
GO_TARGET=	./cmd/openapi

PLIST_FILES=	bin/openapi

.include <bsd.port.mk>
