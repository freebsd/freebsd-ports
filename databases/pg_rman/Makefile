# $FreeBSD$

PORTNAME=	pg_rman
PORTVERSION=	1.2.3
CATEGORIES=	databases
MASTER_SITES=	http://pg-rman.googlecode.com/files/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Online backup and restore tool for PostgreSQL

USE_GMAKE=	yes
USE_PGSQL=	client server
WANT_PGSQL_VER=	83+
MAKE_ARGS=	USE_PGXS=1
PLIST_FILES=	bin/pg_rman

NO_STAGE=	yes
.include <bsd.port.mk>
