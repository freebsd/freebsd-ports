PORTNAME=	goose
DISTVERSIONPREFIX=	v
DISTVERSION=	3.21.1
PORTREVISION=	2
CATEGORIES=	databases
PKGNAMESUFFIX=	-db-migration-tool

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Database migration tool
WWW=		https://pressly.github.io/goose/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/pressly/goose/v3
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
