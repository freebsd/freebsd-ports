PORTNAME=	go-git
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4.2
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Highly extensible git library in pure Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/go-git/go-git/v5
GO_TARGET=	./cli/go-git

PLIST_FILES=	bin/go-git

.include <bsd.port.mk>
