PORTNAME=	nfpm
DISTVERSIONPREFIX=	v
DISTVERSION=	2.44.0
PORTREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple deb, rpm and apk packager written in Go
WWW=		https://github.com/goreleaser/nfpm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:1.25,modules

GO_MODULE=	github.com/goreleaser/nfpm/v2
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
