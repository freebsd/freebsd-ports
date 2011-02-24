# -*- mode: Makefile; tab-width: 4; -*-
# ex: ts=4
#
# $FreeBSD$
#

.if defined(_POSTMKINCLUDED) && !defined(Ldap_Post_Include)

Ldap_Post_Include=			bsd.ldap.mk
Database_Include_MAINTAINER=		ports@FreeBSD.org

# For including this file define macro USE_OPENLDAP. Defining macro like
# USE_OPENLDAP_VER or WANT_OPENLDAP_VER will include this file too.
#
##
# USE_OPENLDAP			- Add OpenLDAP client dependency.
#				  If no version is given (by the maintainer via the port or
#				  by the user via defined variable), try to find the
#				  currently installed version.  Fall back to default if
#				  necessary (OpenLDAP 2.4 = 24).
# DEFAULT_OPENLDAP_VER
#				- OpenLDAP default version. Can be overriden within a port.
#				  Default: 24.
# WANT_OPENLDAP_VER
#				- Maintainer can set an arbitrary version of OpenLDAP by using it.
# IGNORE_OPENLDAP_OPENLDAP
#				- This variable can be defined if the ports doesn't support
#				  one or more version of OpenLDAP.
# WITH_OPENLDAP_VER
#				- User defined variable to set OpenLDAP version.
# OPENLDAP_VER
#				- Detected OpenLDAP version.

.if defined(USE_OPENLDAP)
DEFAULT_OPENLDAP_VER?=	24
# OpenLDAP client versions currently supported
OPENLDAP23_LIBVER=	2.3.2
OPENLDAP24_LIBVER=	2.4.8

.if exists(${LOCALBASE}/bin/ldapwhoami)
_OPENLDAP_VER!=	${LOCALBASE}/bin/ldapwhoami -VV 2>&1 | ${GREP} ldapwhoami | ${SED} -E 's/.*OpenLDAP: ldapwhoami (2)\.(3|4).*/\1\2/'
.endif

.if defined(WANT_OPENLDAP_VER)
.if defined(WITH_OPENLDAP_VER) && ${WITH_OPENLDAP_VER} != ${WANT_OPENLDAP_VER}
IGNORE=		cannot install: the port wants openldap${WANT_OPENLDAP_VER}-client and you try to install openldap${WITH_OPENLDAP_VER}-client.
.endif
OPENLDAP_VER=	${WANT_OPENLDAP_VER}
.elif defined(WITH_OPENLDAP_VER)
OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.else
.if defined(_OPENLDAP_VER)
OPENLDAP_VER=	${_OPENLDAP_VER}
.else
OPENLDAP_VER=	${DEFAULT_OPENLDAP_VER}
.endif
.endif # WANT_OPENLDAP_VER

.if defined(_OPENLDAP_VER)
.if ${_OPENLDAP_VER} != ${OPENLDAP_VER}
IGNORE=	cannot install: OpenLDAP versions mismatch: openldap${_OPENLDAP_VER}-client is installed and wanted version is openldap${OPENLDAP_VER}-client
.endif
.endif

CFLAGS+=	-DLDAP_DEPRECATED

_OPENLDAP_CLIENT_PKG!=	${PKG_INFO} -Ex openldap.\*-client || ${TRUE}
_OPENLDAP_FLAVOUR=	${_OPENLDAP_CLIENT_PKG:C/openldap//:C/-client-.*//}

.if defined(WANT_OPENLDAP_SASL)
.if !empty(_OPENLDAP_CLIENT_PKG) && empty(_OPENLDAP_FLAVOUR)
IGNORE= cannot install: SASL support requested and ${_OPENLDAP_CLIENT_PKG} is installed
.endif
_OPENLDAP_FLAVOUR=	-sasl
.endif

# And now we are checking if we can use it
.if defined(OPENLDAP${OPENLDAP_VER}_LIBVER)
# compatability shim
.if defined(BROKEN_WITH_OPENLDAP)
IGNORE_WITH_OPENLDAP=${BROKEN_WITH_OPENLDAP}
.endif
.if defined(IGNORE_WITH_OPENLDAP)
.	for VER in ${IGNORE_WITH_OPENLDAP}
.		if (${OPENLDAP_VER} == "${VER}")
IGNORE=		cannot install: doesn't work with OpenLDAP version: ${OPENLDAP_VER} (Doesn't support OpenLDAP ${IGNORE_WITH_OPENLDAP})
.		endif
.	endfor
.endif # IGNORE_WITH_OPENLDAP
LIB_DEPENDS+=	ldap-${OPENLDAP${OPENLDAP_VER}_LIBVER}:${PORTSDIR}/net/openldap${OPENLDAP_VER}${_OPENLDAP_FLAVOUR}-client
.else
IGNORE=		cannot install: unknown OpenLDAP version: ${OPENLDAP_VER}
.endif # Check for correct libs

.endif # defined(USE_OPENLDAP)

.endif # defined(_POSTMKINCLUDED) && !defined(Ldap_Post_Include)
