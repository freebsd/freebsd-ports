# $FreeBSD$
#
# vim: ts=8 noexpandtab
#
# Provide support to use Tcl/Tk
#
# MAINTAINER: tcltk@FreeBSD.org
#
#
# Variables set by this file:
#
# TCL_VER		- Major.Minor version of Tcl
#
# TCLSH			- Set to full path of the Tcl interpreter
#
# TCL_LIBDIR		- Path where the Tcl libraries can be found
#
# TCL_INCLUDEDIR	- Path where the Tcl C headers can be found
#
#
# TK_VER		- Major.Minor version of Tk
#
# WISH			- Set to full path of the Tk interpreter
#
# TK_LIBDIR		- Path where the Tk libraries can be found
#
# TK_INCLUDEDIR		- Path where the Tk C headers can be found
#
#
#
# Usage:
#
# USES+=	PORT[:(VERSION|wrapper),build,run]
#
# where PORT is one of:
#
# - tcl			- Depend on Tcl
# - tk			- Depend on both Tk and Tcl (Tk itself depends on Tcl)
#
# and VERSION is in one of the following formats:
#
# - (empty)		- Depend on any installed version of PORT. If none
#   			  is installed, bring in the default version. See
#   			  ${_TCLTK_DEFAULT_VERSION} below.
#
# - 84, 85, 86		- Depend on a specific version series of PORT.
#
# - 84+, 85+, 86+	- Depend on any installed version greater or equal to
#   			  the specified version.
#
# If wrapper is specified, an additional dependency on tcl-wrapper or
# tk-wrapper is added. It is NOT possible to select a specific version of
# Tcl/Tk when using the wrapper.
#
# Build-time / Run-time only dependencies can be specified with build or run.
#

.if !defined(_INCLUDE_USES_TCL_MK)
_INCLUDE_USES_TCL_MK=	yes

_TCLTK_VALID_VERSIONS=	84 85 86

.include "${PORTSDIR}/Mk/bsd.default-versions.mk"
_TCLTK_DEFAULT_VERSION=	${TCLTK_DEFAULT:S/.//}

.if ! ${_TCLTK_VALID_VERSIONS:M${_TCLTK_DEFAULT_VERSION}}
IGNORE=	Invalid tcltk version ${TCLTK_DEFAULT}
.endif

# _TCLTK_PORT might be set to tk if USES+= tk was used
_TCLTK_PORT?=	tcl

# Parse arguments
_TCL_ARGS=	${tcl_ARGS:S/,/ /g}

.if ${_TCL_ARGS:M*+}
#    using the ver+ variant
_TCLTK_MIN_VERSION:=	${_TCL_ARGS:M*+:S/+//}
_TCLTK_WANTED_VERSION:=	${_TCLTK_DEFAULT_VERSION}
.endif

.if ${_TCL_ARGS:M8[4-6]}
#    assume we specified a version
_TCLTK_WANTED_VERSION:=	${_TCL_ARGS:M8[4-6]}
.endif

.if ${_TCL_ARGS:Mwrapper} && defined(_TCLTK_WANTED_VERSION)
IGNORE=	USES=${_TCLTK_PORT}: it is not possible to specify both a version and the wrapper: ${tcl_ARGS}
.endif

.if !defined(_TCLTK_WANTED_VERSION)
_TCLTK_WANTED_VERSION=	${_TCLTK_DEFAULT_VERSION}
.endif

# check that the specified ver+ is valid
.if ! ${_TCLTK_VALID_VERSIONS:M${_TCLTK_WANTED_VERSION}}
IGNORE=	USES=${_TCLTK_PORT}: incorrect ${_TCLTK_PORT} version specified: ${_TCLTK_WANTED_VERSION}
.endif

.if defined(_TCLTK_MIN_VERSION)
.  for _v in ${_TCLTK_VALID_VERSIONS}
.    if ${_v} >= ${_TCLTK_MIN_VERSION} && exists(${LOCALBASE}/lib/lib${_TCLTK_PORT}${_v}.so)
_TCLTK_WANTED_VERSION=	${_v}
.    endif
.  endfor
.endif

#
# Exported variables
#
TCL_VER:=	${_TCLTK_WANTED_VERSION:S/8/8./}
TCL_SHLIB_VER:=	${_TCLTK_WANTED_VERSION}
TCLSH:=		${LOCALBASE}/bin/tclsh${TCL_VER}
TCL_LIBDIR:=	${LOCALBASE}/lib/tcl${TCL_VER}
TCL_INCLUDEDIR:=${LOCALBASE}/include/tcl${TCL_VER}

.if ${_TCLTK_PORT} == "tk"
TK_VER:=	${_TCLTK_WANTED_VERSION:S/8/8./}
TK_SHLIB_VER:=	${_TCLTK_WANTED_VERSION}
WISH:=		${LOCALBASE}/bin/wish${TCL_VER}
TK_LIBDIR:=	${LOCALBASE}/lib/tk${TK_VER}
TK_INCLUDEDIR:=	${LOCALBASE}/include/tk${TK_VER}
.endif

#
# Dependencies
#
_TCLTK_BUILD_DEPENDS=
_TCLTK_RUN_DEPENDS=
_TCLTK_LIB_DEPENDS=

# Construct the correct dependency lines (wrapper)
.if ${_TCL_ARGS:Mwrapper}
.  if ${_TCLTK_PORT} == "tcl"
_TCLTK_WRAPPER_PORT=	tclsh:${PORTSDIR}/lang/tcl-wrapper
.  elif ${_TCLTK_PORT} == "tk"
_TCLTK_WRAPPER_PORT=	wish:${PORTSDIR}/x11-toolkits/tk-wrapper
.  endif
.endif

# Construct the correct dependency lines (Tcl/Tk)
.  if ${_TCLTK_PORT} == "tcl"
_TCLTK_EXE_LINE=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${_TCLTK_WANTED_VERSION}
_TCLTK_LIB_LINE=	libtcl${TCL_SHLIB_VER}.so:${PORTSDIR}/lang/tcl${_TCLTK_WANTED_VERSION}
.  elif ${_TCLTK_PORT} == "tk"
_TCLTK_EXE_LINE=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${_TCLTK_WANTED_VERSION}
_TCLTK_LIB_LINE=	libtk${TK_SHLIB_VER}.so:${PORTSDIR}/x11-toolkits/tk${_TCLTK_WANTED_VERSION}
.endif

.if ${_TCL_ARGS:Mbuild}
BUILD_DEPENDS+=	${_TCLTK_WRAPPER_PORT} \
		${_TCLTK_EXE_LINE}
.elif ${_TCL_ARGS:Mrun}
RUN_DEPENDS+=	${_TCLTK_WRAPPER_PORT} \
		${_TCLTK_EXE_LINE}
.else
RUN_DEPENDS+=	${_TCLTK_WRAPPER_PORT}
LIB_DEPENDS+=	${_TCLTK_LIB_LINE}
.endif

.endif # defined(_INCLUDE_USES_TCL_MK)
