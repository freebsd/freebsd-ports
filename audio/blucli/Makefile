PORTNAME=	blucli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
CATEGORIES=	audio net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Go-based cli for BluOS
WWW=		https://github.com/steipete/blucli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules

GO_MODULE=	github.com/steipete/blucli
GO_TARGET=	./cmd/blu

PLIST_FILES=	bin/blu

.include <bsd.port.mk>
