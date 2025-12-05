PORTNAME=	wush
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	ftp

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Command-line file transfer tool over wireguard
WWW=		https://github.com/coder/wush

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

GO_MODULE=	github.com/coder/wush
GO_TARGET=	./cmd/wush
GO_BUILDFLAGS=	-ldflags '-X main.version=${DISTVERSION}'
PLIST_FILES=	bin/wush

.include <bsd.port.mk>
