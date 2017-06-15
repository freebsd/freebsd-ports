# $FreeBSD$

PORTNAME=	ksql
PORTVERSION=	0.0.9
CATEGORIES=	devel databases
MASTER_SITES=	http://kristaps.bsd.lv/ksql/snapshots/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Lazy man's wrapper for the SQLite C API

LICENSE=	ISCL

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=	localbase
MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"
ALL_TARGET=	libksql.a

.include <bsd.port.mk>
