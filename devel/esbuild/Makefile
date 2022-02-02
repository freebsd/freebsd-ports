PORTNAME=	esbuild
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.14
CATEGORIES=	devel www

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Extremely fast JavaScript bundler and minifier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	evanw

.include "${.CURDIR}/Makefile.deps"

GO_TARGET=	./cmd/esbuild:esbuild

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
