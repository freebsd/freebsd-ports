# vim: ts=8 noexpandtab
#
# Provide support to use Tcl/Tk
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
# TCL_PKG_LIB_PREFIX    - Library prefix, as per TIP595. This is tcl9 when
#			  when building against Tcl 9.x, and empty otherwise
#
# TCL_PKG_STUB_POSTFIX  - Stub library postfix. This is empty when building
#			  against Tcl 9.x, and DISTVERSION otherwise.
#			  See https://core.tcl-lang.org/tclconfig/info/381985d331b96ba9
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
# USES+=	PORT[:(VERSION|wrapper),build,run,tea,test]
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
# - 86 			- Depend on Tcl/Tk 8.6 specifically.
# - 91 			- Depend on Tcl/Tk 9.1 specifically.
#
#
# If wrapper is specified, an additional dependency on tcl-wrapper or
# tk-wrapper is added. It is NOT possible to select a specific version of
# Tcl/Tk when using the wrapper.
#
# Build-time / Run-time / Test-time only dependencies can be specified with
# build, run or test.
#
# Tea can be used for Tcl/Tk extensions that use the Tcl Extension Architecture
# [http://www.tcl.tk/doc/tea] and allows to set common autoconf parameters.
#
# MAINTAINER: tcltk@FreeBSD.org

.if ${USES:Mtk} || ${USES:Mtk\:*}
.  if !defined(_TCLTK_PORT)
_TCLTK_IGNORE=	yes
.  endif
.endif

.if !defined(_INCLUDE_USES_TCL_MK) && !defined(_TCLTK_IGNORE)
_INCLUDE_USES_TCL_MK=	yes

#
# List the currently available versions.
#
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
_TCLTK_VALID_VERSIONS=	86 91

#
# Bring in the default and check that the specified version is in the list of
# valid versions.
#
_TCLTK_DEFAULT_VERSION=	${TCLTK_DEFAULT:S/.//}
.  if ! ${_TCLTK_VALID_VERSIONS:M${_TCLTK_DEFAULT_VERSION}}
IGNORE=	Invalid tcltk version ${TCLTK_DEFAULT}
.  endif

#
# _TCLTK_PORT tells us whether we're depending on Tcl or Tk. When using
# USES+=tk, the included file tk.mk sets this before including this file.
#
_TCLTK_PORT?=	tcl

#
# Parse one or more ver arguments.
#
.  if ${tcl_ARGS:M86}
_TCLTK_WANTED_VERSION:=${tcl_ARGS:M86}
.  endif

.  if ${tcl_ARGS:M91}
_TCLTK_WANTED_VERSION:=${tcl_ARGS:M91}
.  endif


#
# It makes little sense to specify both the wrapper and a specific version.
#
.  if ${tcl_ARGS:Mwrapper} && defined(_TCLTK_WANTED_VERSION)
IGNORE=	USES=${_TCLTK_PORT}: it is not possible to specify both a version and the wrapper: ${tcl_ARGS}
.  endif

#
# If no version was specified, set the default version.
#
.  if !defined(_TCLTK_WANTED_VERSION)
_TCLTK_WANTED_VERSION=	${_TCLTK_DEFAULT_VERSION}
.  endif

#
# Resolve the port suffix
.  if ${_TCLTK_WANTED_VERSION} == "86"
_TCLTK_PORT_SUFFIX=86
.  endif

#
# Exported variables
#
TCL_VER:=	${_TCLTK_WANTED_VERSION:S/8/8./:S/9/9./}
TCL_SHLIB_VER:=	${_TCLTK_WANTED_VERSION:S/9/9./}
TCLSH:=		${LOCALBASE}/bin/tclsh${TCL_VER}
TCL_LIBDIR:=	${LOCALBASE}/lib/tcl${TCL_VER}
TCL_INCLUDEDIR:=${LOCALBASE}/include/tcl${TCL_VER}

.  if ${_TCLTK_PORT} == "tk"
TK_VER:=	${TCL_VER}
TK_SHLIB_VER:=	${TCL_SHLIB_VER}
WISH:=		${LOCALBASE}/bin/wish${TCL_VER}
TK_LIBDIR:=	${LOCALBASE}/lib/tk${TCL_VER}
TK_INCLUDEDIR:=	${LOCALBASE}/include/tk${TCL_VER}
.  endif

# Construct the correct dependency lines (wrapper)
.  if ${tcl_ARGS:Mwrapper}
.    if ${_TCLTK_PORT} == "tcl"
_TCLTK_WRAPPER_PORT=	tclsh:lang/tcl-wrapper
.    elif ${_TCLTK_PORT} == "tk"
_TCLTK_WRAPPER_PORT=	wish:x11-toolkits/tk-wrapper
.    endif
.  endif

# Construct the correct dependency lines (Tcl/Tk)
.  if ${_TCLTK_PORT} == "tcl"
_TCLTK_EXE_LINE=	tclsh${TCL_VER}:lang/tcl${_TCLTK_PORT_SUFFIX}
_TCLTK_LIB_LINE=	libtcl${TCL_SHLIB_VER}.so:lang/tcl${_TCLTK_PORT_SUFFIX}
.  elif ${_TCLTK_PORT} == "tk"
_TCLTK_EXE_LINE=	wish${TCL_VER}:x11-toolkits/tk${_TCLTK_PORT_SUFFIX}
_TCLTK_LIB_LINE=	libtk${TCL_SHLIB_VER}.so:x11-toolkits/tk${_TCLTK_PORT_SUFFIX} \
			libtcl${TCL_SHLIB_VER}.so:lang/tcl${_TCLTK_PORT_SUFFIX}
.  endif

.undef _TCLTK_DEPENDS_FOUND
.  if ${tcl_ARGS:Mbuild}
BUILD_DEPENDS+=		${_TCLTK_WRAPPER_PORT} ${_TCLTK_EXE_LINE}
_TCLTK_DEPENDS_FOUND=	yes
.  endif
.  if ${tcl_ARGS:Mrun}
RUN_DEPENDS+=		${_TCLTK_WRAPPER_PORT} ${_TCLTK_EXE_LINE}
_TCLTK_DEPENDS_FOUND=	yes
.  endif
.  if ${tcl_ARGS:Mtest}
TEST_DEPENDS+=		${_TCLTK_WRAPPER_PORT} ${_TCLTK_EXE_LINE}
_TCLTK_DEPENDS_FOUND=	yes
.  endif
.  if !defined(_TCLTK_DEPENDS_FOUND)
RUN_DEPENDS+=	${_TCLTK_WRAPPER_PORT}
LIB_DEPENDS+=	${_TCLTK_LIB_LINE}
.  endif
.undef _TCLTK_DEPENDS_FOUND

# Setup TEA stuff
.  if ${tcl_ARGS:Mtea}
GNU_CONFIGURE=	yes
TCL_PKG?=	${PORTNAME:C/^tcl(-?)//:C/(-?)tcl\$//}${PORTVERSION}
.    if ${TCL_VER} == "9.1"
TCL_PKG_LIB_PREFIX=	tcl9
TCL_PKG_STUB_POSTFIX=	
.    else
TCL_PKG_LIB_PREFIX=	
TCL_PKG_STUB_POSTFIX=	${DISTVERSION}
.    endif
PLIST_SUB+=	TCL_PKG=${TCL_PKG} TCL_PKG_LIB_PREFIX=${TCL_PKG_LIB_PREFIX} \
		TCL_PKG_STUB_POSTFIX=${TCL_PKG_STUB_POSTFIX}
CONFIGURE_ARGS+=--exec-prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
.    if ${_TCLTK_PORT} == "tk"
CONFIGURE_ARGS+=--with-tk=${TK_LIBDIR} --with-tkinclude=${TK_INCLUDEDIR}
.    endif
.  endif

.endif # defined(_INCLUDE_USES_TCL_MK)

.undef _TCLTK_IGNORE
