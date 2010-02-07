# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	libpqxx
PORTVERSION=	2.6.9
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://pqxx.org/download/software/libpqxx/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A new C++ interface for PostgreSQL

CONFLICTS=	postgresql-libpqxx-3.*
PORTSCOUT=	limit:^2\.

USE_PGSQL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}

CONFIGURE_ARGS=	--with-postgres=${LOCALBASE} \
		--enable-shared \
		--with-postgres-include=${LOCALBASE}/include/postgresql

.include <bsd.port.mk>
