PORTNAME=	tldx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.4
CATEGORIES=	dns

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Domain Availability Research Tool
WWW=		https://github.com/brandonyoungdev/tldx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

GO_MODULE=	github.com/brandonyoungdev/tldx
GO_BUILDFLAGS+=	-ldflags="-s -w -X github.com/brandonyoungdev/tldx/cmd.Version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/tldx

.include <bsd.port.mk>
