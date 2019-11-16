# Created by: Brad Davis <brd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hey
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny program that sends some load to a web application

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/rakyll/hey

USE_GITHUB=	yes
GH_ACCOUNT=	rakyll

GH_TUPLE=	golang:net:04a2e54:net/vendor/golang.org/x/net \
		golang:text:v0.3.0:text/vendor/golang.org/x/text

PLIST_FILES=	bin/hey

.include <bsd.port.mk>
