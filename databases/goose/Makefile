PORTNAME=	goose
DISTVERSIONPREFIX=	v
DISTVERSION=	3.22.0
PORTREVISION=	6
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
