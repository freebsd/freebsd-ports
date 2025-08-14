# Provide support for MySQL
# Feature:	mysql
# Usage:	USES=mysql or USES=mysql:args
# Valid ARGS:	<version>, client, server
#
# version	If no version is given (by the maintainer via the port), try to
#		find the currently installed version.  Fall back to default if
#		necessary (MySQL-8.0 = 80, look at bsd.default-versions.mk for
#		possible values).
# client	Depends on the libmysqlclient library (default)
# server 	Depend on the server at run/build time. If none of these is
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
# DBD_MYSQL
#		Set compatible p5-DBD-mysql version
#
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_MYSQL_MK)
_INCLUDE_USES_MYSQL_MK=	yes

.  if !empty(mysql_ARGS)
.undef _WANT_MYSQL_VER
.undef _WANT_MYSQL_SERVER
_MYSQL_ARGS=		${mysql_ARGS:S/,/ /g}
.    if ${_MYSQL_ARGS:Mserver}
_WANT_MYSQL_SERVER=	yes
_MYSQL_ARGS:=	${_MYSQL_ARGS:Nserver}
.    endif
.    if ${_MYSQL_ARGS:Mclient}
_WANT_MYSQL_CLIENT=	yes
_MYSQL_ARGS:=	${_MYSQL_ARGS:Nclient}
.    endif

# Port requested a version
.    if !empty(_MYSQL_ARGS)
_WANT_MYSQL_VER=	${_MYSQL_ARGS}
.      if   (${_WANT_MYSQL_VER:C/[0-9]*//} == "m")
_WANT_MYSQL_FLAVOUR=	mariadb
.      else
_WANT_MYSQL_FLAVOUR=	mysql
.      endif
.    endif
.  endif # !empty(mysql_ARGS)

.  if defined(DEFAULT_MYSQL_VER)
WARNING+=	"DEFAULT_MYSQL_VER is defined, consider using DEFAULT_VERSIONS=mysql=${DEFAULT_MYSQL_VER} instead"
.  endif

DEFAULT_MYSQL_VER?=	${MYSQL_DEFAULT:S/.//}
# MySQL client version currently supported.
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
MYSQL80_LIBVER=		21
MYSQL84_LIBVER=		24
MYSQL91_LIBVER=		24

.  for v in 106 1011 114 118
MYSQL${v}m_LIBVER=	3
.  endfor

# Setting/finding MySQL version we want.
.  if exists(${LOCALBASE}/bin/mariadb)
_MARIADB!=      ${LOCALBASE}/bin/mariadb --version | ${GREP} MariaDB | wc -l
.  elif exists(${LOCALBASE}/bin/mysql)
_MYSQL!=	${LOCALBASE}/bin/mysql_config --version | ${SED} -e 's/\([0-9]\{1,2\}\)\.\([0-9]*\).*/\1\2/'
_MARIADB!=	${LOCALBASE}/bin/mysql --version | ${GREP} MariaDB | wc -l

.    if ${_MARIADB} == 1
_MYSQL_VER=	${_MYSQL}m
_MYSQL_FLAVOUR=	mariadb
.    else
_MYSQL_VER=	${_MYSQL}
_MYSQL_FLAVOUR=	mysql
.    endif
.  endif

.  if defined(_WANT_MYSQL_VER)
.    if   defined(WITH_MYSQL_VER) && (${WITH_MYSQL_VER:C/[0-9]*//} == "m")
WITH_MYSQL_FLAVOUR=	mariadb
.    else
WITH_MYSQL_FLAVOUR=	mysql
.    endif
.    if defined(WITH_MYSQL_VER) && ${WITH_MYSQL_VER} != ${_WANT_MYSQL_VER}
IGNORE=		cannot install: the port wants ${_WANT_MYSQL_FLAVOUR}${_WANT_MYSQL_VER:C/[m]//}-client and you try to install ${WITH_MYSQL_FLAVOUR}${WITH_MYSQL_VER:C/[m]//}-client
.    endif
MYSQL_VER=	${_WANT_MYSQL_VER}
.  elif defined(WITH_MYSQL_VER)
MYSQL_VER=	${WITH_MYSQL_VER}
.  else
.    if defined(_MYSQL_VER)
MYSQL_VER=	${_MYSQL_VER}
.    else
MYSQL_VER=	${DEFAULT_MYSQL_VER}
.    endif
.  endif # _WANT_MYSQL_VER

.  if   ${MYSQL_VER:C/[0-9]*//} == "m"
MYSQL_FLAVOUR=     mariadb
.  else
MYSQL_FLAVOUR=     mysql
.  endif

.  if defined(_MYSQL_VER)
.    if ${_MYSQL_VER} != ${MYSQL_VER}
IGNORE=		cannot install: MySQL versions mismatch: ${_MYSQL_FLAVOUR}${_MYSQL_VER:C/[m]//}-client is installed and wanted version is ${MYSQL_FLAVOUR}${MYSQL_VER:C/[m]//}-client
.    endif
.  endif

_MYSQL_SHLIB=	libmysqlclient
.  if (${MYSQL_VER:C/[0-9]*//} == "m")
_MYSQL_SERVER_FLAVOUR=	mariadb
_MYSQL_CLIENT_FLAVOUR=	mariadb
.    if ${MYSQL_VER:C/m//} >= 105
_MYSQL_SHLIB=	libmariadb
.    endif
.  else
_MYSQL_SERVER_FLAVOUR=	mysql
_MYSQL_CLIENT_FLAVOUR=	mysql
.  endif

_MYSQL_CLIENT=	databases/${_MYSQL_CLIENT_FLAVOUR}${MYSQL_VER:C/[m]//}-client
_MYSQL_SERVER=	databases/${_MYSQL_SERVER_FLAVOUR}${MYSQL_VER:C/[m]//}-server

# And now we are checking if we can use it
.  if defined(MYSQL${MYSQL_VER}_LIBVER)
.    if defined(IGNORE_WITH_MYSQL)
.      for VER in ${IGNORE_WITH_MYSQL}
.        if (${MYSQL_VER} == "${VER}")
IGNORE=		cannot install: does not work with MySQL version ${MYSQL_VER} (MySQL ${IGNORE_WITH_MYSQL} not supported)
.        endif
.      endfor
.    endif # IGNORE_WITH_MYSQL
.    if defined(_WANT_MYSQL_SERVER)
RUN_DEPENDS+=	${LOCALBASE}/libexec/mysqld:${_MYSQL_SERVER}
.    endif
.    if defined(_WANT_MYSQL_CLIENT) || !defined(_WANT_MYSQL_SERVER)
LIB_DEPENDS+=	${_MYSQL_SHLIB}.so.${MYSQL${MYSQL_VER}_LIBVER}:${_MYSQL_CLIENT}
.    endif
.  else
IGNORE=		cannot install: unknown MySQL version: ${MYSQL_VER}
.  endif # Check for correct libs

.  if ${MYSQL_FLAVOUR} == mariadb
DBD_MYSQL=	p5-DBD-mysql4>=0:databases/p5-DBD-mysql4
.  else
DBD_MYSQL=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
.  endif

.endif
