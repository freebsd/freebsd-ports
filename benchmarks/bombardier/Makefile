PORTNAME=	bombardier
PORTVERSION=	1.2.6
DISTVERSIONPREFIX=	v
PORTREVISION=	17
CATEGORIES=	benchmarks

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Fast cross-platform HTTP benchmarking tool written in Go
WWW=		https://github.com/codesenberg/bombardier

LICENSE=	MIT

USES=		go:modules

GO_MODULE=	github.com/codesenberg/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
