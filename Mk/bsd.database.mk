# $FreeBSD$
#

.if defined(_POSTMKINCLUDED) && !defined(Database_Post_Include)

Database_Post_Include=		bsd.database.mk
Database_Include_MAINTAINER=	ports@FreeBSD.org

# This file contains some routines to interact with different databases, such
# as MySQL and Berkley DB.  To include this file, define macro
# USE_[DATABASE], for example USE_MYSQL.  Defining macro like
# USE_[DATABASE]_VER or WANT_[DATABASE]_VER will include this file as well.
#
##
# USE_MYSQL		- Add MySQL (client/server/embedded) dependency (default:
#			  client).
#			  If no version is given (by the maintainer via the port or
#			  by the user via defined variable), try to find the
#			  currently installed version.  Fall back to default if
#			  necessary (MySQL-5.6 = 56).
# DEFAULT_MYSQL_VER
#			- MySQL default version.  Can be overridden within a port.
#			  Default: 56.
# WANT_MYSQL_VER
#			- Maintainer can set an arbitrary version of MySQL to always
#			  build this port with (overrides WITH_MYSQL_VER).
# IGNORE_WITH_MYSQL
#			- This variable can be defined if the ports does not support
#			  one or more versions of MySQL.
# WITH_MYSQL_VER
#			- User defined variable to set MySQL version.
# MYSQL_VER
#			- Detected MySQL version.
##
# USE_BDB	- Add Berkeley DB library dependency.
#			  If no version is given (by the maintainer via the port or
#			  by the user via defined variable), try to find the
#			  currently installed version.  Fall back to default if
#			  necessary (db5 if compatible).
#			  This adds a "debug-bdb" make target which will dump the
#			  related data.
# INVALID_BDB_VER
#			- This variable can be defined when the port does not
#			  support one or more versions of Berkeley DB.
# WANT_BDB_VER
#			- Maintainer can set a version of Berkeley DB to always
#			  build this port with (overrides WITH_BDB_VER).
# WITH_BDB_VER
#			- User defined global variable to set Berkeley DB version.
# <BDB_UNIQUENAME>_WITH_BDB_VER
#			- User defined port specific variable to set Berkeley DB
#			  version.
# WITH_BDB_HIGHEST
#			- Use the highest installed version of Berkeley DB.
# WITH_BDB6_PERMITTED
# 			- If defined, BerkeleyDB 6 is added to the
# 			  default version set, making it eligible even
# 			  if not already installed. This is due to its
# 			  stricter Affero GNU Public License.
#
# These variables will then be filled in by this .mk file:
#
# BDB_LIB_NAME
#			- This variable is automatically set to the name of the
#			  Berkeley DB library (default: db41).
# BDB_LIB_CXX_NAME
#			- This variable is automatically set to the name of the
#			  Berkeley DB C++ library (default: db41_cxx).
# BDB_INCLUDE_DIR
#			- This variable is automatically set to the location of
#			  the Berkeley DB include directory (default:
#			  ${LOCALBASE}/include/db41).
# BDB_LIB_DIR
#			- This variable is automatically set to the location of
#			  the Berkeley DB library directory.
# BDB_VER
#			- Detected Berkeley DB version.
##
# USE_SQLITE		- Add dependency on SQLite library.  Valid values are:
#			  3 and 2.  If version is not specified directly then
#			  SQLite-3 is used (if USE_SQLITE= yes).
# SQLITE_VER
#			- Detected SQLite version.
##
# USE_FIREBIRD		- Add dependency on Firebird library.  Valid values are:
#			  2 and 1.  If no version is given by the maintainer (if
#			  USE_FIREBIRD= yes) and the user did not define
#			  WITH_FIREBIRD_VER variable, fall back to default "2".
# WITH_FIREBIRD_VER
#			- User defined variable to set Firebird version.
# FIREBIRD_VER
#			- Detected Firebird version.

.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

.if defined(DEFAULT_MYSQL_VER)
WARNING+=	"DEFAULT_MYSQL_VER is defined, consider using DEFAULT_VERSIONS=mysql=${DEFAULT_MYSQL_VER} instead"
.endif

.if defined(USE_MYSQL)
DEFAULT_MYSQL_VER?=	${MYSQL_DEFAULT:S/.//}
# MySQL client version currently supported.
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
MYSQL51_LIBVER=		16
MYSQL55_LIBVER=		18
MYSQL55m_LIBVER=	18
MYSQL55p_LIBVER=	18
MYSQL56_LIBVER=		18
MYSQL56p_LIBVER=	18
MYSQL57_LIBVER=		20
MYSQL100m_LIBVER=	18
MYSQL101m_LIBVER=	18

# Setting/finding MySQL version we want.
.if exists(${LOCALBASE}/bin/mysql)
_MYSQL!=	${LOCALBASE}/bin/mysql --version | ${SED} -e 's/.*Distrib \([0-9]\{1,2\}\)\.\([0-9]*\).*/\1\2/'
_PERCONA!=	${LOCALBASE}/bin/mysql --version | ${GREP} Percona | wc -l
_MARIADB!=	${LOCALBASE}/bin/mysql --version | ${GREP} MariaDB | wc -l

.if ${_PERCONA} == 1
_MYSQL_VER=	${_MYSQL}p
.elif ${_MARIADB} == 1
_MYSQL_VER=	${_MYSQL}m
.else
_MYSQL_VER=	${_MYSQL}
.endif
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

.if (${MYSQL_VER:C/[0-9]*//} == "m")
_MYSQL_FLAVOUR=	mariadb
.elif (${MYSQL_VER:C/[0-9]*//} == "p")
_MYSQL_FLAVOUR=	percona
.else
_MYSQL_FLAVOUR=	mysql
.endif

_MYSQL_CLIENT=	databases/${_MYSQL_FLAVOUR}${MYSQL_VER:C/[mp]//}-client
_MYSQL_SERVER=	databases/${_MYSQL_FLAVOUR}${MYSQL_VER:C/[mp]//}-server

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
RUN_DEPENDS+=	${LOCALBASE}/libexec/mysqld:${_MYSQL_SERVER}
.if (${USE_MYSQL} == "embedded")
BUILD_DEPENDS+=	${LOCALBASE}/lib/mysql/libmysqld.a:${_MYSQL_SERVER}
.endif
.else
LIB_DEPENDS+=	libmysqlclient.so.${MYSQL${MYSQL_VER}_LIBVER}:${_MYSQL_CLIENT}
.endif
.else
IGNORE=		cannot install: unknown MySQL version: ${MYSQL_VER}
.endif # Check for correct libs
.endif # USE_MYSQL

.if defined(USE_BDB)
# TODO: avoid malformed conditional with invalid USE_BDB/WITH_BDB_VER
# check if + works properly from test builds 01h12m23s

BDB_UNIQUENAME?=	${PKGNAMEPREFIX}${PORTNAME}

_USE_BDB_save:=${USE_BDB}
_WITH_BDB_VER_save:=${WITH_BDB_VER}

_DB_PORTS=		48 5 6
_DB_DEFAULTS=	48 5	# does not include 6 due to different licensing
#	but user can re-add it through WITH_BDB6_PERMITTED
. if defined(WITH_BDB6_PERMITTED)
_DB_DEFAULTS+=	6
. endif

# Dependency lines for different db versions
db48_DEPENDS=	libdb-4.8.so:databases/db48
db5_DEPENDS=	libdb-5.3.so:databases/db5
db6_DEPENDS=	libdb-6.1.so:databases/db6
# Detect db versions by finding some files
db48_FIND=	${LOCALBASE}/include/db48/db.h
db5_FIND=	${LOCALBASE}/include/db5/db.h
db6_FIND=	${LOCALBASE}/include/db6/db.h

# Override the global WITH_BDB_VER with the
# port specific <BDB_UNIQUENAME>_WITH_BDB_VER
.if defined(${BDB_UNIQUENAME:tu:S,-,_,}_WITH_BDB_VER)
WITH_BDB_VER=	${${BDB_UNIQUENAME:tu:S,-,_,}_WITH_BDB_VER}
.endif

# Override USE_BDB with global WITH_BDB_VER
.if defined(WITH_BDB_VER)
. if ${WITH_BDB_VER} != 1
USE_BDB=	${WITH_BDB_VER}
. endif
.endif

# Override USE_BDB with maintainer's WANT_BDB_VER
.if defined(WANT_BDB_VER)
USE_BDB=	${WANT_BDB_VER}
.endif

# Compatiblity hack:
# upgrade older plussed versions to 48+
_BDB_OLDPLUSVERS=4+ 40+ 41+ 42+ 43+ 44+ 45+ 46+ 47+
.for i in ${USE_BDB}
. if ${_BDB_OLDPLUSVERS:M${i}}
USE_BDB:=	48+
. endif
.endfor

.if ${USE_BDB} == yes
USE_BDB:=	48+
.endif

# 1. detect installed versions
_INST_BDB_VER=
.for bdb in ${_DB_PORTS}
. if exists(${db${bdb}_FIND})
_INST_BDB_VER+=${bdb}
. endif
.endfor

# 2. parse supported versions:
# 2a. build list from USE_BDB
_SUPP_BDB_VER=
_USE_BDB:=${USE_BDB:C,\+$,,:C/(.)(.)$/\1.\2/}
.if !empty(USE_BDB:M*+)
. for bdb in ${_DB_PORTS:C/(.)(.)$/\1.\2/}
.  if ${_USE_BDB} <= ${bdb}
_SUPP_BDB_VER+=${bdb:C/\.//}
.  endif
. endfor
.else
_SUPP_BDB_VER=${USE_BDB}
.endif
# 2b. expand INVALID_BDB_VER if given with "+":
.if !empty(INVALID_BDB_VER:M*+)
_INV_BDB:=${INVALID_BDB_VER:C,\+$,,:C/(.)(.)$/\1.\2/}
_INV_BDB_VER:=
. for bdb in ${_DB_PORTS:C/(.)(.)$/\1.\2/}
.  if ${_INV_BDB} <= ${bdb}
_INV_BDB_VER+=${bdb:C/\.//}
.  endif
. endfor
.else
_INV_BDB_VER:=${INVALID_BDB_VER}
.endif
# 2c. strip versions from INVALID_BDB_VER out of _SUPP_BDB_VER
.for unsupp in ${_INV_BDB_VER}
_SUPP_BDB_VER:=${_SUPP_BDB_VER:N${unsupp}}
.endfor

# 3a. calculate intersection in _INST_BDB_VER to see if there
# is a usable installed version
.for i in ${_INST_BDB_VER}
. if empty(_SUPP_BDB_VER:M${i})
_INST_BDB_VER:=	${_INST_BDB_VER:N${i}}
. endif
.endfor
_ELIGIBLE_BDB_VER:=${_INST_BDB_VER}

# 3b. if there is no usable version installed, check defaults
.if empty(_INST_BDB_VER)
_DFLT_BDB_VER:=${_DB_DEFAULTS}
# make sure we use a reasonable version for package builds
_WITH_BDB_HIGHEST=yes
. for i in ${_DFLT_BDB_VER}
.  if empty(_SUPP_BDB_VER:M${i})
_DFLT_BDB_VER:=	${_DFLT_BDB_VER:N${i}}
.  endif
. endfor
_ELIGIBLE_BDB_VER:=${_DFLT_BDB_VER}
.endif

# 4. elect a version
_BDB_VER=
.for i in ${_ELIGIBLE_BDB_VER}
. if !empty(WITH_BDB_HIGHEST) || !empty(_WITH_BDB_HIGHEST) || empty(${_BDB_VER})
_BDB_VER:=${i}
. endif
.endfor

# 5. catch errors or set variables
.if empty(_BDB_VER)
IGNORE=		cannot install: no eligible BerkeleyDB version. Requested: ${USE_BDB}, incompatible: ${_INV_BDB_VER}. Try: make debug-bdb
.else
. if defined(BDB_BUILD_DEPENDS)
BUILD_DEPENDS+=	${db${_BDB_VER}_FIND}:${db${_BDB_VER}_DEPENDS:C/^libdb.*://}
. else
LIB_DEPENDS+=	${db${_BDB_VER}_DEPENDS}
. endif
. if ${_BDB_VER} == 48
BDB_LIB_NAME=		db-4.8
BDB_LIB_CXX_NAME=	db_cxx-4.8
BDB_LIB_DIR=		${LOCALBASE}/lib/db48
. elif ${_BDB_VER} == 5
BDB_LIB_NAME=		db-5.3
BDB_LIB_CXX_NAME=	db_cxx-5.3
BDB_LIB_DIR=		${LOCALBASE}/lib/db5
. elif ${_BDB_VER} == 6
BDB_LIB_NAME=		db-6.1
BDB_LIB_CXX_NAME=	db_cxx-6.1
BDB_LIB_DIR=		${LOCALBASE}/lib/db6
. endif
BDB_LIB_NAME?=		db${_BDB_VER}
BDB_LIB_CXX_NAME?=	db${_BDB_VER}_cxx
BDB_INCLUDE_DIR?=	${LOCALBASE}/include/db${_BDB_VER}
BDB_LIB_DIR?=		${LOCALBASE}/lib
.endif
BDB_VER=	${_BDB_VER}

debug-bdb:
	@${ECHO_CMD} "--INPUTS----------------------------------------------------"
	@${ECHO_CMD} "${BDB_UNIQUENAME:tu:S,-,_,}_WITH_BDB_VER: ${${BDB_UNIQUENAME:tu:S,-,_,}_WITH_BDB_VER}"
	@${ECHO_CMD} "WITH_BDB_VER: ${_WITH_BDB_VER_save}"
	@${ECHO_CMD} "WANT_BDB_VER: ${WANT_BDB_VER}"
	@${ECHO_CMD} "BDB_BUILD_DEPENDS: ${BDB_BUILD_DEPENDS}"
	@${ECHO_CMD} "USE_BDB (original): ${_USE_BDB_save}"
	@${ECHO_CMD} "WITH_BDB_HIGHEST (original): ${WITH_BDB_HIGHEST}"
	@${ECHO_CMD} "--PROCESSING------------------------------------------------"
	@${ECHO_CMD} "supported versions: ${_SUPP_BDB_VER}"
	@${ECHO_CMD} "invalid versions: ${_INV_BDB_VER}"
	@${ECHO_CMD} "installed versions: ${_INST_BDB_VER}"
	@${ECHO_CMD} "eligible versions: ${_ELIGIBLE_BDB_VER}"
	@${ECHO_CMD} "USE_BDB (effective): ${USE_BDB}"
	@${ECHO_CMD} "WITH_BDB_HIGHEST (override): ${_WITH_BDB_HIGHEST}"
	@${ECHO_CMD} "--OUTPUTS---------------------------------------------------"
	@${ECHO_CMD} "IGNORE=${IGNORE}"
	@${ECHO_CMD} "BDB_VER=${BDB_VER}"
	@${ECHO_CMD} "BDB_INCLUDE_DIR=${BDB_INCLUDE_DIR}"
	@${ECHO_CMD} "BDB_LIB_NAME=${BDB_LIB_NAME}"
	@${ECHO_CMD} "BDB_LIB_CXX_NAME=${BDB_LIB_CXX_NAME}"
	@${ECHO_CMD} "BDB_LIB_DIR=${BDB_LIB_DIR}"
	@${ECHO_CMD} "BUILD_DEPENDS=${BUILD_DEPENDS:M*/databases/db*}"
	@${ECHO_CMD} "LIB_DEPENDS=${LIB_DEPENDS:M*/databases/db*}"
	@${ECHO_CMD} "------------------------------------------------------------"

# Obsolete variables - ports can define these to want users about
# variables that may be in /etc/make.conf but that are no longer
# effective:
.if defined(OBSOLETE_BDB_VAR)
. for var in ${OBSOLETE_BDB_VAR}
.  if defined(${var})
BAD_VAR+=	${var},
.  endif
. endfor
. if defined(BAD_VAR)
_IGNORE_MSG=	Obsolete variable(s) ${BAD_VAR} use WITH_BDB_VER or ${BDB_UNIQUENAME:tu:S,-,_,}_WITH_BDB_VER to select Berkeley DB version
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

.if ${USE_SQLITE:tl} == "yes"
_SQLITE_VER=	3
.else
_SQLITE_VER=	 ${USE_SQLITE}
.endif

# USE_SQLITE is specified incorrectly, so mark this as IGNORE
.if ${_SQLITE_VER} == "3"
LIB_DEPENDS+=	libsqlite3.so:databases/sqlite${_SQLITE_VER}
SQLITE_VER=	${_SQLITE_VER}
.elif ${_SQLITE_VER} == "2"
LIB_DEPENDS+=	libsqlite.so:databases/sqlite${_SQLITE_VER}
SQLITE_VER=	${_SQLITE_VER}
.else
IGNORE=		cannot install: unknown SQLite version: ${_SQLITE_VER}
.endif

.endif # defined(USE_SQLITE)

.if defined(USE_FIREBIRD)

.if defined(WITH_FIREBIRD_VER)
USE_FIREBIRD=	${WITH_FIREBIRD_VER}
.endif

.if ${USE_FIREBIRD:tl} == "yes"
FIREBIRD_VER=	${FIREBIRD_DEFAULT:S/.//}
.else
FIREBIRD_VER=	${USE_FIREBIRD}
.endif

.if ${FIREBIRD_VER} == "25"
LIB_DEPENDS+=	libfbclient.so:databases/firebird25-client
.else
IGNORE=		cannot install: unknown Firebird version: ${FIREBIRD_VER}
.endif

.endif # defined(USE_FIREBIRD)

.endif # defined(_POSTMKINCLUDED) && !defined(Database_Post_Include)
