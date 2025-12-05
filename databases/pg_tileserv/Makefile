PORTNAME=	pg_tileserv
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.11
PORTREVISION=	5
CATEGORIES=	databases

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	PostGIS-only tile server written in Go
WWW=		https://github.com/crunchydata/pg_tileserv/issues

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:1.21,modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys
GO_MODULE=	github.com/crunchydata/pg_tileserv

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
