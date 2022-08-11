PORTNAME=	yaegi
DISTVERSION=	0.9.23
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Elegant Go Interpreter - a REPL for Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	traefik

GO_TARGET=	./cmd/yaegi:yaegi

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
