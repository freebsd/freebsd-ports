# -*- mode: Makefile; tab-width: 4; -*-
# ex: ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Tcl_Pre_Include)

Tcl_Pre_Include=		bsd.tcl.mk
Tcl_Include_MAINTAINER=		mm@FreeBSD.org

# USE_TCL		- Add library dependency on Tcl. If no version is given by the maintainer
#			  via the port or by the user via defined variable try to find the highest
#			  stable installed version.
#			  Available values: yes 86+ 85+ 84+ 83+ 82+ 85 84 83 82
#			  NOTE: - default value 85 is used in case of USE_TCL=yes
#
# USE_TCL_BUILD		- Add buildtime dependency on Tcl (tclsh).
#			  Available values: see USE_TCL
#			  NOTE: - has no effect if USE_TCL is defined
#
# USE_TCL_RUN		- Add runtime dependency on Tcl (tclsh).
#			  Available values: see USE_TCL
#			  NOTE: - has no effect if USE_TCL is defined
#				- value is implied by USE_TCL_BUILD (if defined)
#
# USE_TCL_WRAPPER	- Depend on the tclsh wrapper to run. Ports that do not explicitly require
#			  a specific tclsh version may use this.
#			  The tclsh wrapper script installs into ${LOCALBASE}/bin/tclsh
#			  NOTE: - USE_TCL_WRAPPER and USE_TCL can be used together
#			        - ports using the wrapper should support default Tcl (8.5)
##
# INVALID_TCL_VER	- This variable contains a list of Tcl versions not supported by the port.
#			  This setting is effective only when USE_TCL is set to a range (e.g. 83+)
# WITH_TCL_VER		- User defined global variable to set Tcl version
#			  This variable is effective only if USE_TCL is set to a range (e.g. 83+)
#			  and WITH_TCL_VER points inside that range.
#			  NOTE: INVALID_TCL_VER takes precedence
# <UNIQUENAME>_WITH_TCL_VER	- User defined port specific variable to set Tcl version
##
# USE_TCL_THREADS	- If defined, Tcl a threaded version of tcl is required.
#			  NOTE: support for threaded builds starts with version 84
# USE_TCL_NO_THREADS	- If defined, port may not use a threaded Tcl, even if requested via
#			  USE_TCL_THREADS or WITH_TCL_THREADS
# WITH_TCL_THREADS	- User defined variable to use Tcl with threads
# <UNIQUENAME>_WITH_TCL_THREADS	- User defined port specific variable to require Tcl with threads
##
# TCL_VER		- Detected by bsd.tcl.mk. Contains the version number of Tcl to be used.
#
##
# USE_TK		- Add library dependency on Tk. If no version is given by the maintainer
#			  via the port or by the user via defined variable try to find the highest
#			  stable installed version.
#			  Avaliable values: yes 86+ 85+ 84+ 83+ 82+ 85 84 83 82
#			  NOTE: - overrides USE_TCL
#			        - default value 85 is used in case of USE_TK=yes
#
# USE_TK_BUILD		- Add buildtime dependency on Tk (wish).
#			  Available values: see USE_TK
#			  NOTE: - has no effect if USE_TK is defined
#
# USE_TK_RUN		- Add runtime dependency on Tk (wish).
#			  Available values: see USE_TK
#			  NOTE: - has no effect if USE_TK is defined
#				- value is implied by USE_TK_BUILD (if defined)
#
# USE_TK_WRAPPER	- Depend on the wish wrapper to run. Ports that do not explicitly require
#			  a specific wish version may use this.
#			  The wish wrapper script installs into ${LOCALBASE}/bin/wish
#			  NOTE: - USE_TK_WRAPPER and USE_TK can be used together.
#			        - ports using the wrapper should support default Tk (8.5)
##
# INVALID_TK_VER	- This variable contains a list of Tk versions not supported by the port
#			  This setting is effective only when USE_TK is set to a range (e.g. 83+)
# WITH_TK_VER		- User defined global variable to set Tk version.
#			  This variable is effective only if USE_TK is set to a range (e.g. 83+)
#			  and WITH_TK_VER points inside that range.
#			  NOTE: overrides WITH_TCL_VER.
# <UNIQUENAME>_WITH_TK_VER	- User defined port specific variable to set Tk version
#			  NOTE: overrides <UNIQUENAME>_WITH_TCL_VER.
##
# USE_TK_THREADS	- Tk has to obey tcl in threads. A threaded Tk requires
#			  a threaded Tcl and a non-threaded Tcl requires a non-threaded Tk.
#			  This variable defines USE_TCL_THREADS
# USE_TK_NO_THREADS	- If defined, port may not use a threaded Tk, even if requested via
#			  USE_TK_THREADS or WITH_TK_THREADS. Defines USE_TCL_NO_THREADS
# WITH_TK_THREADS	- User defined variable to use Tk with threads
# <UNIQUENAME>_WITH_TK_THREADS	- User defined port specific variable to require Tk with threads
###
# TCL_LIBDIR		- Path where tcl libraries can be found
#
# TCL_INCLUDEDIR	- Path where tcl C headers can be found
##
# TK_LIBDIR		- Path where tk libraries can be found
#
# TK_INCLUDEDIR 	- Path where tk C headers can be found
##
# TCLSH			- Path to tclsh executable respecting Tcl version
#			  or to the tclsh wrapper if USE_TCL_WRAPPER is set
#
# WISH			- Path to wish executable respecting Tk version
#			  or to the wish wrapper if USE_TK_WRAPPER is set
#
##
# PATCH_TCL_SCRIPTS	- List of tcl scripts that need to be patched to replace
# 			  tclsh calls with tclsh${TK_VER} calls. Also note that
# 			  post-patch target is used.
#
# PATCH_TK_SCRIPTS	- List of tcl scripts that need to be patched to replace
# 			  wish calls with wish${TK_VER} calls. Also note that
# 			  post-patch target is used.

# Set RUN_DEPENDS for wrappers
. if defined(USE_TCL_WRAPPER)
RUN_DEPENDS+=		tclsh:${PORTSDIR}/lang/tcl-wrapper
. endif
. if defined(USE_TK_WRAPPER)
RUN_DEPENDS+=		wish:${PORTSDIR}/x11-toolkits/tk-wrapper
. endif

# Process USE_TCL_BUILD and USE_TCL_RUN
.if !defined(USE_TCL)
. if defined(USE_TCL_RUN)
USE_TCL:=	${USE_TCL_RUN}
_TCL_RUN_DEPENDS=	yes
. endif
. if defined(USE_TCL_BUILD)
USE_TCL:=	${USE_TCL_BUILD}
_TCL_BUILD_DEPENDS=	yes
. endif
.endif

# Process USE_TK_BUILD and USE_TK_RUN
.if !defined(USE_TK)
. if defined(USE_TK_RUN)
USE_TK:=	${USE_TK_RUN}
_TK_RUN_DEPENDS=	yes
. endif
. if defined(USE_TK_BUILD)
USE_TK:=	${USE_TK_BUILD}
_TK_BUILD_DEPENDS=	yes
. endif
.endif

# Set WITH_TCL_THREADS or WITH_TK_THREADS if port-specific define
. if defined(${UNIQUENAME:U:S,-,_,}_WITH_TCL_THREADS)
WITH_TCL_THREADS=	yes
. endif
. if defined(${UNIQUENAME:U:S,-,_,}_WITH_TK_THREADS)
WITH_TK_THREADS=	yes
.endif

# If a threaded Tcl or Tk is requested we require a threaded Tcl
. if !defined(USE_TK_NO_THREADS) && !defined(USE_TCL_NO_THREADS)
.  if defined(USE_TCL_THREADS) || defined(USE_TK_THREADS)
USE_TCL_THREADS=	yes
.  endif
.  if defined(WITH_TK_THREADS)
WITH_TCL_THREADS=	${WITH_TK_THREADS}
.  endif
. endif

# Override the global WITH_TCL_VER or WITH_TK_VER with the
# port specific <UNIQUENAME>_WITH_TCL_VER or <UNIQUENAME>_WITH_TK_VER
. if defined(${UNIQUENAME:U:S,-,_,}_WITH_TCL_VER)
WITH_TCL_VER:=	${${UNIQUENAME:U:S,-,_,}_WITH_TCL_VER}
. endif
. if defined(${UNIQUENAME:U:S,-,_,}_WITH_TK_VER)
WITH_TK_VER:=	${${UNIQUENAME:U:S,-,_,}_WITH_TK_VER}
. endif

# If USE_TK, WITH_TK_VER, INVALID_TK_VER is defined,
# set USE_TCL, WITH_TCL_VER, INVALID_TCL_VER to identical values
# we require the same version of Tcl for Tk
. if defined(USE_TK)
.  if !defined(USE_TCL)
_TK_ONLY=	yes
.  endif
USE_TCL:=	${USE_TK}
. endif
. if defined(WITH_TK_VER)
WITH_TCL_VER:=	${WITH_TK_VER}
. endif
. if defined(INVALID_TK_VER)
INVALID_TCL_VER:=	${INVALID_TK_VER}
. endif

#
# Tcl part
#
. if defined(USE_TCL)

_TCL_DEFAULT_VERSION=		85
_TCL_VERSIONS=			86 85 84 83 82
_TCL_THREADS_VERSIONS=		86 85 84
_TCL_RANGE_VERSIONS= 		86+ 85+ 84+ 83+ 82+
_TCL_THREADS_RANGE_VERSIONS=	86+ 85+ 84+

# For specifying [85, 84, ..]+
_TCL_82P=	82 83 84 85 86
_TCL_83P=	83 84 85 86
_TCL_84P=	84 85 86
_TCL_85P=	85 86
_TCL_86P=	86

# Set the default Tcl version and check if USE_TCL=yes was given
.  if ${USE_TCL} == "yes"
USE_TCL=	${_TCL_DEFAULT_VERSION}
.  endif

# Support for obsolete 84-thread and 85-thread definitions
.  if ${USE_TCL} == "84-thread" || ${USE_TCL} == "85-thread"
USE_TCL:=		${USE_TCL:S/-thread//}
USE_TCL_THREADS=	yes
.  endif

# Ignore WITH_TCL_THREADS if USE_TCL is
# not in _TCL_THREADS_VERSIONS or _TCL_RANGE_VERSIONS
.  if defined(WITH_TCL_THREADS)
.   for ver in ${_TCL_THREADS_VERSIONS} ${_TCL_RANGE_VERSIONS}
.    if ${USE_TCL} == "${ver}"
USE_TCL_THREADS=	yes
.    endif
.   endfor
.  endif

# Check if a build with threads is required
.  if !defined(USE_TCL_NO_THREADS) && !defined(USE_TK_NO_THREADS) && !defined(BUILDING_TCL_THREADS) && !defined(BUILDING_TK_THREADS)
.   if defined(USE_TCL_THREADS)
_TCL_THREADS_PORT=	-thread
_TCL_THREADS_SUFFIX=	-threads

# Threaded Tcl/Tk accepts only ranges starting with 84+
# reset the range to 84+ if the value is lower
.    for ver in ${_TCL_RANGE_VERSIONS}
.     if ${USE_TCL} == "${ver}"
_TCL_T_BAD_RANGE=	yes
.      for tver in ${_TCL_THREADS_RANGE_VERSIONS}
.       if ${USE_TCL} == "${tver}"
_TCL_T_BAD_RANGE=	no
.       endif
.      endfor
.     endif
.    endfor
.    if defined(_TCL_T_BAD_RANGE) && ${_TCL_T_BAD_RANGE} == "yes"
USE_TCL=	84+
.    endif

.   endif
. endif

_TCL_VER=	no

# Check if we have user-defined WITH_TCL_VER and if it matches
# the range specified in port's USE_TCL or USE_TK
.  if defined(WITH_TCL_VER)
.   for ver in ${_TCL_RANGE_VERSIONS}
.    if ${USE_TCL} == "${ver}" && ${_TCL_VER} == "no"
_MATCHED_TCL_VER:=	${USE_TCL:S/+//}
.     for tcl in ${_TCL_${_MATCHED_TCL_VER}P}
.      if ${WITH_TCL_VER} == ${tcl}
#  Check if user supplied WITH_TCL is in the INVALID_TCL_VER list
_BRKTCL=	no
.       for iver in ${INVALID_TCL_VER}
.        if ${WITH_TCL_VER} == ${iver}
_BRKTCL=	yes
.	 endif
.       endfor
#  If WITH_TCL is not in the INVALID_TCL_VER list, use it
#  otherwise take default from port
.       if ${_BRKTCL} == "no"
_TCL_VER=	${WITH_TCL_VER}
USE_TCL=	${_TCL_VER}
.       endif
.      endif
.     endfor
.    endif
.   endfor
.  endif

# Check for highest installed Tcl (if e.g. 83+ is specified)
# The default version of Tcl counts as the highest
.  if ${_TCL_VER} == "no"
.   for ver in ${_TCL_RANGE_VERSIONS}
.    if ${USE_TCL} == "${ver}" && ${_TCL_VER} == "no"
_MATCHED_TCL_VER:=	${USE_TCL:S/+//}
.     for tcl in ${_TCL_${_MATCHED_TCL_VER}P}
#  Skip versions we are incompatible with
_BRKTCL=	no
.      for iver in ${INVALID_TCL_VER}
_INVALID_VER=	${iver}
.       if ${_INVALID_VER} == ${tcl}
_BRKTCL=	yes
.	endif
.      endfor
.      if ${_BRKTCL} == "no"
#  We have matched a supported version
_TCL_VER_MATCH=${tcl}
#  Check if the default version is supported
.	if ${_TCL_VER_MATCH} == ${_TCL_DEFAULT_VERSION}
_TCL_SUPPORT_DEFAULT=	yes
.	endif
#  Look for installed versions
.       if exists(${LOCALBASE}/include/tcl${tcl:S/8/8./}/tcl.h)
_TCL_INST_VER=${tcl}
#  Check if the default version is installed
.        if ${_TCL_INST_VER} == ${_TCL_DEFAULT_VERSION}
_TCL_HAVE_DEFAULT=	yes
.        endif
.	endif
.      endif
.     endfor
.    endif
.   endfor
.   if defined(_MATCHED_TCL_VER)
.    if defined(_TCL_INST_VER)
#  Default version is installed
.     if defined(_TCL_HAVE_DEFAULT)
USE_TCL=	${_TCL_DEFAULT_VERSION}
.     else
#  Default version is not installed, but another supported version is installed
USE_TCL=	${_TCL_INST_VER}
.     endif
#  No supported version is installed, we want to install the default version
.    elif defined(_TCL_SUPPORT_DEFAULT)
USE_TCL=	${_TCL_DEFAULT_VERSION}
.    elif defined(_TCL_VER_MATCH)
#  Default version is not wanted, select next best match
USE_TCL=	${_TCL_VER_MATCH}
.    else
#  INVALID_[TCL|TK]_VER removes all choices from the USE_[TCL|TK] range
IGNORE=		selection of a Tcl/Tk version is not possible. Please check USE_[TCL|TK] and INVALID_[TCL|TK]_VER
.    endif
.   endif
.  endif

TCL_VER:=	${USE_TCL:S/8/8./}

# Check if a correct Tcl/Tk version was specified
_FOUND=		no
.  for ver in ${_TCL_VERSIONS}
.   if ${USE_TCL} == "${ver}" && ${_FOUND} == "no"
_FOUND=		yes
.   endif
.  endfor

.  if ${_FOUND} == "yes" && defined(USE_TCL_THREADS)
_FOUND=		no
_THREADED_NOT_FOUND=	yes
.   for ver in ${_TCL_THREADS_VERSIONS}
.    if ${USE_TCL} == "${ver}" && ${_FOUND} == "no"
_FOUND=		yes
.    endif
.   endfor
.  endif

.  if ${_FOUND} == "yes"

TCL_INCLUDEDIR=		${LOCALBASE}/include/tcl${TCL_VER}
TCL_LIBDIR=		${LOCALBASE}/lib/tcl${TCL_VER}${_TCL_THREADS_SUFFIX}
TCLSH=			${LOCALBASE}/bin/tclsh${TCL_VER}${_TCL_THREADS_SUFFIX}

# Add dependencies
.   if !defined(_TK_ONLY)
.    if !defined(_TCL_RUN_DEPENDS) && !defined(_TCL_BUILD_DEPENDS)
LIB_DEPENDS+=	tcl${USE_TCL}${_TCL_THREADS_SUFFIX}:${PORTSDIR}/lang/tcl${USE_TCL}${_TCL_THREADS_PORT}
.    else
.     if defined(_TCL_BUILD_DEPENDS)
BUILD_DEPENDS+=	tclsh${TCL_VER}${_TCL_THREADS_SUFFIX}:${PORTSDIR}/lang/tcl${USE_TCL}${_TCL_THREADS_PORT}
.     endif
.     if defined(_TCL_RUN_DEPENDS)
RUN_DEPENDS+=	tclsh${TCL_VER}${_TCL_THREADS_SUFFIX}:${PORTSDIR}/lang/tcl${USE_TCL}${_TCL_THREADS_PORT}
.     endif
.    endif
.   endif

.  elif defined(_THREADED_NOT_FOUND) && !defined(IGNORE)
IGNORE=		the defined version of Tcl/Tk does not support threads: ${USE_TCL}
.  elif !defined(IGNORE)
IGNORE=		unknown Tcl/Tk version specified: ${USE_TCL}
.  endif

#
# Tk part
#
.  if defined(USE_TK)

# We now read the version numbers from the Tcl part
USE_TK:=	${USE_TCL}
TK_VER:=	${USE_TCL:S/8/8./}

.   if !defined(_TK_RUN_DEPENDS) && !defined(_TK_BUILD_DEPENDS)
LIB_DEPENDS+=	tk${USE_TK}${_TCL_THREADS_SUFFIX}:${PORTSDIR}/x11-toolkits/tk${USE_TK}${_TCL_THREADS_PORT}
.   else
.    if defined(_TK_BUILD_DEPENDS)
BUILD_DEPENDS+=	wish${TK_VER}${_TCL_THREADS_SUFFIX}:${PORTSDIR}/x11-toolkits/tk${USE_TK}${_TCL_THREADS_PORT}
.    endif
.    if defined(_TK_RUN_DEPENDS)
RUN_DEPENDS+=	wish${TK_VER}${_TCL_THREADS_SUFFIX}:${PORTSDIR}/x11-toolkits/tk${USE_TK}${_TCL_THREADS_PORT}
.    endif
.   endif

TK_INCLUDEDIR=		${LOCALBASE}/include/tk${TK_VER}
TK_LIBDIR=		${LOCALBASE}/lib/tk${TK_VER}${_TCL_THREADS_SUFFIX}
WISH=			${LOCALBASE}/bin/wish${TK_VER}${_TCL_THREADS_SUFFIX}

.  endif # defined(USE_TK)
. endif # defined(USE_TCL)

# (Re)set WISH and TCLSH to the wrapper, if defined
. if defined(USE_TCL_WRAPPER)
TCLSH=			${LOCALBASE}/bin/tclsh
. endif
. if defined(USE_TK_WRAPPER)
WISH=			${LOCALBASE}/bin/wish
. endif

.endif # !defined(_POSTMKINCLUDED) && !defined(Tcl_Pre_Include)

.if defined(_POSTMKINCLUDED) && !defined(Tcl_Post_Include)

Tcl_Post_Include=	bsd.tcl.mk

. if defined(PATCH_TCL_SCRIPTS) || defined (PATCH_TK_SCRIPTS)
.  if !target(post-patch)
post-patch:
.   if defined(PATCH_TCL_SCRIPTS) && defined(TCLSH)
.    for tcl_script in ${PATCH_TCL_SCRIPTS}
	@${REINPLACE_CMD} -e 's,tclsh,${TCLSH},' ${WRKSRC}/${tcl_script}
.    endfor
.   endif
.   if defined(PATCH_TK_SCRIPTS) && defined(WISH)
.    for tk_script in ${PATCH_TK_SCRIPTS}
	@${REINPLACE_CMD} -e 's,wish,${WISH},' ${WRKSRC}/${tk_script}
.    endfor
.   endif
.  endif # !target(post-patch)
. endif # defined(PATCH_TCL_SCRIPTS) || defined (PATCH_TK_SCRIPTS)
.endif # defined(_POSTMKINCLUDED) && !defined(Tcl_Post_Include)
