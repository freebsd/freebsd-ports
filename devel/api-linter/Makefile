PORTNAME=	api-linter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.69.2
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Google API Linter
WWW=		https://github.com/googleapis/api-linter/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

GO_MODULE=	github.com/googleapis/api-linter
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
