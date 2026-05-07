PORTNAME=	esbuild
DISTVERSIONPREFIX=	v
# post to phabricator & chromium@ before committing so they can update
DISTVERSION=	0.28.0
CATEGORIES=	devel www

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Extremely fast JavaScript bundler and minifier
WWW=		https://esbuild.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
GO_MODULE=	github.com/evanw/${PORTNAME}
GO_TARGET=	./cmd/esbuild:esbuild

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
