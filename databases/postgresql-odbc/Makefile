# New ports collection makefile for:  PostgreSQL ODBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	7.2.5
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	odbc/versions/src
PKGNAMESUFFIX?=	-odbc
DISTNAME=	psqlodbc-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PostgreSQL ODBC client support

# PostgreSQL ODBC support needs an ODBC driver manager to be
# installed, and it supports both iODBC and unixODBC.

.if defined(WITH_IODBC) && defined(WITH_UNIXODBC)
IGNORE=		selected mutually exclusive options: WITH_IODBC and WITH_UNIXODBC
.endif

.if !defined(WITH_IODBC) && !defined(WITH_UNIXODBC)
WITH_IODBC?=	yes
.endif

# Note that there is a potential conflict between unixODBC's and
# postgres' libodbcpsql.so. unixODBC installs versions `1' & `2' of
# the named lib, while postgres installs version `0'. The postgres
# folks say their is the best, so you might be better off removing
# the others?
.if defined(WITH_IODBC)
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc --with-odbcinst=${LOCALBASE}/etc/libiodbc
.elif defined(WITH_UNIXODBC)
PKGNAMESUFFIX=		-unixodbc
CONFIGURE_ARGS+=	--with-unixodbc
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
.endif

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --with-libdir=${LOCALBASE}/lib --enable-pthreads \
		--with-includes=${LOCALBASE}/include

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
