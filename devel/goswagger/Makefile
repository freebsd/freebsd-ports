PORTNAME=	goswagger
DISTVERSIONPREFIX=	v
DISTVERSION=	0.30.4
PORTREVISION=	19
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Swagger 2.0 implementation for Go
WWW=		https://goswagger.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/go-swagger/go-swagger
GO_TARGET=	./cmd/swagger

PLIST_FILES=	bin/swagger

.include <bsd.port.mk>
