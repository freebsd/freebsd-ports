# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	libpqxx
PORTVERSION=	3.0.2
CATEGORIES=	databases
MASTER_SITES=	http://pqxx.org/download/software/libpqxx/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	20080111.freebsd.org@ab.ote.we.lv
COMMENT=	A new C++ interface for PostgreSQL

CONFLICTS=	postgresql-libpqxx-2.*
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}30

USE_PGSQL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	SHLIBVERSION=3.0

CONFIGURE_ARGS=	--enable-shared

.include <bsd.port.mk>
