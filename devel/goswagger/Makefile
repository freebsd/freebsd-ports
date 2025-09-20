PORTNAME=	goswagger
DISTVERSIONPREFIX=	v
DISTVERSION=	0.32.3
CATEGORIES=	devel

MAINTAINER=	atanubisbiswas484@gmail.com
COMMENT=	Swagger 2.0 implementation for Go
WWW=		https://goswagger.io/ \
		https://github.com/go-swagger/go-swagger/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/go-swagger/go-swagger
GO_TARGET=	./cmd/swagger

PLIST_FILES=	bin/swagger

.include <bsd.port.mk>
