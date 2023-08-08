# handle dependency on the pkgconf port
#
# Feature:	pkgconfig
# Usage:	USES=pkgconfig or USES=pkgconfig:ARGS
# Valid ARGS:	build (default, implicit), run, both
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_PKGCONFIG_MK)
_INCLUDE_USES_PKGCONFIG_MK=	yes

_PKGCONFIG_DEPENDS=	pkgconf>=1.3.0_1:devel/pkgconf

.  if empty(pkgconfig_ARGS)
pkgconfig_ARGS=	build
.  endif

.  if ${pkgconfig_ARGS} == "build"
BUILD_DEPENDS+=	${_PKGCONFIG_DEPENDS}
CONFIGURE_ENV+=	PKG_CONFIG=pkgconf
.  elif ${pkgconfig_ARGS} == "run"
RUN_DEPENDS+=	${_PKGCONFIG_DEPENDS}
.  elif ${pkgconfig_ARGS} == "both"
CONFIGURE_ENV+=	PKG_CONFIG=pkgconf
BUILD_DEPENDS+=	${_PKGCONFIG_DEPENDS}
RUN_DEPENDS+=	${_PKGCONFIG_DEPENDS}
.  else
IGNORE=	USES=pkgconfig - invalid args: [${pkgconfig_ARGS}] specified
.  endif

_USES_POST+= pkgconfig
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_PKGCONFIG_POST_MK)
_INCLUDE_USES_PKGCONFIG_POST_MK=yes

# Provide a cooperative mechanism for managing PKG_CONFIG_PATH.
.  if defined(PKGCONFIG_PATHS)
.    if !${CONFIGURE_ENV:MPKG_CONFIG_PATH=*} && !${MAKE_ENV:MPKG_CONFIG_PATH=*}
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PKGCONFIG_PATHS:ts:}
MAKE_ENV+=	PKG_CONFIG_PATH=${PKGCONFIG_PATHS:ts:}
.    else
DEV_WARNING+=	"PKGCONFIG_PATHS was ignored due to conflict with CONFIGURE_ENV or MAKE_ENV"
.    endif
.  endif

.endif
