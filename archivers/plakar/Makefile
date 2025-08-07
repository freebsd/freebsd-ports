PORTNAME=			plakar
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.1
DISTVERSIONSUFFIX=	-beta.13
PORTREVISION=	2
CATEGORIES=			archivers

MAINTAINER=		lbartoletti@FreeBSD.org
COMMENT=		Utility to create distributed, versioned backups
WWW=			https://docs.plakar.io/

LICENSE=		ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=			go:modules,1.23
GO_MODULE=		github.com/PlakarKorp/plakar
GO_TARGET=		./cmd/${PORTNAME}

PLIST_FILES=	bin/plakar

.include <bsd.port.mk>
