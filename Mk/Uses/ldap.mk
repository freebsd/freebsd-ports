# Provide support for OpenLDAP
# Feature:	ldap
# Usage:	USES=ldap or USES=ldap:args
# Valid ARGS:	<version>, client, server, (none)
#
# version	If no version is given (by the maintainer via the port), try to
#		find the currently installed version.  Fall back to default if
#		necessary (OpenLDAP-2.6 = 26, look at bsd.default-versions.mk for
#		possible values).
# client	Depends on the libldap library (default)
# server
#		Depend on the server at runtime. If none of these is
#		set, depends on the client.
#
# IGNORE_WITH_OPENLDAP
#		This variable can be defined if the ports does not support one
#		or more version of OpenLDAP.
# WITH_OPENLDAP_VER
#		User defined variable to set OpenLDAP version.
# OPENLDAP_VER
#		Detected OpenLDAP version.
#
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_LDAP_MK)
_INCLUDE_USES_LDAP_MK=    yes

.  if !empty(ldap_ARGS)
.undef _WANT_OPENLDAP_VER
.undef _WANT_OPENLDAP_SERVER
_OPENLDAP_ARGS=		${ldap_ARGS:S/,/ /g}
.    if ${_OPENLDAP_ARGS:Mserver}
_WANT_OPENLDAP_SERVER=	yes
_OPENLDAP_ARGS:=	${_OPENLDAP_ARGS:Nserver}
.    endif
.    if ${_OPENLDAP_ARGS:Mclient}
_WANT_OPENLDAP_CLIENT=	yes
_OPENLDAP_ARGS:=	${_OPENLDAP_ARGS:Nclient}
.    endif

# Port requested a version
.    if !empty(_OPENLDAP_ARGS)
_WANT_OPENLDAP_VER=	${_OPENLDAP_ARGS}
.    endif
.  endif # !empty(ldap_ARGS)

.  if defined(DEFAULT_OPENLDAP_VER)
WARNING+=	"DEFAULT_OPENLDAP_VER is defined, consider using DEFAULT_VERSIONS=openldap=${DEFAULT_OPENLDAP_VER} instead"
.  endif

DEFAULT_OPENLDAP_VER?=	${OPENLDAP_DEFAULT:S/.//}
# OpenLDAP client version currently supported.
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
# OpenLDAP client versions currently supported
OPENLDAP25_LIB=		libldap-2.5.so.0
OPENLDAP26_LIB=		libldap.so.2

.  if exists(${LOCALBASE}/bin/ldapwhoami)
_OPENLDAP_VER!=	${LOCALBASE}/bin/ldapwhoami -VV 2>&1 | ${GREP} ldapwhoami | ${SED} -E 's/.*OpenLDAP: ldapwhoami (2)\.([0-9]).*/\1\2/'
.  endif

.  if defined(WANT_OPENLDAP_VER)
.    if defined(WITH_OPENLDAP_VER) && ${WITH_OPENLDAP_VER} != ${WANT_OPENLDAP_VER}
IGNORE=		cannot install: the port wants openldap${WANT_OPENLDAP_VER}-client and you try to install openldap${WITH_OPENLDAP_VER}-client
.    endif
OPENLDAP_VER=	${WANT_OPENLDAP_VER}
.  elif defined(WITH_OPENLDAP_VER)
OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.  else
.    if defined(_OPENLDAP_VER)
OPENLDAP_VER=	${_OPENLDAP_VER}
.    else
OPENLDAP_VER=	${DEFAULT_OPENLDAP_VER}
.    endif
.  endif # WANT_OPENLDAP_VER

.  if defined(_OPENLDAP_VER)
.    if ${_OPENLDAP_VER} != ${OPENLDAP_VER}
IGNORE=	cannot install: OpenLDAP versions mismatch: openldap${_OPENLDAP_VER}-client is installed and wanted version is openldap${OPENLDAP_VER}-client
.    endif
.  endif

CFLAGS+=	-DLDAP_DEPRECATED

_OPENLDAP_CLIENT=	net/openldap${OPENLDAP_VER}-client
_OPENLDAP_SERVER=	net/openldap${OPENLDAP_VER}-server

# And now we are checking if we can use it
.  if defined(OPENLDAP${OPENLDAP_VER}_LIB)
.    if defined(IGNORE_WITH_OPENLDAP)
.      for VER in ${IGNORE_WITH_OPENLDAP}
.        if (${OPENLDAP_VER} == "${VER}")
IGNORE=		cannot install: doesn't work with OpenLDAP version: ${OPENLDAP_VER} (Doesn't support OpenLDAP ${IGNORE_WITH_OPENLDAP})
.        endif
.      endfor
.    endif # IGNORE_WITH_OPENLDAP
.    if defined(_WANT_OPENLDAP_SERVER)
RUN_DEPENDS+=	${LOCALBASE}/libexec/slapd:${_OPENLDAP_SERVER}
.    endif
.    if defined(_WANT_OPENLDAP_CLIENT) || !defined(_WANT_OPENLDAP_SERVER)
LIB_DEPENDS+=	${OPENLDAP${OPENLDAP_VER}_LIB}:${_OPENLDAP_CLIENT}
.    endif
.  else
IGNORE=		cannot install: unknown OpenLDAP version: ${OPENLDAP_VER}
.  endif # Check for correct libs

.endif # !defined(_INCLUDE_USES_LDAP_MK)
