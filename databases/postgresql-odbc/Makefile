# New ports collection makefile for:  PostgreSQL ODBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	7.2.5
CATEGORIES=	databases
MASTER_SITES=	http://odbc.postgresql.org/ftpsite/odbc/versions/src/
PKGNAMESUFFIX?=	-odbc
DISTNAME=	psqlodbc-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net

POSTGRESQL_PORT?=	databases/postgresql7
POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../../${POSTGRESQL_PORT}/Makefile>

# PostgreSQL ODBC support needs an ODBC driver manager to be
# installed, and it supports both iODBC and unixODBC.  The following
# variable may be set at built-time to either "iodbc" or "unixodbc",
# with the former being the default:
DRIVER_MANAGER?=	iodbc

# Note that there is a potential conflict between unixODBC's and
# postgres' libodbcpsql.so. unixODBC installs versions `1' & `2' of
# the named lib, while postgres installs version `0'. The postgres
# folks say their is the best, so you might be better off removing
# the others?
.if ${DRIVER_MANAGER} == "unixodbc"
PKGNAMESUFFIX=		-unixodbc
CONFIGURE_ARGS+=	--with-unixodbc
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
.else	# assume we're using iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc --with-odbcinst=${LOCALBASE}/etc/libiodbc
.endif

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --with-libdir=${LOCALBASE}/lib --enable-pthreads \
		--with-includes=${LOCALBASE}/include

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
