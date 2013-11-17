# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	libpqxx
PORTVERSION=	4.0
CATEGORIES=	databases
MASTER_SITES=	http://pqxx.org/download/software/libpqxx/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	New C++ interface for PostgreSQL

CONFLICTS=	postgresql-libpqxx-3.* postgresql-libpqxx3-3.*
PORTSCOUT=	limit:^2\.

USE_PGSQL=	yes
USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SOVERSION=	4
PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		SOVERSION=${SOVERSION}

CONFIGURE_ARGS=	--enable-shared \
		--disable-dependency-tracking

NO_STAGE=	yes
post-install:
#	This is needed for ldconfig
	${LN} -s ${PREFIX}/lib/libpqxx-${PORTVERSION}.so \
		${PREFIX}/lib/libpqxx.so.${SOVERSION}

.include <bsd.port.mk>
