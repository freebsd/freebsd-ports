PORTNAME=	plakar
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	twisla@twis.la
COMMENT=	Utility to create distributed, versioned backups
WWW=		https://docs.plakar.io/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:modules
GO_MODULE=	github.com/PlakarKorp/plakar
GO_TARGET=	.

PLIST_FILES=	bin/plakar

.include <bsd.port.mk>
