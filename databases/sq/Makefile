PORTNAME=	sq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.54.1
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	CLI tool for querying multiple databases and data formats
WWW=		https://sq.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libduckdb.so:databases/duckdb

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	neilotoole

GO_MODULE=	github.com/neilotoole/sq
GO_LDFLAGS=	-X ${GO_MODULE}/cli/buildinfo.Version=${DISTVERSIONFULL}
GO_BUILDFLAGS+=	-tags duckdb_use_lib

PLIST_FILES=	bin/sq

.include <bsd.port.mk>
