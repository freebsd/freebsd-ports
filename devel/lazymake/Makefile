PORTNAME=	lazymake
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI for browsing and executing Makefile targets
WWW=		https://github.com/rshelekhov/lazymake

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/rshelekhov/lazymake
GO_TARGET=	./cmd/lazymake

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
