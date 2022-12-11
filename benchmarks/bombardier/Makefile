PORTNAME=	bombardier
PORTVERSION=	1.2.5
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	benchmarks

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Fast cross-platform HTTP benchmarking tool written in Go
WWW=		https://github.com/codesenberg/bombardier

LICENSE=	MIT

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	codesenberg

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
