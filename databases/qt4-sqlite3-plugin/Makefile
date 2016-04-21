# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2

COMMENT=	Qt SQLite 3 database plugin
DB=		sqlite
USES=		sqlite:3

LDFLAGS+=	-lsqlite3

BROKEN_powerpc64=	Does not build

.include "${.CURDIR:H:H}/devel/qt4/Makefile.sqldrivers"
