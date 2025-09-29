PORTNAME=	yaegi
DISTVERSION=	0.16.1
DISTVERSIONPREFIX=	v
PORTREVISION=	17
CATEGORIES=	devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Elegant Go Interpreter - a REPL for Go
WWW=		https://github.com/traefik/yaegi

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	traefik

GO_TARGET=	./cmd/yaegi:yaegi

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
