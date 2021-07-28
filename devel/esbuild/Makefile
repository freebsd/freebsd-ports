PORTNAME=	esbuild
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.16
CATEGORIES=	devel www

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Extremely fast JavaScript bundler and minifier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	evanw
GH_TUPLE=	golang:sys:bc7a7d42d5c3:golang_sys/vendor/golang.org/x/sys

GO_TARGET=	./cmd/esbuild:esbuild

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
