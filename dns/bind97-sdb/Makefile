# New ports collection makefile for:	bind97-sdb-postgresql
# Date created:				2011-06-10
# Whom:					Josh Carroll <josh.carroll@gmail.com>
#
# $FreeBSD$

PORTNAME=	bind97-sdb

MAINTAINER=	josh.carroll@gmail.com

MASTERDIR=	${.CURDIR}/../bind97

CONFLICTS=	bind9? host-*

# the user may pick one and only one SDB driver. Depending on which
#	option the user picks, the appropriate patches will be applied
#	so bind is built with the proper driver
OPTIONS=	PGSQL "Build with PostgreSQL SDB support" on \
		LDAP "Build with LDAP SDB support" off

# Future use
#		DIRDB "Build with dirdb SDB support" off \
#		BDB "Build with bdb SDB support" off \
#		SQLITE "Build with sqlite SDB support" off \
#		TCL "Build with tcldb SDB support" off \
#		TIMEDB "Build with timedb SDB support" off

.include <bsd.port.options.mk>

OUR_PATCHDIR:=${.CURDIR}/files

# check that one and ONLY one of the SDB options is set
# the value of SDB_DRIVER should match the name of the
# contrib/sdb dir
num_sdb_types:=SDB
.if defined(WITH_PGSQL)
num_sdb_types+=1
USE_PGSQL=		yes
EXTRA_PATCHES+=	${OUR_PATCHDIR}/patch-pgsql-bin__named__Makefile.in \
		${OUR_PATCHDIR}/patch-pgsql-bin__named__main.c \
		${OUR_PATCHDIR}/patch-pgsql-bin__named__pgsqldb.c
SDB_DRIVER=pgsql
SDB_DRIVER_FILES=pgsqldb.c pgsqldb.h
.endif

.if defined(WITH_LDAP)
num_sdb_types+=1
USE_OPENLDAP=	yes
EXTRA_PATCHES+=	${OUR_PATCHDIR}/patch-ldap-bin__named__Makefile.in \
		${OUR_PATCHDIR}/patch-ldap-bin__named__main.c
SDB_DRIVER=ldap
SDB_DRIVER_FILES=ldapdb.c
.endif

.if defined(WITH_DIRDB)
num_sdb_types+=1
SDB_DRIVER=dir
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB DIRDB
.endif

.if defined(WITH_BDB)
num_sdb_types+=1
SDB_DRIVER=bdb
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB BDB
.endif

.if defined(WITH_SQLITE)
num_sdb_types+=1
SDB_DRIVER=sqlite
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB SQLITE
.endif

.if defined(WITH_TCL)
num_sdb_types+=1
SDB_DRIVER=tcldb
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB TCLDB
.endif

.if defined(WITH_TIMEDB)
num_sdb_types+=1
SDB_DRIVER=timedb
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB TIMEDB
.endif

# if one and only 1 of the SDB options is set
#	then the value of ${num_sdb_types} will be "SDB 1"
.if ${num_sdb_types} == "SDB"
IGNORE=You must select one SDB database type : DEBUG 1: ->${num_sdb_types}<-
.else
.	if ${num_sdb_types} != "SDB 1"
IGNORE=You have selected more than one SDB database type : DEBUG 2: ->${num_sdb_types}<-
.   endif
.endif

pre-patch:
.for FILE in ${SDB_DRIVER_FILES}
	@${CP} ${WRKSRC}/contrib/sdb/${SDB_DRIVER}/${FILE} ${WRKSRC}/bin/named
.endfor

.include "${MASTERDIR}/Makefile"
