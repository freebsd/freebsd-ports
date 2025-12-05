PORTNAME=	orbiton
DISTVERSIONPREFIX=	v
DISTVERSION=	2.68.8
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small, fast and limited text editor in Go
WWW=		https://roboticoverlords.org/orbiton/ \
		https://github.com/xyproto/orbiton

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

GO_MODULE=	github.com/xyproto/orbiton/v2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
