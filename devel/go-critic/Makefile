PORTNAME=	go-critic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Opinionated Go source code linter for code audit
WWW=		https://go-critic.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GO_MODULE=	github.com/go-critic/go-critic
GO_TARGET=	./cmd/go-critic \
		./cmd/go-critic-analysis
GO_BUILDFLAGS=	-ldflags "-X main.Version=v${PKGVERSION}"

PLIST_FILES=	bin/go-critic \
		bin/go-critic-analysis

.include <bsd.port.mk>
