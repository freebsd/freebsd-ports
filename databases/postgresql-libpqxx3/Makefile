# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	libpqxx
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://gborg.postgresql.org/pub/libpqxx/stable/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net
COMMENT=	A new C++ interface for  PostgreSQL

POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES

CONFIGURE_ARGS=	--with-postgres=${LOCALBASE} \
		--with-postgres-include=${LOCALBASE}/include/postgresql

.include <bsd.port.mk>
