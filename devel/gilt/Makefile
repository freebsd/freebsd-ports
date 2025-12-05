PORTNAME=	gilt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.4
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	GIT layering tool
WWW=		https://retr0h.github.io/gilt/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules
GO_MODULE=	github.com/retr0h/gilt/v2

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

PLIST_FILES=	bin/gilt

.include <bsd.port.mk>
