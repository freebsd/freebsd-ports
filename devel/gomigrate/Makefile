PORTNAME=	migrate
DISTVERSIONPREFIX=	v
DISTVERSION=	4.17.1
PORTREVISION=	3
CATEGORIES=	devel
PKGNAMEPREFIX=	go

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	CLI for performing database migrations
WWW=		https://github.com/golang-migrate/migrate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

CONFLICTS_INSTALL=	migrate

GO_MODULE=	github.com/golang-migrate/migrate/v4
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
