PORTNAME=	goose
DISTVERSIONPREFIX=	v
DISTVERSION=	3.27.2
CATEGORIES=	databases
PKGNAMESUFFIX=	-db-migration-tool

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Database migration tool
WWW=		https://pressly.github.io/goose/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:modules

GO_MODULE=	github.com/pressly/goose/v3
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
