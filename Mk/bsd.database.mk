# -*- mode: Makefile; tab-width: 4; -*-
# ex: ts=4
#
# $FreeBSD$
#

.if defined(_POSTMKINCLUDED) && !defined(Database_Post_Include)

Database_Post_Include=			bsd.database.mk
Database_Include_MAINTAINER=	ports@FreeBSD.org

# This file contains some routines to interact with different databases, such
# as MySQL, PostgreSQL, and Berkley DB.  To include this file, define macro
# USE_[DATABASE], for example USE_MYSQL.  Defining macro like
# USE_[DATABASE]_VER or WANT_[DATABASE]_VER will include this file as well.
#
##
# USE_MYSQL		- Add MySQL (client/server/embedded) dependency (default:
#				  client).
#				  If no version is given (by the maintainer via the port or
#				  by the user via defined variable), try to find the
#				  currently installed version.  Fall back to default if
#				  necessary (MySQL-5.5 = 55).
# DEFAULT_MYSQL_VER
#				- MySQL default version.  Can be overridden within a port.
#				  Default: 55.
# WANT_MYSQL_VER
#				- Maintainer can set an arbitrary version of MySQL to always
#				  build this port with (overrides WITH_MYSQL_VER).
# IGNORE_WITH_MYSQL
#				- This variable can be defined if the ports does not support
#				  one or more versions of MySQL.
# WITH_MYSQL_VER
#				- User defined variable to set MySQL version.
# MYSQL_VER
#				- Detected MySQL version.
##
# USE_PGSQL		- Add PostgreSQL client dependency.
#				  If no version is given (by the maintainer via the port or
#				  by the user via defined variable), try to find the
#				  currently installed version.  Fall back to default if
#				  necessary (PostgreSQL-8.4 = 84).
# DEFAULT_PGSQL_VER
#				- PostgreSQL default version.  Can be overridden within a
#				  port.  Default: 84.
# WANT_PGSQL_VER
#				- Maintainer can set an arbitrary version of PostgreSQL to
#				  always build this port with (overrides WITH_PGSQL_VER).
# IGNORE_WITH_PGSQL
#				- This variable can be defined if the ports does not support
#				  one or more versions of PostgreSQL.
# WITH_PGSQL_VER
#				- User defined variable to set PostgreSQL version.
# PGSQL_VER
#				- Detected PostgreSQL version.
##
# USE_BDB		- Add Berkeley DB library dependency.
#				  If no version is given (by the maintainer via the port or
#				  by the user via defined variable), try to find the
#				  currently installed version.  Fall back to default if
#				  necessary (db41+).
# INVALID_BDB_VER
#				- This variable can be defined when the port does not
#				  support one or more versions of Berkeley DB.
# WANT_BDB_VER
#				- Maintainer can set a version of Berkeley DB to always
#				  build this port with (overrides WITH_BDB_VER).
# WITH_BDB_VER
#				- User defined global variable to set Berkeley DB version.
# <UNIQUENAME>_WITH_BDB_VER
#				- User defined port specific variable to set Berkeley DB
#				  version.
# WITH_BDB_HIGHEST
#				- Use the highest installed version of Berkeley DB.
# BDB_LIB_NAME
#				- This variable is automatically set to the name of the
#				  Berkeley DB library (default: db41).
# BDB_LIB_CXX_NAME
#				- This variable is automatically set to the name of the
#				  Berkeley DB C++ library (default: db41_cxx).
# BDB_INCLUDE_DIR
#				- This variable is automatically set to the location of
#				  the Berkeley DB include directory (default:
#				  ${LOCALBASE}/include/db41).
# BDB_LIB_DIR
#				- This variable is automatically set to the location of
#				  the Berkeley DB library directory.
# BDB_VER
#				- Detected Berkeley DB version.
##
# USE_SQLITE	- Add dependency on SQLite library.  Valid values are:
#				  3 and 2.  If version is not specified directly then
#				  SQLite-3 is used (if USE_SQLITE= yes).
# SQLITE_VER
#				- Detected SQLite version.
##
# USE_FIREBIRD	- Add dependency on Firebird library.  Valid values are:
#				  2 and 1.  If no version is given by the maintainer (if
#				  USE_FIREBIRD= yes) and the user did not define
#				  WITH_FIREBIRD_VER variable, fall back to default "2".
# WITH_FIREBIRD_VER
#				- User defined variable to set Firebird version.
# FIREBIRD_VER
#				- Detected Firebird version.

.if defined(USE_MYSQL)
DEFAULT_MYSQL_VER?=	55
# MySQL client version currently supported.
MYSQL323_LIBVER=	10
MYSQL40_LIBVER=		12
MYSQL41_LIBVER=		14
MYSQL50_LIBVER=		15
MYSQL51_LIBVER=		16
MYSQL52_LIBVER=		16
MYSQL55_LIBVER=		16

# Setting/finding MySQL version we want.
.if exists(${LOCALBASE}/bin/mysql)
_MYSQL_VER!=	${LOCALBASE}/bin/mysql --version | ${SED} -e 's/.*Distrib \([0-9]\)\.\([0-9]*\).*/\1\2/'
.endif

.if defined(WANT_MYSQL_VER)
.if defined(WITH_MYSQL_VER) && ${WITH_MYSQL_VER} != ${WANT_MYSQL_VER}
IGNORE=		cannot install: the port wants mysql${WANT_MYSQL_VER}-client and you try to install mysql${WITH_MYSQL_VER}-client
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
IGNORE=		cannot install: MySQL versions mismatch: mysql${_MYSQL_VER}-client is installed and wanted version is mysql${MYSQL_VER}-client
.endif
.endif

.if (${MYSQL_VER} == "52")
_MYSQL_CLIENT=	databases/mariadb
_MYSQL_SERVER=	databases/mariadb
.else
_MYSQL_CLIENT=	databases/mysql${MYSQL_VER}-client
_MYSQL_SERVER=	databases/mysql${MYSQL_VER}-server
.endif

.if (${USE_MYSQL} == "embedded")
IGNORE_WITH_MYSQL=	323 40 41
.endif

# And now we are checking if we can use it
.if defined(MYSQL${MYSQL_VER}_LIBVER)
.if defined(IGNORE_WITH_MYSQL)
.	for VER in ${IGNORE_WITH_MYSQL}
.		if (${MYSQL_VER} == "${VER}")
IGNORE=		cannot install: does not work with MySQL version ${MYSQL_VER} (MySQL ${IGNORE_WITH_MYSQL} not supported)
.		endif
.	endfor
.endif # IGNORE_WITH_MYSQL
.if (${USE_MYSQL} == "server" || ${USE_MYSQL} == "embedded")
RUN_DEPENDS+=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/${_MYSQL_SERVER}
.if (${USE_MYSQL} == "embedded")
BUILD_DEPENDS+=	${LOCALBASE}/lib/mysql/libmysqld.a:${PORTSDIR}/${_MYSQL_SERVER}
.endif
.else
LIB_DEPENDS+=	mysqlclient.${MYSQL${MYSQL_VER}_LIBVER}:${PORTSDIR}/${_MYSQL_CLIENT}
.endif
.else
IGNORE=		cannot install: unknown MySQL version: ${MYSQL_VER}
.endif # Check for correct libs
.endif # USE_MYSQL

.if defined(USE_PGSQL)
DEFAULT_PGSQL_VER?=	84
PGSQL73_LIBVER=		3
PGSQL74_LIBVER=		3
PGSQL80_LIBVER=		4
PGSQL81_LIBVER=		4
PGSQL82_LIBVER=		5
PGSQL83_LIBVER=		5
PGSQL84_LIBVER=		5
PGSQL90_LIBVER=		5

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/pg_config)
_PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)[^0-9].*/\1\2/p'
.endif

.if defined(WANT_PGSQL_VER)
.if defined(WITH_PGSQL_VER) && ${WITH_PGSQL_VER} != ${WANT_PGSQL_VER}
IGNORE=		cannot install: the port wants postgresql${WANT_PGSQL_VER}-client and you try to install postgresql${WITH_PGSQL_VER}-client
.endif
PGSQL_VER=	${WANT_PGSQL_VER}
.elif defined(WITH_PGSQL_VER)
PGSQL_VER=	${WITH_PGSQL_VER}
.else
.if defined(_PGSQL_VER)
PGSQL_VER=	${_PGSQL_VER}
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif
.endif # WANT_PGSQL_VER

.if defined(_PGSQL_VER) && ${PGSQL_VER} != ${_PGSQL_VER}
IGNORE=		cannot install: the port wants postgresql${PGSQL_VER}-client but you have postgresql${_PGSQL_VER}-client installed
.endif

# And now we are checking if we can use it
.if defined(PGSQL${PGSQL_VER}_LIBVER)
# compatibility shim
.if defined(BROKEN_WITH_PGSQL)
IGNORE_WITH_PGSQL=${BROKEN_WITH_PGSQL}
.endif
.if defined(IGNORE_WITH_PGSQL)
.	for VER in ${IGNORE_WITH_PGSQL}
.		if (${PGSQL_VER} == "${VER}")
IGNORE=		cannot install: does not work with postgresql${PGSQL_VER}-client (PostgresSQL ${IGNORE_WITH_PGSQL} not supported)
.		endif
.	endfor
.endif # IGNORE_WITH_PGSQL
LIB_DEPENDS+=	pq.${PGSQL${PGSQL_VER}_LIBVER}:${PORTSDIR}/databases/postgresql${PGSQL_VER}-client
.else
IGNORE=		cannot install: unknown PostgreSQL version: ${PGSQL_VER}
.endif # Check for correct version
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif # USE_PGSQL


.if defined(USE_BDB)

_DB_PORTS=	2 3 40 41 42 43 44 45 46 47 48 50 51 3+ 40+ 41+ 42+ 43+ 44+ 45+ 46+ 47+ 48+ 50+ 51+
# Dependence lines for different db versions
db2_DEPENDS=	db2.0:${PORTSDIR}/databases/db2
db3_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
db40_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
db41_DEPENDS=	db41.1:${PORTSDIR}/databases/db41
db42_DEPENDS=	db-4.2.2:${PORTSDIR}/databases/db42
db43_DEPENDS=	db-4.3.0:${PORTSDIR}/databases/db43
db44_DEPENDS=	db-4.4.0:${PORTSDIR}/databases/db44
db45_DEPENDS=	db-4.5.0:${PORTSDIR}/databases/db45
db46_DEPENDS=	db-4.6.0:${PORTSDIR}/databases/db46
db47_DEPENDS=	db-4.7.0:${PORTSDIR}/databases/db47
db48_DEPENDS=	db-4.8.0:${PORTSDIR}/databases/db48
db50_DEPENDS=	db-5.0.0:${PORTSDIR}/databases/db50
db51_DEPENDS=	db-5.1.0:${PORTSDIR}/databases/db51
# Detect db versions by finding some files
db3_FIND=	${LOCALBASE}/include/db3/db.h
db40_FIND=	${LOCALBASE}/include/db4/db.h
db41_FIND=	${LOCALBASE}/include/db41/db.h
db42_FIND=	${LOCALBASE}/include/db42/db.h
db43_FIND=	${LOCALBASE}/include/db43/db.h
db44_FIND=	${LOCALBASE}/include/db44/db.h
db45_FIND=	${LOCALBASE}/include/db45/db.h
db46_FIND=	${LOCALBASE}/include/db46/db.h
db47_FIND=	${LOCALBASE}/include/db47/db.h
db48_FIND=	${LOCALBASE}/include/db48/db.h
db50_FIND=	${LOCALBASE}/include/db50/db.h
db51_FIND=	${LOCALBASE}/include/db51/db.h

# For specifying [3, 40, 41, ..]+
_DB_3P=		3 ${_DB_40P}
_DB_40P=	40 ${_DB_41P}
_DB_41P=	41 ${_DB_42P}
_DB_42P=	42 ${_DB_43P}
_DB_43P=	43 ${_DB_44P}
_DB_44P=	44 ${_DB_45P}
_DB_45P=	45 ${_DB_46P}
_DB_46P=	46 ${_DB_47P}
_DB_47P=	47 ${_DB_48P}
_DB_48P=	48 ${_DB_50P}
_DB_50P=	50 ${_DB_51P}
_DB_51P=	51

# Override the global WITH_BDB_VER with the
# port specific <UNIQUENAME>_WITH_BDB_VER
.if defined(${UNIQUENAME:U:S,-,_,}_WITH_BDB_VER)
WITH_BDB_VER=	${${UNIQUENAME:U:S,-,_,}_WITH_BDB_VER}
.endif

.if defined(WITH_BDB_VER)
. if ${WITH_BDB_VER} == 4
USE_BDB=	40
. elif ${WITH_BDB_VER} != 1
USE_BDB=	${WITH_BDB_VER}
. endif
.endif
_WANT_BDB_VER=	${USE_BDB}

# Assume the default bdb version as 41
.if ${USE_BDB:L} == "yes"
_WANT_BDB_VER=	41+
.endif

# Detect bdb version
_BDB_VER=	no
_BDB_IGNORE=	no

# Override the user defined WITH_BDB_VER with the WANT_BDB_VER
.if defined(WANT_BDB_VER)
.for bdb in ${_DB_PORTS}
.if ${WANT_BDB_VER} == "${bdb}" && ${_BDB_VER} == "no"
_BDB_VER=	${WANT_BDB_VER}
.endif
.endfor
USE_BDB=	${WANT_BDB_VER}
.else
.for bdb in ${_DB_PORTS}
.if ${_WANT_BDB_VER} == "${bdb}" && ${_BDB_VER} == "no"
_MATCHED_DB_VER:=	${bdb:S/+//}
. if ${_MATCHED_DB_VER} == "${bdb}"
# USE_BDB is exactly specified
_BDB_VER=	${bdb}
.else
# USE_BDB is specified as VER+
.  for dbx in ${_DB_${_MATCHED_DB_VER}P}
.   if exists(${db${dbx}_FIND})
_BRKDB=	no
# Skip versions we are incompatible with
.    if defined(INVALID_BDB_VER)
_CHK_BDB:=	${dbx}
.     for BRKDB in ${INVALID_BDB_VER}
.      if ${_CHK_BDB} == "${BRKDB}"
_BRKDB= yes
.      endif
.     endfor
.    endif
.    if ${_BRKDB} == no
.     if defined(WITH_BDB_HIGHEST)
# Use the highest version of Berkeley DB found
_BDB_VER=	${dbx}
.     elif ${_BDB_VER} == no
# Use the first Berkeley DB found
_BDB_VER=	${dbx}
.     endif
.    endif
.   endif
.  endfor
.  if ${_BDB_VER} == "no"
# No existing db4 version is detected in system
_BDB_VER=	${_MATCHED_DB_VER}
.  endif
. endif
.endif
.endfor
.endif

# USE_BDB is specified incorrectly, so mark this as IGNORE
.if ${_BDB_VER} == "no"
IGNORE=		cannot install: unknown Berkeley DB version: ${USE_BDB}
.else
# Now check if we can use it
. if defined(INVALID_BDB_VER)
.  for VER in ${INVALID_BDB_VER}
_CHK_PLUS:=	${VER:S/+//}
# INVALID_BDB_VER is specified as VER+
.   if ${_CHK_PLUS}  != "${VER}"
.    if ${_BDB_VER} == "${_CHK_PLUS}"
_BDB_IGNORE=	yes
.    else
.     for VER_P in ${_DB_${_CHK_PLUS}P}
.      if ${_BDB_VER} == "${VER_P}"
_BDB_IGNORE=	yes
.      endif
.     endfor
.    endif
.   elif ${_BDB_VER} == "${VER}"
_BDB_IGNORE=	yes
.   endif
.  endfor
. endif
. if ${_BDB_IGNORE} == "yes"
IGNORE=		cannot install: does not work with Berkeley DB version ${_BDB_VER} (${INVALID_BDB_VER} not supported)
. else
# Now add the dependency on Berkeley DB ${_BDB_VER) version
.if defined(BDB_BUILD_DEPENDS)
BUILD_DEPENDS+=	${db${_BDB_VER}_FIND}:${db${_BDB_VER}_DEPENDS:C/^db.*://}
.else
LIB_DEPENDS+=	${db${_BDB_VER}_DEPENDS}
.endif
.  if ${_BDB_VER} == 40
BDB_LIB_NAME=		db4
BDB_LIB_CXX_NAME=	db4_cxx
BDB_INCLUDE_DIR=	${LOCALBASE}/include/db4
.  elif ${_BDB_VER} == 42
BDB_LIB_NAME=		db-4.2
BDB_LIB_CXX_NAME=	db_cxx-4.2
BDB_LIB_DIR=		${LOCALBASE}/lib/db42
.  elif ${_BDB_VER} == 43
BDB_LIB_NAME=		db-4.3
BDB_LIB_CXX_NAME=	db_cxx-4.3
BDB_LIB_DIR=		${LOCALBASE}/lib/db43
.  elif ${_BDB_VER} == 44
BDB_LIB_NAME=		db-4.4
BDB_LIB_CXX_NAME=	db_cxx-4.4
BDB_LIB_DIR=		${LOCALBASE}/lib/db44
.  elif ${_BDB_VER} == 45
BDB_LIB_NAME=		db-4.5
BDB_LIB_CXX_NAME=	db_cxx-4.5
BDB_LIB_DIR=		${LOCALBASE}/lib/db45
.  elif ${_BDB_VER} == 46
BDB_LIB_NAME=		db-4.6
BDB_LIB_CXX_NAME=	db_cxx-4.6
BDB_LIB_DIR=		${LOCALBASE}/lib/db46
.  elif ${_BDB_VER} == 47
BDB_LIB_NAME=		db-4.7
BDB_LIB_CXX_NAME=	db_cxx-4.7
BDB_LIB_DIR=		${LOCALBASE}/lib/db47
.  elif ${_BDB_VER} == 48
BDB_LIB_NAME=		db-4.8
BDB_LIB_CXX_NAME=	db_cxx-4.8
BDB_LIB_DIR=		${LOCALBASE}/lib/db48
.  elif ${_BDB_VER} == 50
BDB_LIB_NAME=		db-5.0
BDB_LIB_CXX_NAME=	db_cxx-5.0
BDB_LIB_DIR=		${LOCALBASE}/lib/db50
.  elif ${_BDB_VER} == 51
BDB_LIB_NAME=		db-5.1
BDB_LIB_CXX_NAME=	db_cxx-5.1
BDB_LIB_DIR=		${LOCALBASE}/lib/db51
.  endif
BDB_LIB_NAME?=		db${_BDB_VER}
BDB_LIB_CXX_NAME?=	db${_BDB_VER}_cxx
BDB_INCLUDE_DIR?=	${LOCALBASE}/include/db${_BDB_VER}
BDB_LIB_DIR?=		${LOCALBASE}/lib
. endif
BDB_VER=	${_BDB_VER}
.endif

# Obsolete variables
.if defined(OBSOLETE_BDB_VAR)
. for var in ${OBSOLETE_BDB_VAR}
.  if defined(${var})
BAD_VAR+=	${var},
.  endif
. endfor
. if defined(BAD_VAR)
_IGNORE_MSG=	Obsolete variable(s) ${BAD_VAR} use WITH_BDB_VER or ${UNIQUENAME:U:S,-,_,}_WITH_BDB_VER to select Berkeley DB version
.  if defined(IGNORE)
IGNORE+= ${_IGNORE_MSG}
.  else
IGNORE=	${_IGNORE_MSG}
.  endif
. endif
.endif

.endif # USE_BDB

# Handling SQLite dependency
.if defined(USE_SQLITE)

.if ${USE_SQLITE:L} == "yes"
_SQLITE_VER=	3
.else
_SQLITE_VER=	 ${USE_SQLITE}
.endif

# USE_SQLITE is specified incorrectly, so mark this as IGNORE
.if ${_SQLITE_VER} == "3"
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite${_SQLITE_VER}
SQLITE_VER=	${_SQLITE_VER}
.elif ${_SQLITE_VER} == "34"
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite${_SQLITE_VER}
SQLITE_VER=	${_SQLITE_VER}
.elif ${_SQLITE_VER} == "2"
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite${_SQLITE_VER}
SQLITE_VER=	${_SQLITE_VER}
.else
IGNORE=		cannot install: unknown SQLite version: ${_SQLITE_VER}
.endif

.endif # defined(USE_SQLITE)

.if defined(USE_FIREBIRD)

.if defined(WITH_FIREBIRD_VER)
USE_FIREBIRD=	${WITH_FIREBIRD_VER}
.endif

.if ${USE_FIREBIRD:L} == "yes"
FIREBIRD_VER=	25
.else
FIREBIRD_VER=	${USE_FIREBIRD}
.endif

.if ${FIREBIRD_VER} == "2"
LIB_DEPENDS+=	fbclient.2:${PORTSDIR}/databases/firebird20-client
.elif ${FIREBIRD_VER} == "20"
LIB_DEPENDS+=	fbclient.2:${PORTSDIR}/databases/firebird20-client
.elif ${FIREBIRD_VER} == "21"
LIB_DEPENDS+=	fbclient.2:${PORTSDIR}/databases/firebird21-client
.elif ${FIREBIRD_VER} == "25"
LIB_DEPENDS+=	fbclient.2:${PORTSDIR}/databases/firebird25-client
.else
IGNORE=		cannot install: unknown Firebird version: ${FIREBIRD_VER}
.endif

.endif # defined(USE_FIREBIRD)

.endif # defined(_POSTMKINCLUDED) && !defined(Database_Post_Include)
