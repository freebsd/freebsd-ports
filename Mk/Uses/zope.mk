# $FreeBSD$
#
# Provide support for Zope-related ports
#
# SZOPEBASEDIR		- relative base directory of zope server
# ZOPEBASEDIR		- absolute base directory of zope that is
#					  ${LOCALBASE}/${SZOPEBASEDIR} by default,
# ZOPEPRODUCTDIR	- directory, where products for zope can be found
#
# ZOPE_VERSION		- Version of zope that will be used in the port. Set this
#					  in your /etc/make.conf in case you want to use a
#					  specific version of zope.
#
# MAINTAINER: zope@FreeBSD.org

.if !defined(_INCLUDE_USES_ZOPE_MK)
_INCLUDE_USES_ZOPE_MK=	yes

_ZOPE_PORTBRANCH=	2.13
_ZOPE_ALLBRANCHES=	2.13

_PYTHON_VER_REQUIRED=	python2.7

.if defined(ZOPE_VERSION)
_ZOPE_VERSION:=	${ZOPE_VERSION}
.else
_ZOPE_VERSION:=	${_ZOPE_PORTBRANCH}
.endif

# Validate Zope version whether it meets USE_ZOPE version restriction.
_ZOPE_VERSION_CHECK:=		${USE_ZOPE:C/^([1-9]\.[0-9]*)$/\1-\1/}
_ZOPE_VERSION_MINIMUM_TMP:=	${_ZOPE_VERSION_CHECK:C/([1-9]\.[0-9]*)[-+].*/\1/}
_ZOPE_VERSION_MINIMUM:=		${_ZOPE_VERSION_MINIMUM_TMP:M[1-9].[0-9]}
_ZOPE_VERSION_MAXIMUM_TMP:=	${_ZOPE_VERSION_CHECK:C/.*-([1-9]\.[0-9]*)/\1/}
_ZOPE_VERSION_MAXIMUM:=		${_ZOPE_VERSION_MAXIMUM_TMP:M[1-9].[0-9]}

.if !empty(_ZOPE_VERSION_MINIMUM) && ( \
		${_ZOPE_VERSION} < ${_ZOPE_VERSION_MINIMUM})
_ZOPE_VERSION_NONSUPPORTED=	${_ZOPE_VERSION_MINIMUM} at least
.elif !empty(_ZOPE_VERSION_MAXIMUM) && ( \
		${_ZOPE_VERSION} > ${_ZOPE_VERSION_MAXIMUM})
_ZOPE_VERSION_NONSUPPORTED=	${_ZOPE_VERSION_MAXIMUM} at most
.endif

# If we have an unsupported version of Zope, try another.
.if defined(_ZOPE_VERSION_NONSUPPORTED)
.if defined(ZOPE_VERSION)
IGNORE=			needs Zope ${_ZOPE_VERSION_NONSUPPORTED}.\
				But you specified ${_ZOPE_VERSION}
.else
.undef _ZOPE_VERSION
.for ver in ${_ZOPE_ALLBRANCHES}
__VER=		${ver}
.if !defined(_ZOPE_VERSION) && \
	!(!empty(_ZOPE_VERSION_MINIMUM) && ( \
		${__VER} < ${_ZOPE_VERSION_MINIMUM})) && \
	!(!empty(_ZOPE_VERSION_MAXIMUM) && ( \
		${__VER} > ${_ZOPE_VERSION_MAXIMUM}))
_ZOPE_VERSION=	${ver}
.endif
.endfor
.if !defined(_ZOPE_VERSION)
IGNORE=			needs an unsupported version of Zope
_ZOPE_VERSION=	${_ZOPE_PORTBRANCH} # just to avoid version sanity checking.
.endif
.endif # defined(ZOPE_VERSION)
.endif # defined(_ZOPE_VERSION_NONSUPPORTED)

ZOPE_VERSION?=	${_ZOPE_VERSION}

.if !defined(PYTHON_VERSION)
PYTHON_VERSION=	${_PYTHON_VER_REQUIRED}
.elif ${PYTHON_VERSION} != ${_PYTHON_VER_REQUIRED}
IGNORE+=	Zope requires Python ${_PYTHON_VER_REQUIRED}.\
			But you or a port dependency specified ${PYTHON_VERSION}
.endif # !defined(PYTHON_VERSION)

# Zope-related variables
.if ${ZOPE_VERSION} == ${_ZOPE_PORTBRANCH}
RUN_DEPENDS+=	zope213>0:${PORTSDIR}/www/zope213
.else
_USES_sanity+=	300:check-makevars-zope
check-makevars-zope:
	@${ECHO} "Makefile error: bad value for ZOPE_VERSION: ${ZOPE_VERSION}."
	@${ECHO} "Legal values are: ${_ZOPE_PORTBRANCH} (default)"
	@${FALSE}
.endif
ZOPEBASEDIR?=			${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTDIR?=		Products

# Zope specific substitutions
PLIST_SUB+=		ZOPEBASEDIR=${SZOPEBASEDIR} \
				ZOPEPRODUCTDIR=${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}

.endif # !defined(_INCLUDE_USES_ZOPE_MK)
