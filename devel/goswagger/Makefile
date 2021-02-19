# $FreeBSD$

PORTNAME=	goswagger
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Swagger 2.0 implementation for Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/go-swagger/go-swagger
GO_TARGET=	./cmd/swagger

PLIST_FILES=	bin/swagger

.include <bsd.port.mk>
