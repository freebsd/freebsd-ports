PORTNAME=	wire
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	11
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	Compile-time Dependency Injection for Go
WWW=		https://github.com/google/wire

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/google/wire
GO_TARGET=	./cmd/wire

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
