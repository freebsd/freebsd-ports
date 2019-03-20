# $FreeBSD$

PORTNAME=	compress
PORTVERSION=	1.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers
PKGNAMEPREFIX=	go-

MAINTAINER=	guy.tabrar@me.com
COMMENT=	Go optimised compression packages

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Go libraries should not be packaged
EXPIRATION_DATE=	2019-03-31

BUILD_DEPENDS=	go-cpuid>=0:devel/go-cpuid \
		go-crc32>=0:devel/go-crc32
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	klauspost
USES=		go
GO_PKGNAME=	github.com/klauspost/compress
GO_TARGET=	${GO_PKGNAME}/flate \
		${GO_PKGNAME}/gzip \
		${GO_PKGNAME}/snappy \
		${GO_PKGNAME}/zip \
		${GO_PKGNAME}/zlib

.include <bsd.port.mk>
