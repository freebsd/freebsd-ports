# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bombardier
PORTVERSION=	1.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Fast cross-platform HTTP benchmarking tool written in Go

LICENSE=	MIT

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	codesenberg

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
