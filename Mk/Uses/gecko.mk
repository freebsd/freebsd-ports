# $FreeBSD$
#
# Handle dependency of different gecko based applications
#
# MAINTAINER: gecko@FreeBSD.org
#
# Feature:	gecko
# Usage:	USES=gecko or USES=gecko:ARGS
# Valid ARGS:	libxul, firefox, seamonkey, thunderbird
#		in case the first argument is not libxul
#		The following arguments are available
#		- build: also add the dependency as a build
#		         dependency
#		- [0-9][0-9][+]?: a version optionnally
#		                  followed by a +
#

.if !defined(_INCLUDE_USES_GECKO_MK)
_INCLUDE_USES_GECKO_MK=	yes

.if !defined(gecko_ARGS)
_GECKO_ARGS=	libxul
.else
_GECKO_ARGS=	${gecko_ARGS:S/,/ /g}
.endif

_GECKO_VERSION=	${_GECKO_ARGS:M[0-9][0-9]*}

.if ${_GECKO_ARGS:Mlibxul}
# Compat with older versions
GECKO=	libxul
GECKO_CONFING?=	${LOCALBASE}/bin/${GECKO}-config
XPIDL?=		${LOCALBASE}/lib/${GECKO}/xpidl
XPIDL_INCL?=	`${GECKO_CONFIG} --idlflags`

BUILD_DEPENDS+=	libxul>=24:${PORTSDIR}/www/libxul
RUN_DEPENDS+=	libxul>=24:${PORTSDIR}/www/libxul

.elif ${_GECKO_ARGS:Mfirefox}

_GECKO_DEFAULT_VERSION=	31
_GECKO_VERSIONS=		31 33
_GECKO_TYPE=	firefox

# Dependence lines for different Firefox versions
31_DEPENDS=		${LOCALBASE}/lib/firefox/firefox:${PORTSDIR}/www/firefox-esr
33_DEPENDS=		${LOCALBASE}/lib/firefox/firefox:${PORTSDIR}/www/firefox

.if exists(${LOCALBASE}/bin/firefox)
_GECKO_INSTALLED_VER!=	${LOCALBASE}/bin/firefox --version 2>/dev/null
_GECKO_INSTALLED_VER:=	${_GECKO_INSTALLED_VER:M[0-9][0-9]*:C/([0-9][0-9]).*/\1/g}
.endif

.elif ${_GECKO_ARGS:Mseamonkey}

_GECKO_DEFAULT_VERSION=	29
_GECKO_VERSIONS=		29
_GECKO_TYPE=	seamonkey

.if exists(${LOCALBASE}/bin/seamonkey)
_GECKO_INSTALLED_VER!=	${LOCALBASE}/bin/seamonkey --version 2>/dev/null
_GECKO_INSTALLED_VER:=	${_GECKO_INSTALLED_VER:M[0-9]*:C/[0-9].([0-9][0-9]).*/\1/g}
.endif

# Dependence lines for different Seamonkey versions
29_DEPENDS=		${LOCALBASE}/lib/seamonkey/seamonkey:${PORTSDIR}/www/seamonkey

.elif ${_GECKO_ARGS:Mthunderbird}

_GECKO_DEFAULT_VERSION=	31
_GECKO_VERSIONS=	31
_GECKO_TYPE=	thunderbird

.if exists(${LOCALBASE}/bin/thunderbird)
_GECKO_INSTALLED_VER!=	${LOCALBASE}/bin/thunderbird --version 2>/dev/null
_GECKO_INSTALLED_VER:=	${_GECKO_INSTALLED_VER:M[0-9][0-9]*:C/([0-9][0-9]).*/\1/g}
.endif

# Dependence lines for different Thunderbird versions
31_DEPENDS=		${LOCALBASE}/lib/thunderbird/thunderbird:${PORTSDIR}/mail/thunderbird

.else
IGNORE=	Unknown type of gecko dependency you may specify either libxul, firefox, seamonkey or thunderbird
.endif

.if defined(_GECKO_TYPE)
.if ${_GECKO_VERSION:M*+}
_GECKO_MIN_VERSION:=		${_GECKO_VERSION:S/+//}
_GECKO_WANTED_VERSIONS:=	${_GECKO_DEFAULT_VERSION}
.endif

.if ${_GECKO_VERSION:M[0-9][0-9]}
_GECKO_WANTED_VERSIONS:=	${_GECKO_VERSION:M[0-9][0-9]}
.endif

_GECKO_WANTED_VERSIONS?=	${_GECKO_DEFAULT_VERSION}

.if defined(_GECKO_MIN_VERSION)
.  for _v in _GECKO_VERSIONS
.    if ${_GECKO_MIN_VERSION} <= ${_v}
_GECKO_WANTED_VERSIONS+=	${_v}
.    endif
.  endfor
.endif

.for _v in ${_GECKO_WANTED_VERSIONS:O:u}
_GECKO_HIGHEST_VERSION:=	${_v}
.if defined(_GECKO_INSTALLED_VER) && ${_GECKO_INSTALLED_VER} == ${_v}
_GECKO_WANTED_VERSION:=	${_v}
.endif
.endfor

.if !defined(_GECKO_WANTED_VERSION)
.if defined(_GECKO_INSTALLED_VER)
IGNORE=	cannot install: ${_GECKO_TYPE} versions mismatch: ${_GECKO_TYPE}-${_GECKO_INSTALLED_VER} is installed and wanted version is ${_GECKO_TYPE}-${_GECKO_VERSION:M[0-9][0-9]}
.else
_GECKO_WANTED_VERSION:=	${_GECKO_HIGHEST_VERSION}
.endif
.endif


.if ${_GECKO_ARGS:Mbuild}
BUILD_DEPENDS+=	${${_GECKO_WANTED_VERSION}_DEPENDS}
.endif
RUN_DEPENDS+=	${${_GECKO_WANTED_VERSION}_DEPENDS}

.endif

.endif
