# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	libpqxx
PORTVERSION=	4.0
CATEGORIES=	databases
MASTER_SITES=	http://pqxx.org/download/software/libpqxx/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A new C++ interface for PostgreSQL

CONFLICTS=	postgresql-libpqxx-3.*
PORTSCOUT=	limit:^2\.

USE_PGSQL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SOVERSION=	4
PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		SOVERSION=${SOVERSION}

CONFIGURE_ARGS=	--enable-shared \
		--disable-dependency-tracking

post-install:
#	This is needed for ldconfig
	${LN} -s ${PREFIX}/lib/libpqxx-${PORTVERSION}.so \
		${PREFIX}/lib/libpqxx.so.${SOVERSION}

.include <bsd.port.mk>
