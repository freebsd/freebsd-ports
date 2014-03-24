#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# bsd.wx.mk - Support for wxWidgets based ports.
#
# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
#
# Please view me with 4 column tabs!
#
# The following variables can be defined in a port that uses the wxWidgets
# library, contributed libraries, WxPython and/or more wxWidgets related
# components (with run and/or build dependencies). It can be used after and/or
# before bsd.port.pre.mk, but Python components will only work if Python
# variables (e.g. USE_PYTHON) are defined before it (this is a bsd.python.mk
# limitation), at least it is manually included.
# USE_WX		- Set to the list of wxWidgets versions that can be used by
#				  the port. The syntax allows the following elements:
#				  - Single version (e.g. "3.0").
#				  - Range of versions (e.g. "2.8-3.0"). Must be ascending.
#				  - Partial range: single version and upper (e.g. "2.8+").
#				  - Partial range: single version and lower (e.g. "-2.8").
#				  Multiple elements can be specified separated by spaces.
# USE_WX_NOT	- Set to the list of wxWidgets versions that can't be used by
#				  the port. In other words, it removes some versions from
#				  USE_WX. If the latter is not defined, it will have the value
#				  of all the possible versions. The syntax is like USE_WX.
# WX_COMPS		- Set to the list of wxWidgets components the port uses.
#				  Several components can be specified separated by spaces. By
#				  default it will have the value of "wx". Suffixes in the form
#				  ":xxx" may be added to the components to determine the
#				  dependency type.
#				  The available components are:
#				  wx			- The wxWidgets library.
#				  contrib		- The wxWidgets contributed libraries.
#				  python		- The wxWidgets API for Python.
#				  svg			- WxSVG (only for 2.8).
#				  The available dependency types are:
#				  build			- Requires component for building.
#				  lib			- Requires component for building and running.
#				  run			- Requires component for running.
#				  If no suffix is present then "run" will be used for "python"
#				  and "lib" for others.
# WX_CONF_ARGS	- Set to "absolute" or "relative" if the port needs configure
#				  arguments in addition to the WX_CONFIG environment variable.
#				  It determines the type of parameters that have to be passed
#				  to the configure script. In the first case it adds
#				  "--with-wx-config=${WX_CONFIG}" (absolute path of
#				  WX_CONFIG), and in second one "--with-wx=${LOCALBASE}" plus
#				  "--with-wx-config=${WX_CONFIG:T} (prefix and name).
# WX_PREMK		- Define to determine version and define WX_CONFIG/WX_VERSION
#				  after <bsd.port.pre.mk> (in case the port needs to manually run
#				  the script).
# WX_UNICODE	- Define if the port needs the Unicode version of the
#				  wxWidgets library and/or contributed libraries.
#				  NOTE: this should NOT be used for ports that can be compiled
#				  with Unicode or not, but for the ones that require it.
# WANT_UNICODE	- Define if the port prefers Unicode, but doesn't require it.
# WANT_WX		- Set to "yes" or a valid single version (no ranges, etc).
#				  In both cases it will detect the installed wxWidgets
#				  components and add them to the variable HAVE_WX. If a
#				  version is selected, HAVE_WX will contain a list of
#				  components in the other case it will contain a list of
#				  "component-version" pairs (e.g. wx-2.8, contrib-2.8, etc).
#				  It has to be used before bsd.port.pre.mk.
# WANT_WX_VER	- Set to the prefered wxWidgets version for the port. It must
#				  be present in USE_WX or missing in USE_WX_NOT. This is
#				  overriden by the user variable WITH_WX_VER if set. It can
#				  contain multiple versions in order of preference (last ones
#				  are tried first).
#
# The following variables are intended for the user and can be defined in
# make.conf.
# WITH_UNICODE	- Define if you prefer the Unicode version when available.
# WITHOUT_UNICODE
#				- Define if you prefer the non Unicode version (this
#				  variable disables WITH_UNICODE and WANT_UNICODE).
# WITH_WX_VER	- Define to the list of prefered versions in reverse order.
#
# The following variables are defined by this file, to be read from the port.
# WX_CONFIG		- The path to the wx-config program (with different name).
# WXRC_CMD		- The path to the wxrc program (with different name).
# WX_VERSION	- The wxWidgets version that is going to be used.
# WX_UNICODE	- If this variable is not defined by the port (which means it
#				  requires the Unicode version of wxWidgets), it will be
#				  defined in the case the Unicode version is used (enabled by
#				  WITH_UNICODE or WANT_UNICODE).
# HAVE_WX		- The list of wxWidgets components installed, if WANT_WX was
#				  defined. The components will have version suffix if it was
#				  set to "yes".
#
# Examples:
# - A port that needs wxWidgets 2.8 and contributed libraries with Unicode.
#	USE_WX=		2.8
#	WX_COMPS=	wx contrib
#	WX_UNICODE=	yes
# - A port that needs WxPython 2.8 for running.
#	USE_PYTHON=	yes
#	USE_WX=		2.8
#	WX_COMPS=	python:run
# - A port that needs WxPython 2.8 or 3.0 for building.
#	USE_PYTHON=	yes
#	USE_WX=		2.8 3.0
#	WX_COMPS=	python:build
# - A port that needs wxWidgets version 2.8 or higher and contributed
#	libraries.
#	USE_WX=		2.8+
#	WX_COMPS=	wx contrib
# - A port that needs wxWidgets of any version other than 2.8.
#	USE_WX_NOT=	2.8
#

WX_Include_MAINTAINER=	alepulver@FreeBSD.org

#
# Global definitions.
#

.if !defined(_WX_Definitions_Done)
_WX_Definitions_Done=	yes

#
# Common variables:
# _WX_COMPS_ALL			- List of valid components.
# _WX_DEP_TYPES_ALL		- List of valid dependency types.
# _WX_VERS_ALL			- List of supported versions.
# _WX_VERS_UC_ALL		- List of Unicode capable versions.
# _WX_VERS_LISTS		- Reverse lists preference order.
#

_WX_COMPS_ALL=			wx contrib python svg
_WX_DEP_TYPES_ALL=		build lib run
_WX_VERS_ALL=			2.8 2.9 3.0
_WX_VERS_UC_ALL=		2.8 2.9 3.0
_WX_VERS_SKIP=			2.9 3.0
_WX_VERS_LISTS=			WANT_WX_VER WITH_WX_VER _WX_VER_INSTALLED

#
# Variables used to determine what is needed:
# _WX_PORT_comp_ver		- Port directory.
# _WX_LIB_comp_ver		- Name of the shared library (optional).
# _WX_SHVER_comp_ver	- Shared library version (optional).
# _WX_FILE_comp_ver		- File installed by that component.
# _WX_DEPTYPE_comp_ver	- Default dependency type (optional).
#

# wxgtk 2.8
_WX_PORT_wx_2.8=		x11-toolkits/wxgtk28${_WX_UCL}
_WX_LIB_wx_2.8=			wx_base${_WX_UC}-2.8

_WX_PORT_contrib_2.8=	x11-toolkits/wxgtk28${_WX_UCL}-contrib
_WX_LIB_contrib_2.8=	wx_gtk2${_WX_UC}_fl-2.8

_WX_PORT_python_2.8=	x11-toolkits/py-wxPython28${_WX_UCL}
_WX_FILE_python_2.8=	${PYTHON_SITELIBDIR}/wx-2.8-gtk2${_WX_PYSUFX}/wx/__init__.py

_WX_PORT_svg_2.8=		graphics/wxsvg
_WX_LIB_svg_2.8=		wxsvg

# wxgtk 2.9
_WX_PORT_wx_2.9=		x11-toolkits/wxgtk29
_WX_LIB_wx_2.9=			wx_baseu-2.9

# wxgtk 3.0
_WX_PORT_wx_3.0=		x11-toolkits/wxgtk30
_WX_LIB_wx_3.0=			wx_baseu-3.0

# Set _WX_SHVER_comp_ver to 0 and _WX_FILE_comp_ver for libs appropiately.
# Set _WX_DEPTYPE_comp_ver for "python" to "run", and others to "lib".

.	for comp in ${_WX_COMPS_ALL}
_WX_COMP=				${comp}
.		for ver in ${_WX_VERS_ALL}
.			if defined(_WX_LIB_${comp}_${ver})
_WX_SHVER_${comp}_${ver}=	0
_WX_FILE_${comp}_${ver}=	${LOCALBASE}/lib/lib${_WX_LIB_${comp}_${ver}}.so.${_WX_SHVER_${comp}_${ver}}
.			endif
.			if ${_WX_COMP} == "python"
_WX_DEPTYPE_${comp}_${ver}=	run
.			else
_WX_DEPTYPE_${comp}_${ver}=	lib
.			endif
.		endfor
.	endfor
.endif		# !_WX_Defined_Done

#
# Check if the user/port wants Unicode.
#

.if (!defined(WITHOUT_UNICODE) && \
    (defined(WITH_UNICODE) || defined(WANT_UNICODE)))
_WX_UC_AVAILABLE=			yes
.else
.	undef _WX_UC_AVAILABLE
.endif

#
# Check if we are going to determine the version.
#

.if !defined(_WX_Version_Done) && (defined(_POSTMKINCLUDED) || \
    (defined(WX_PREMK) && defined(BEFOREPORTMK) && \
    (defined(USE_WX) || defined(USE_WX_NOT))))
_WX_Need_Version=			yes
.endif

#
# Check for present components.
#

# Requested by the user.

.if defined(WANT_WX) && defined(BEFOREPORTMK)
_WANT_WX=				${WANT_WX}
.endif

# Used for autodetection of installed versions.

.if defined(_WX_Need_Version)
_WANT_WX=				yes
.endif

.if defined(_WANT_WX)

# Check if Unicode will be used.

.	for __WANT_WX in ${_WANT_WX}
.		if defined(_WX_UC_AVAILABLE) && \
		   (${_WX_VERS_UC_ALL:M${__WANT_WX}} != "" || ${_WANT_WX:L} == "yes")
_WX_WANT_UNICODE=		yes
.		endif
.	endfor

# These variables are reprocessed later so they won't affect other parts.

.	if defined(WX_UNICODE) || defined(_WX_WANT_UNICODE)
_WX_VER_FINAL=			${_WX_VERS_UC_ALL}
_WX_UC=					u
_WX_UCL=				-unicode
_WX_PYSUFX=				-unicode
.	else
_WX_VER_FINAL=			${_WX_VERS_ALL}
_WX_UC=					#
_WX_UCL=				#
_WX_PYSUFX=				-ansi
.	endif

# Fill _HAVE_WX with the installed components.

.	undef _HAVE_WX
.	for __WANT_WX in ${_WANT_WX}
# Check if _WANT_WX contains more than one word.
.		if defined(_HAVE_WX)
IGNORE?=				selected multiple values for WANT_WX: ${_WANT_WX}
.		endif
_HAVE_WX=				#
# Check for all versions.
.		if ${_WANT_WX:L} == "yes"
.			for comp in ${_WX_COMPS_ALL}
.				for ver in ${_WX_VER_FINAL}
_WX_COMP=				_WX_FILE_${comp}_${ver}
.					if defined(${_WX_COMP}) && exists(${${_WX_COMP}})
_HAVE_WX+=				${comp}-${ver}
.					endif
.				endfor
.			endfor
# Check for a specific version.
.		elif ${_WX_VERS_ALL:M${__WANT_WX}}
.			for comp in ${_WX_COMPS_ALL}
.				if exists(${_WX_FILE_${comp}_${__WANT_WX}})
_HAVE_WX+=				${comp}
.				endif
.			endfor
.		else
IGNORE?=				selected an invalid value for WANT_WX: ${__WANT_WX}
.		endif
.	endfor
.endif		# _WANT_WX

# Requested by the user.

.if defined(WANT_WX) && defined(BEFOREPORTMK)
HAVE_WX:=				${_HAVE_WX}
.endif

# Used for autodetection of installed versions.

.if defined(_WX_Need_Version)
_WX_VER_INSTALLED:=		${_HAVE_WX:Mwx-*:S/wx-//}
.endif

#
# Select wxWidgets version.
#

.if defined(_WX_Need_Version)
_WX_Version_Done=		yes

#
# Basic component parsing (ignores dependency types).
#
# The variables used are:
# _WX_COMP				- Component part.
# _WX_COMPS_FINAL		- Final list of components.
#

# Detect duplicated components.

_WX_COMPS_FINAL=		#
.for comp in ${WX_COMPS}
_WX_COMP=				${comp:C/:([[:alpha:]]+)$//}
.	for __WX_COMP in ${_WX_COMP}
.		if ${_WX_COMPS_ALL:M${__WX_COMP}} == ""
IGNORE?=				selected an invalid wxWidgets component: ${__WX_COMP}
.		endif
.	endfor
.	for newcomp in ${_WX_COMP}
.		if ${_WX_COMPS_FINAL:M${newcomp}} == "" && !defined(IGNORE)
_WX_COMPS_FINAL+=		${newcomp}
.		endif
.	endfor
.endfor

# Set defaults (if one isn't present).

USE_WX?=				${_WX_VERS_ALL}
USE_WX_NOT?=			#

#
# Make lists of valid and invalid versions.
#
# The following variables are used:
# _WX_VER_CHECK			- If the version is a single one, express in a range.
# _WX_VER_MIN			- Lower version of the range.
# _WX_VER_MAX			- Higher version of the range.
# _WX_VER_LIST			- List of requested versions.
# _WX_VER_NOT_LIST		- List of disallowed versions.
# _WX_VER_MERGED		- List of requested version without disallowed ones.
#

.for list in VER VER_NOT
_WX_${list}_LIST=		#
.	for ver in ${USE_WX${list:C/VER//}}
_WX_VER_CHECK:=			${ver:C/^([[:digit:]]+(\.[[:digit:]]+)*)$/\1-\1/}
_WX_VER_MIN:=			${_WX_VER_CHECK:C/([[:digit:]]+(\.[[:digit:]]+)*)[-+].*/\1/}
_WX_VER_MAX:=			${_WX_VER_CHECK:C/.*-([[:digit:]]+(\.[[:digit:]]+)*)/\1/}
# Minimum version not specified.
.		if ${_WX_VER_MIN} == ${_WX_VER_CHECK}
.			undef _WX_VER_MIN
.			for v in ${_WX_VERS_ALL}
.				if ${_WX_VER_CHECK:C/[-+]//} == ${v} || ${_WX_VERS_SKIP:M${v}} == ""
_WX_VER_MIN?=			${v}
.				endif
.			endfor
.		endif
# Maximum version not specified.
.		if ${_WX_VER_MAX} == ${_WX_VER_CHECK}
.			for v in ${_WX_VERS_ALL}
.				if ${_WX_VER_CHECK:C/[-+]//} == ${v} || ${_WX_VERS_SKIP:M${v}} == ""
_WX_VER_MAX=			${v}
.				endif
.			endfor
.		endif
# Expand versions and add valid ones to each list.
.		for v in ${_WX_VERS_ALL}
.			if ${_WX_VER_MIN} <= ${v} && ${_WX_VER_MAX} >= ${v} && \
			   ${_WX_${list}_LIST:M${v}} == ""
_WX_${list}_LIST+=		${v}
.			endif
.		endfor
.	endfor
.endfor

# Merge the lists into a single list of valid versions.

_WX_VER_MERGED=			#
.for ver in ${_WX_VER_LIST}
.	if ${_WX_VER_NOT_LIST:M${ver}} == ""
_WX_VER_MERGED+=		${ver}
.	endif
.endfor

# Check for a null version.

.if empty(_WX_VER_MERGED)
IGNORE?=				selected a null or invalid wxWidgets version
.endif

# Avoid versions which have unavailable components.

.for ver in ${_WX_VER_MERGED}
.	for comp in ${_WX_COMPS_FINAL}
.		if !defined(_WX_PORT_${comp}_${ver})
_WX_WRONG_COMPS+=		${comp}
_WX_WRONG_VERS+=		${ver}
_WX_VER_MERGED:=		${_WX_VER_MERGED:N${ver}}
.		endif
.	endfor
.endfor

.if empty(_WX_VER_MERGED)
IGNORE?=				selected wxWidgets versions (${_WX_WRONG_VERS}) which do not have the selected components (${_WX_WRONG_COMPS})
.endif

#
# Unicode support.
#

# Create a list of capable versions.

_WX_VER_UC=				#
.for ver in ${_WX_VER_MERGED}
.	if ${_WX_VERS_UC_ALL:M${ver}} != ""
_WX_VER_UC+=			${ver}
.	endif
.endfor

# Requested by the user or port (optional).

.if defined(_WX_UC_AVAILABLE)
.	for ver in ${_WX_VER_UC}
.		if ${_WX_VERS_UC_ALL:M${ver}} != ""
WX_UNICODE=				yes
.		endif
.	endfor
.endif

# Requested by the port (mandatory).

.if defined(WX_UNICODE)
.	if empty(_WX_VER_UC)
IGNORE?=				selected a wxWidgets version which does not support Unicode: ${_WX_VER_MERGED}
.	endif
.endif

# Set Unicode variables.

.if defined(WX_UNICODE)
_WX_VER_FINAL=			${_WX_VER_UC}
_WX_UC=					u
_WX_UCL=				-unicode
_WX_PYSUFX=				-unicode
.else
_WX_VER_FINAL=			${_WX_VER_MERGED}
_WX_UC=					#
_WX_UCL=				#
_WX_PYSUFX=				-ansi
.endif

# Remove unusable installed versions.

.for ver in ${_WX_VER_INSTALLED}
.	if ${_WX_VER_FINAL:M${ver}} == ""
_WX_VER_INSTALLED:=		${_WX_VER_INSTALLED:N${ver}}
.	endif
.endfor

#
# Choose final version.
#

#
# Check for the following (in order):
# 1) WITH_WX_VER		- User preference.
# 2) WANT_WX_VER		- Port preference.
# 3) _WX_VER_INSTALLED	- Installed versions.
# 4) _WX_VER_FINAL		- Available versions.
#

.for list in _WX_VER_FINAL ${_WX_VERS_LISTS}
.	if defined(${list})
.		for ver in ${${list}}
.			if ${_WX_VER_FINAL:M${ver}} != ""
_WX_VER=				${ver}
.			endif
.		endfor
.	endif
.endfor

#
# Set variables.
#

WX_CONFIG?=				${LOCALBASE}/bin/wxgtk2${_WX_UC}-${_WX_VER}-config
WXRC_CMD?=				${LOCALBASE}/bin/wxrc-gtk2${_WX_UC}-${_WX_VER}
WX_VERSION?=			${_WX_VER}

.endif		# _WX_Need_Version

#
# Process components list and add dependencies, variables, etc.
#

.if defined(_POSTMKINCLUDED)

#
# Component parsing.
#
# The variables used are:
# _WX_COMP				- Component part.
# _WX_DEP_TYPE			- Dependency type part.
# _WX_COMP_NEW			- Component + dependency type.
# _WX_COMPS_FINAL		- Final list of components with dependency types.
#

# Default components.

WX_COMPS?=				wx

# Detect invalid and duplicated components.

_WX_COMPS_FINAL=		#
.for comp in ${WX_COMPS}
_WX_COMP=				${comp:C/:([[:alpha:]]+)$//}
.	if ${_WX_COMP} == ${comp}
_WX_DEP_TYPE=			${_WX_DEPTYPE_${comp}_${_WX_VER}}
.	else
_WX_DEP_TYPE=			${comp:C/.+:([[:alpha:]]+)$/\1/}
.	endif
_WX_COMP_NEW=			${_WX_COMP}_${_WX_DEP_TYPE}
.	for __WX_COMP in ${_WX_COMP}
.		if ${_WX_COMPS_ALL:M${__WX_COMP}} == ""
IGNORE?=				selected an invalid wxWidgets component: ${__WX_COMP}
.		endif
.	endfor
.	for __WX_DEP_TYPE in ${_WX_DEP_TYPE}
.		if ${_WX_DEP_TYPES_ALL:M${__WX_DEP_TYPE}} == ""
IGNORE?=				selected an invalid wxWidgets dependency type: ${__WX_DEP_TYPE}
.		endif
.	endfor
.	if !defined(_WX_PORT_${_WX_COMP}_${_WX_VER})
IGNORE?=				selected a wxWidgets component (${_WX_COMP}) which is not available for the selected version (${_WX_VER})
.	endif
.	for newcomp in ${_WX_COMP_NEW}
.		if ${_WX_COMPS_FINAL:M${newcomp}} == "" && !defined(IGNORE)
_WX_COMPS_FINAL+=		${newcomp}
.		endif
.	endfor
.endfor

# Add dependencies.
#
# The variable used are:
# _WX_COMP		-		- Component part.
# _WX_DEP_TYPE			- Dependency type part.

.for comp in ${_WX_COMPS_FINAL}
_WX_COMP=				${comp:C/_([[:alpha:]]+)$//}
_WX_DEP_TYPE=			${comp:C/.+_([[:alpha:]]+)$/\1/}
# XXX Need a .for loop here so the variable is expanded before the assignment.
.	for comp_part in ${_WX_COMP}
.		if ${_WX_DEP_TYPE} == "lib"
.			if defined(_WX_LIB_${_WX_COMP}_${_WX_VER})
LIB_DEPENDS+=			lib${_WX_LIB_${comp_part}_${_WX_VER}}.so:${PORTSDIR}/${_WX_PORT_${comp_part}_${_WX_VER}}
.			else
BUILD_DEPENDS+=			${_WX_FILE_${comp_part}_${_WX_VER}}:${PORTSDIR}/${_WX_PORT_${comp_part}_${_WX_VER}}
RUN_DEPENDS+=			${_WX_FILE_${comp_part}_${_WX_VER}}:${PORTSDIR}/${_WX_PORT_${comp_part}_${_WX_VER}}
.			endif
.		else
${_WX_DEP_TYPE:U}_DEPENDS+=	${_WX_FILE_${comp_part}_${_WX_VER}}:${PORTSDIR}/${_WX_PORT_${comp_part}_${_WX_VER}}
.		endif
.	endfor
.endfor

#
# Set build related variables.
#

MAKE_ENV+=				WX_CONFIG=${WX_CONFIG}
CONFIGURE_ENV+=			WX_CONFIG=${WX_CONFIG}

.if defined(WX_CONF_ARGS)
.	if ${WX_CONF_ARGS:L} == "absolute"
CONFIGURE_ARGS+=		--with-wx-config=${WX_CONFIG}
.	elif ${WX_CONF_ARGS:L} == "relative"
CONFIGURE_ARGS+=		--with-wx=${LOCALBASE} \
						--with-wx-config=${WX_CONFIG:T}
.	else
IGNORE?=				selected an invalid wxWidgets configure argument type: ${WX_CONF_ARGS}
.	endif
.endif

.endif		# _POSTMKINCLUDED
