PORTNAME=	plakar
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	twisla@twis.la
COMMENT=	Utility to create distributed, versioned backups
WWW=		https://docs.plakar.io/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25,modules
GO_MODULE=	github.com/PlakarKorp/plakar
GO_TARGET=	.

PLIST_FILES=	bin/plakar

.include <bsd.port.mk>
