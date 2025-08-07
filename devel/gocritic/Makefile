PORTNAME=	gocritic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Opinionated Go source code linter for code audit
WWW=		https://go-critic.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GO_MODULE=	github.com/go-critic/go-critic
GO_TARGET=	./cmd/gocritic \
		./cmd/gocritic-analysis
GO_BUILDFLAGS=	-ldflags "-X main.Version=v${PKGVERSION}"

PLIST_FILES=	bin/gocritic \
		bin/gocritic-analysis

.include <bsd.port.mk>
