# $FreeBSD$
#
# Provide support for MySQL
# Feature:	mysql
# Usage:	USES=mysql or USES=mysql:args
# Valid ARGS:	<version>, client, server, embedded
#
# version	If no version is given (by the maintainer via the port), try to
#		find the currently installed version.  Fall back to default if
#		necessary (MySQL-5.6 = 56).
# client	Depends on the libmysqlclient library (default)
# server/embedded
#		Depend on the server at run/build time. If none of these is
#		set, depends on the client.
#
# IGNORE_WITH_MYSQL
#		This variable can be defined if the ports does not support one
#		or more versions of MySQL.
# WITH_MYSQL_VER
#		User defined variable to set MySQL version.
# MYSQL_VER
#		Detected MySQL version.
#
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_MYSQL_MK)
_INCLUDE_USES_MYSQL_MK=	yes

.if !empty(mysql_ARGS)
.undef _WANT_MYSQL_VER
.undef _WANT_MYSQL_SERVER
.undef _WANT_MYSQL_EMBEDDED
_MYSQL_ARGS=		${mysql_ARGS:S/,/ /g}
.if ${_MYSQL_ARGS:Mserver}
_WANT_MYSQL_SERVER=	yes
_MYSQL_ARGS:=	${_MYSQL_ARGS:Nserver}
.endif
.if ${_MYSQL_ARGS:Membedded}
_WANT_MYSQL_EMBEDDED=	yes
_MYSQL_ARGS:=	${_MYSQL_ARGS:Nembedded}
.endif
.if ${_MYSQL_ARGS:Mclient}
_WANT_MYSQL_CLIENT=	yes
_MYSQL_ARGS:=	${_MYSQL_ARGS:Nclient}
.endif

# Port requested a version
.if !empty(_MYSQL_ARGS)
_WANT_MYSQL_VER=	${_MYSQL_ARGS}
.endif
.endif # !empty(mysql_ARGS)

.if defined(DEFAULT_MYSQL_VER)
WARNING+=	"DEFAULT_MYSQL_VER is defined, consider using DEFAULT_VERSIONS=mysql=${DEFAULT_MYSQL_VER} instead"
.endif

DEFAULT_MYSQL_VER?=	${MYSQL_DEFAULT:S/.//}
# MySQL client version currently supported.
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
MYSQL55_LIBVER=		18
MYSQL55m_LIBVER=	18
MYSQL55p_LIBVER=	18
MYSQL56_LIBVER=		18
MYSQL56p_LIBVER=	18
MYSQL57_LIBVER=		20
MYSQL57p_LIBVER=	20
MYSQL80_LIBVER=		21
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

.if defined(_WANT_MYSQL_VER)
.if defined(WITH_MYSQL_VER) && ${WITH_MYSQL_VER} != ${_WANT_MYSQL_VER}
IGNORE=		cannot install: the port wants mysql${_WANT_MYSQL_VER}-client and you try to install mysql${WITH_MYSQL_VER}-client
.endif
MYSQL_VER=	${_WANT_MYSQL_VER}
.elif defined(WITH_MYSQL_VER)
MYSQL_VER=	${WITH_MYSQL_VER}
.else
.if defined(_MYSQL_VER)
MYSQL_VER=	${_MYSQL_VER}
.else
MYSQL_VER=	${DEFAULT_MYSQL_VER}
.endif
.endif # _WANT_MYSQL_VER

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
.if defined(_WANT_MYSQL_SERVER) || defined(_WANT_MYSQL_EMBEDDED)
RUN_DEPENDS+=	${LOCALBASE}/libexec/mysqld:${_MYSQL_SERVER}
.if defined(_WANT_MYSQL_EMBEDDED)
BUILD_DEPENDS+=	${LOCALBASE}/lib/mysql/libmysqld.a:${_MYSQL_SERVER}
.endif
.endif
.if defined(_WANT_MYSQL_CLIENT) || \
	!(defined(_WANT_MYSQL_SERVER) || defined(_WANT_MYSQL_EMBEDDED))
LIB_DEPENDS+=	libmysqlclient.so.${MYSQL${MYSQL_VER}_LIBVER}:${_MYSQL_CLIENT}
.endif
.else
IGNORE=		cannot install: unknown MySQL version: ${MYSQL_VER}
.endif # Check for correct libs

.endif
