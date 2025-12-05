PORTNAME=	pet
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple command-line snippet manager, written in Go
WWW=		https://github.com/knqyf263/pet

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

GO_MODULE=	github.com/knqyf263/pet

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
