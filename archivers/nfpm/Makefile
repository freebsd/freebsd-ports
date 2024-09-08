PORTNAME=	nfpm
DISTVERSIONPREFIX=	v
DISTVERSION=	2.39.0
CATEGORIES=	archivers

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple deb, rpm and apk packager written in Go
WWW=		https://github.com/goreleaser/nfpm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

GO_MODULE=	github.com/goreleaser/nfpm/v2
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
