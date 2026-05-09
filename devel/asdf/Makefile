PORTNAME=	asdf
DISTVERSIONPREFIX=	v
DISTVERSION=	${MODVERSION}
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	hoanga@gmail.com
COMMENT=	Extendable version manager
WWW=		https://asdf-vm.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules
MODVERSION=	0.16.7
GO_MODULE=	github.com/asdf-vm/asdf@v${MODVERSION}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags='-s -X main.version=${DISTVERSION}'
CGO_ENABLED=	0

PLIST_FILES=	./bin/asdf

.include <bsd.port.mk>
