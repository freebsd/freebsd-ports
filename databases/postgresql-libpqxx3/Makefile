# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	libpqxx
PORTVERSION=	1.1.4
CATEGORIES=	databases
MASTER_SITES=	ftp://gborg.postgresql.org/pub/libpqxx/stable/
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net

POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_REINPLACE=	YES
INSTALLS_SHLIB=	YES

CONFIGURE_ARGS=	--with-postgres=${LOCALBASE} \
		--with-postgres-include=${LOCALBASE}/include/postgresql

.include <bsd.port.mk>
