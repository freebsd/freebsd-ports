PORTNAME=	pgtui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI for PostgreSQL
WWW=		https://github.com/pgplex/pgtui

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/pgplex/pgtui
GO_TARGET=	./cmd/pgtui

PLIST_FILES=	bin/pgtui

.include <bsd.port.mk>
