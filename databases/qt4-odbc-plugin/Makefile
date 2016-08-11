# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2

DB=		odbc
COMMENT=	Qt Open Database Connectivity plugin

LIB_DEPENDS=	libodbc.so:databases/unixODBC

LDFLAGS+=	-lodbc

BROKEN_powerpc64=	Does not build

.include "${.CURDIR:H:H}/devel/qt4/Makefile.sqldrivers"
