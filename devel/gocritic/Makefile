PORTNAME=	gocritic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	fuz@fuz.su
COMMENT=	Opinionated Go source code linter for code audit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/go-critic/go-critic
GO_TARGET=	./cmd/gocritic

PLIST_FILES=	bin/gocritic

.include <bsd.port.mk>
