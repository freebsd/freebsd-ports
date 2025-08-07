PORTNAME=	go-git
DISTVERSIONPREFIX=	v
DISTVERSION=	5.10.0
PORTREVISION=	14
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly extensible git library in pure Go
WWW=		https://github.com/go-git/go-git

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/go-git/go-git/v5
GO_TARGET=	./cli/go-git
GO_BUILDFLAGS=	-ldflags=" \
			-X main.version=${DISTVERSION} \
			-X main.build=FreeBSD"

PLIST_FILES=	bin/go-git

.include <bsd.port.mk>
