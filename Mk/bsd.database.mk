# -*- mode: Makefile; tab-width: 4; -*-
# ex: ts=4
#
# $FreeBSD$
#

.if defined(_POSTMKINCLUDED) && !defined(Database_Post_Include)

Database_Post_Include=			bsd.database.mk
Database_Include_MAINTAINER=	vsevolod@FreeBSD.org

# This file contains some routines to interact with different databases, such
# as mysql, postgresql and berkley DB. For including this file define macro
# USE_[DATABASE], for example USE_MYSQL. Defining macro like USE_[DATABASE]_VER
# or WANT_[DATABSE]_VER will include this file too.
#
##
# USE_MYSQL		- Add MySQL client dependency.
#				  If no version is given (by the maintainer via the port or
#				  by the user via defined variable), try to find the
#				  currently installed version.  Fall back to default if
#				  necessary (MySQL4.1 = 41).
# DEFAULT_MYSQL_VER
#				- MySQL default version. Can be overriden within a port.
#				  Default: 41.
# WANT_MYSQL_VER
#				- Maintainer can set an arbitrary version of MySQL by using it.
# BROKEN_WITH_MYSQL
#				- This variable can be defined if the ports doesn't support
#				  one or more version of MySQL.
# MYSQL_VER		- Internal variable for MySQL version.
# WITH_MYSQL_VER
#				- User defined variable to set MySQL version.
##
# USE_PGSQL		- Add PostgreSQL client dependency.
#				  If no version is given (by the maintainer via the port or
#				  by the user via defined variable), try to find the
#				  currently installed version.  Fall back to default if
#				  necessary (PostgreSQL-7.4 = 74).
# DEFAULT_PGSQL_VER
#				- PostgreSQL default version. Can be overridden within a port.
#				  Default: 74.
# WANT_PGSQL_VER
#				- Maintainer can set an arbitrary version of PostgreSQL by
#				  using it.
# BROKEN_WITH_PGSQL
#				- This variable can be defined if the ports doesn't support
#				  one or more versions of PostgreSQL.
##
# USE_BDB		- Add Berkley DB library dependency.
#                 If no version is given (by the maintainer via the port or
#                 by the user via defined variable), try to find the
#                 currently installed version.  Fall back to default if
#                 necessary (db41+).
##
# USE_SQLITE	- Add dependency on sqlite library. Valid values are:
#				  3 and 2. If version is not specified directly then
#				  sqlite3 is used (if USE_SQLITE= yes).

.if defined(USE_MYSQL)
DEFAULT_MYSQL_VER?=	41
# MySQL client version currently supported.
MYSQL323_LIBVER=	10
MYSQL40_LIBVER=		12
MYSQL41_LIBVER=		14
MYSQL50_LIBVER=		15
MYSQL51_LIBVER=		15

# Setting/finding MySQL version we want.
.if exists(${LOCALBASE}/bin/mysql)
_MYSQL_VER!=	${LOCALBASE}/bin/mysql --version | ${SED} -e 's/.*Distrib \([0-9]\)\.\([0-9]*\).*/\1\2/'
.endif

.if defined(WANT_MYSQL_VER)
.if defined(WITH_MYSQL_VER) && ${WITH_MYSQL_VER} != ${WANT_MYSQL_VER}
IGNORE=		cannot install: the port wants mysql${WANT_MYSQL_VER}-client and you try to install mysql${WITH_MYSQL_VER}-client.
.endif
MYSQL_VER=	${WANT_MYSQL_VER}
.elif defined(WITH_MYSQL_VER)
MYSQL_VER=	${WITH_MYSQL_VER}
.else
.if defined(_MYSQL_VER)
MYSQL_VER=	${_MYSQL_VER}
.else
MYSQL_VER=	${DEFAULT_MYSQL_VER}
.endif
.endif # WANT_MYSQL_VER

.if defined(_MYSQL_VER)
.if ${_MYSQL_VER} != ${MYSQL_VER}
IGNORE=	cannot install: MySQL versions mismatch: mysql${_MYSQL_VER}-client is installed and wanted version is mysql${MYSQL_VER}-client
.endif
.endif

# And now we are checking if we can use it
.if defined(MYSQL${MYSQL_VER}_LIBVER)
.if defined(BROKEN_WITH_MYSQL)
.	for VER in ${BROKEN_WITH_MYSQL}
.		if (${MYSQL_VER} == "${VER}")
IGNORE=		cannot install: doesn't work with MySQL version : ${MYSQL_VER} (Doesn't support MySQL ${BROKEN_WITH_MYSQL})
.		endif
.	endfor
.endif # BROKEN_WITH_MYSQL
LIB_DEPENDS+=	mysqlclient.${MYSQL${MYSQL_VER}_LIBVER}:${PORTSDIR}/databases/mysql${MYSQL_VER}-client
.else
IGNORE=		cannot install: unknown MySQL version: ${MYSQL_VER}
.endif # Check for correct libs
.endif # USE_MYSQL

.if defined(USE_PGSQL)
DEFAULT_PGSQL_VER?=	74
PGSQL73_LIBVER=		3
PGSQL74_LIBVER=		3
PGSQL80_LIBVER=		4
PGSQL81_LIBVER=		4

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/pg_config)
_PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)[^0-9].*/\1\2/p'
.endif

.if defined(WANT_PGSQL_VER) && defined(_PGSQL_VER) && ${WANT_PGSQL_VER} != ${_PGSQL_VER}
IGNORE=		cannot install: the port wants postgresql${WANT_PGSQL_VER}-client but you have postgresql${_PGSQL_VER}-client installed
.endif

.if defined(_PGSQL_VER)
PGSQL_VER=	${_PGSQL_VER}
.elif defined(WANT_PGSQL_VER)
PGSQL_VER=	${WANT_PGSQL_VER}
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

# And now we are checking if we can use it
.if defined(PGSQL${PGSQL_VER}_LIBVER)
.if defined(BROKEN_WITH_PGSQL)
.	for VER in ${BROKEN_WITH_PGSQL}
.		if (${PGSQL_VER} == "${VER}")
IGNORE=		cannot install: does not work with postgresql${PGSQL_VER}-client PostgresSQL (${BROKEN_WITH_PGSQL} not supported)
.		endif
.	endfor
.endif # BROKEN_WITH_PGSQL
LIB_DEPENDS+=	pq.${PGSQL${PGSQL_VER}_LIBVER}:${PORTSDIR}/databases/postgresql${PGSQL_VER}-client
.else
IGNORE=		cannot install: unknown PostgreSQL version: ${PGSQL_VER}
.endif # Check for correct version
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif # USE_PGSQL


.if defined(USE_BDB)

_DB_PORTS=	2 3 40 41 42 43 40+ 41+ 42+ 43+
# Dependence lines for different db versions
db2_DEPENDS=	db2.0:${PORTSDIR}/databases/db2
db3_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
db40_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
db41_DEPENDS=	db41.1:${PORTSDIR}/databases/db41
db42_DEPENDS=	db-4.2.2:${PORTSDIR}/databases/db42
db43_DEPENDS=	db-4.3.0:${PORTSDIR}/databases/db43
# Detect db4 versions by finding some files
db40_FIND=	${PREFIX}/include/db4/db.h
db41_FIND=	${PREFIX}/include/db41/db.h
db42_FIND=	${PREFIX}/include/db42/db.h
db43_FIND=	${PREFIX}/include/db43/db.h

# For specifying 40+ 41+ 42+
_DB_40P=	40 41 42 43
_DB_41P=	41 42 43
_DB_42P=	42 43

_WANT_BDB_VER=	${USE_BDB}

# Assume the default bdb version as 41
.if ${USE_BDB:L} == "yes"
_WANT_BDB_VER=	41+
.endif

# Detect bdb version
_FOUND=	no

.for bdb in ${_DB_PORTS}
.if ${_WANT_BDB_VER} == "${bdb}" && ${_FOUND} == "no"
_MATCHED_DB_VER:=	${bdb:S/+//}
. if ${_MATCHED_DB_VER} == "${bdb}"
# USE_BDB is exactly specified
LIB_DEPENDS+=	${db${bdb}_DEPENDS}
_FOUND=	yes
.else
# USE_BDB is specified as VER+
.  for db4 in ${_DB_${_MATCHED_DB_VER}P}
.   if exists(${db${db4}_FIND}) && ${_FOUND} == "no"
LIB_DEPENDS+=   ${db${db4}_DEPENDS}
_FOUND=	yes
.   endif
.  endfor
.  if ${_FOUND} == "no"
# No existing db4 version is detected in system
LIB_DEPENDS+=	${db${_MATCHED_DB_VER}_DEPENDS}
_FOUND=	yes
.  endif
. endif
.endif
.endfor

# USE_BDB is specified incorrectly, so mark this as IGNORE
.if ${_FOUND} == "no"
IGNORE=	cannot install: unknown bdb version: ${USE_BDB}
.endif

.endif # USE_BDB

# Handling sqlite dependency
.if defined(USE_SQLITE)

.if ${USE_SQLITE:L} == "yes"
_SQLITE_VER=	3
.else
_SQLITE_VER=	${USE_SQLITE}
.endif

# USE_SQLITE is specified incorrectly, so mark this as IGNORE
.if ${_SQLITE_VER} == "3"
LIB_DEPENDS+=	sqlite${_SQLITE_VER}:${PORTSDIR}/databases/sqlite${_SQLITE_VER}
.elif ${_SQLITE_VER} == "2"
LIB_DEPENDS+=	sqlite.${_SQLITE_VER}:${PORTSDIR}/databases/sqlite${_SQLITE_VER}
.else
IGNORE=	cannot install: unknown sqlite version: ${_SQLITE_VER}
.endif

.endif # defined(USE_SQLITE)

.endif # defined(_POSTMKINCLUDED) && !defined(Database_Post_Include)
