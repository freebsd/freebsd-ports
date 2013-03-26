# Created by: Josh Carroll <josh.carroll@gmail.com>
# $FreeBSD$

PORTNAME=	bind97-sdb

MAINTAINER=	josh.carroll@gmail.com

MASTERDIR=	${.CURDIR}/../bind97

CONFLICTS=	bind9? host-*

# the user may pick one and only one SDB driver. Depending on which
#	option the user picks, the appropriate patches will be applied
#	so bind is built with the proper driver
OPTIONS_SINGLE= SDB
OPTIONS_SINGLE_SDB=	PGSQL LDAP
OPTIONS_DEFAULT=	PGSQL
PGSQL_DESC=	PostgreSQL SDB support
LDAP_DESC=	LDAP SDB support
#
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
.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
EXTRA_PATCHES+=	${OUR_PATCHDIR}/patch-pgsql-bin__named__Makefile.in \
		${OUR_PATCHDIR}/patch-pgsql-bin__named__main.c \
		${OUR_PATCHDIR}/patch-pgsql-bin__named__pgsqldb.c
SDB_DRIVER=pgsql
SDB_DRIVER_FILES=pgsqldb.c pgsqldb.h
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
EXTRA_PATCHES+=	${OUR_PATCHDIR}/patch-ldap-bin__named__Makefile.in \
		${OUR_PATCHDIR}/patch-ldap-bin__named__main.c
SDB_DRIVER=ldap
SDB_DRIVER_FILES=ldapdb.c
.endif

.if ${PORT_OPTIONS:MDIRDB}
SDB_DRIVER=dir
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB DIRDB
.endif

.if ${PORT_OPTIONS:MBDB}
SDB_DRIVER=bdb
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB BDB
.endif

.if ${PORT_OPTIONS:MSQLITE}
SDB_DRIVER=sqlite
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB SQLITE
.endif

.if ${PORT_OPTIONS:MTCL}
SDB_DRIVER=tcldb
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB TCLDB
.endif

.if ${PORT_OPTIONS:MTIMEDB}
SDB_DRIVER=timedb
SDB_DRIVER_FILES=
IGNORE=This port does not yet support SDB TIMEDB
.endif

pre-patch:
.for FILE in ${SDB_DRIVER_FILES}
	@${CP} ${WRKSRC}/contrib/sdb/${SDB_DRIVER}/${FILE} ${WRKSRC}/bin/named
.endfor

.include "${MASTERDIR}/Makefile"
