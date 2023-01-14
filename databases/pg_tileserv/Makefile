PORTNAME=	pg_tileserv
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.9
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	PostGIS-only tile server written in Go
WWW=		https://github.com/crunchydata/pg_tileserv/issues

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
GO_MODULE=	github.com/crunchydata/pg_tileserv

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
