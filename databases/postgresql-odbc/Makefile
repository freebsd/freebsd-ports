# New ports collection makefile for:	PostgreSQL JDBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql-odbc
CATEGORIES=	databases

MAINTAINER=	girgen@partitur.se

POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../postgresql7/Makefile>

CONFIGURE_ARGS= --with-libdir=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
MAKE_ARGS=	LDFLAGS=${LDFLAGS}

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
CONFIGURE_ARGS+=	--with-unixodbc
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
PLIST_SUB+=UNIXODBC="" IODBC="@comment "
.else	# assume we're using iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc --with-odbcinst=${LOCALBASE}/etc/libiodbc
PLIST_SUB+=UNIXODBC="@comment " IODBC=""
.endif

MAKEFILE=	GNUmakefile
MAKE_ARGS+=	-C src/interfaces/odbc

.include <bsd.port.mk>
