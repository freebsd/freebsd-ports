PORTNAME=	wire
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	jordan@ostreff.info
COMMENT=	Compile-time Dependency Injection for Go
WWW=		https://github.com/goforj/wire/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/goforj/wire
GO_TARGET=	./cmd/wire

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
