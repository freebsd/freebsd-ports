# $FreeBSD$
#
# These variables are used in port makefiles to define the options for a port.
#
# OPTIONS_DEFINE		- List of options this ports accept
# OPTIONS_DEFINE_${ARCH}	- List of options this ports accept and are
#				  specific to ${ARCH}
# OPTIONS_DEFAULT		- List of options activated by default
# OPTIONS_DEFAULT_${ARCH}	- List of options activated by default for a
#				  given arch
#
# ${OPTION}_DESC		- Description of the ${OPTION}
#
# OPTIONS_SINGLE		- List of single-choice grouped options: 1 and
#				  only 1 among N
# OPTIONS_RADIO			- List of radio-choice grouped options: 0 or 1
#				  among N
# OPTIONS_MULTI			- List of multiple-choice grouped options: at
#				  least 1 among N
# OPTIONS_GROUP			- List of group-choice grouped options: 0 or
#				  more among N
#
# OPTIONS_SINGLE_${NAME}	- List of OPTIONS grouped as single choice (for
#				  the single named as ${NAME} as defined in
#				  OPTIONS_SINGLE)
# OPTIONS_RADIO_${NAME}		- List of OPTIONS grouped as radio choice (for
#				  the radio named as ${NAME} as defined in
#				  OPTIONS_RADIO)
# OPTIONS_MULTI_${NAME}		- List of OPTIONS grouped as multiple-choice
#				  (for the multi named as ${NAME} as defined in
#				  OPTIONS_MULTI)
# OPTIONS_GROUP_${NAME}		- List of OPTIONS grouped as group-choice (for
#				  the group named as ${NAME} as defined in
#				  OPTIONS_GROUP)
#
# OPTIONS_EXCLUDE		- List of options unsupported (useful for slave ports)
# OPTIONS_EXCLUDE_${ARCH}	- List of options unsupported on a given ${ARCH}
# OPTIONS_EXCLUDE_${OPSYS}	- List of options unsupported on a given ${OPSYS}
# OPTIONS_EXCLUDE_${OPSYS}_${OSREL:R} - List of options unsupported on a given
#				  ${OPSYS} and major version (8/9/10...)
# OPTIONS_SLAVE			- This is designed for slave ports, it removes an
#				  option from the options list inherited from the
#				  master port and it always adds it to PORT_OPTIONS
#				  meaning activated
#
# These variables can be used in make.conf to configure options.  They are
# processed in the order listed below, i.e. later variables override the effects
# of previous variables.  Options saved using the options dialog are processed
# right before OPTIONS_SET_FORCE.  When building a port a dialog to configure
# options will only appear if there are new options, i.e. options which have not
# been configured before either using the option dialog in a previous build or
# using the variables below.  You can force the dialog to appear by running
# "make config".
#
# OPTIONS_SET			- List of options to enable for all ports.
# OPTIONS_UNSET			- List of options to disable for all ports.
# ${OPTIONS_NAME}_SET		- List of options to enable for a specific port.
# ${OPTIONS_NAME}_UNSET		- List of options to disable for a specific port.
#
# OPTIONS_SET_FORCE		- List of options to enable for all ports.
# OPTIONS_UNSET_FORCE		- List of options to disable for all ports.
# ${OPTIONS_NAME}_SET_FORCE	- List of options to enable for a specific port.
# ${OPTIONS_NAME}_UNSET_FORCE
#				- List of options to disable for a specific port.
#
# These variables can be used on the command line. They override the effects of
# the make.conf variables above.
#
# WITH				- Set options from the command line
# WITHOUT			- Unset options from the command line
#
#
# These variables are strictly informational (read-only).  They indicate the
# current state of the selected options; they are space-delimited lists.
#
# SELECTED_OPTIONS		- list of options set "on"
# DESELECTED_OPTIONS		- list of options set "off"
#
#
# The following knobs are there to simplify the handling of OPTIONS in simple
# cases :
#
# OPTIONS_SUB			When defined it will add to PLIST_SUB:
#				Option enabled  ${opt}=""
#				Option disabled ${opt}="@comment "
#
# ${opt}_CONFIGURE_ON		When option is enabled, it will add its content to
#				the CONFIGURE_ARGS.
# ${opt}_CONFIGURE_OFF		When option is disabled, it will add its content to
#				the CONFIGURE_ARGS.
# ${opt}_CONFIGURE_ENABLE	Will add to CONFIGURE_ARGS:
#				Option enabled  --enable-${content}
#				Option disabled --disable-${content}
# ${opt}_CONFIGURE_WITH		Will add to CONFIGURE_ARGS:
#				Option enabled  --with-${content}
#				Option disabled --without-${content}
#
# ${opt}_CMAKE_ON		When option is enabled, it will add its content to
#				the CMAKE_ARGS.
# ${opt}_CMAKE_OFF		When option is disabled, it will add its content to
#				the CMAKE_ARGS.
#
# ${opt}_CMAKE_BOOL		Will add to CMAKE_ARGS:
#				Option enabled  -D${content}:BOOL=true
#				Option disabled -D${content}:BOOL=false
# ${opt}_CMAKE_BOOL_OFF		Will add to CMAKE_ARGS:
#				Option enabled  -D${content}:BOOL=false
#				Option disabled -D${content}:BOOL=true
#
# ${opt}_QMAKE_ON		When option is enabled, it will add its content to
#				the QMAKE_ARGS.
# ${opt}_QMAKE_OFF		When option is disabled, it will add its content to
#				the QMAKE_ARGS.
#
# ${opt}_MESON_ON		When option is enabled, it will add its
#				content to MESON_ARGS.
# ${opt}_MESON_OFF		When option is disabled, it will add its
#				content to MESON_ARGS.
#
# ${opt}_MESON_TRUE		Will add to MESON_ARGS:
#				Option enabled	-D${content}=true
#				Option disabled	-D${content}=false
# ${opt}_MESON_FALSE		Will add to MESON_ARGS:
#				Option enabled	-D${content}=false
#				Option disabled	-D${content}=true
#
# ${opt}_MESON_YES		Will add to MESON_ARGS:
#				Option enabled  -D${content}=yes
#				Option disabled -D${content}=no
# ${opt}_MESON_NO		Will add to MESON_ARGS:
#				Option enabled  -D${content}=no
#				Option disabled -D${content}=yes
#
# ${opt}_IMPLIES		When opt is enabled, options named in IMPLIES will
#				get enabled too.
# ${opt}_PREVENTS		When opt is enabled, if any options in PREVENTS are
#				also enabled, it will produce an error.
# ${opt}_PREVENTS_MSG		Provides a message explaining why the options
#				cannot be selected together.
#
# ${opt}_USE=	FOO=bar		When option is enabled, it will  enable
#				USE_FOO+= bar
#				If you need more than one option, you can do
#				FOO=bar,baz and you'll get USE_FOO=bar baz
# ${opt}_USE_OFF=	FOO=bar	When option is disabled, it will enable
#				USE_FOO+= bar
#
# ${opt}_VARS=	FOO=bar		When option is enabled, it will set
#				FOO= bar
# ${opt}_VARS=	FOO+=bar	When option is enabled, it will append
#				FOO+= bar
# ${opt}_VARS_OFF=    FOO=bar	When option is disabled, it will set
#				FOO= bar
# ${opt}_VARS_OFF=    FOO+=bar	When option is disabled, it will append
#				FOO+= bar
#
# For each of the depends target PKG FETCH EXTRACT PATCH BUILD LIB RUN,
# defining ${opt}_${deptype}_DEPENDS will add its content to the actual
# dependency when the option is enabled.  Defining
# ${opt}_${deptype}_DEPENDS_OFF will add its content to the actual dependency
# when the option is disabled.
#
# For each of the variables in _OPTIONS_FLAGS below, defining
# ${opt}_${variable} will add its content to the actual variable when the
# option is enabled.  Defining ${opt}_${variable}_OFF will add its content to
# the actual variable when the option is disabled.

##
# Set all the options available for the ports, beginning with the
# global ones and ending with the ones decided by the maintainer.

.if !defined(OPTIONSMKINCLUDED)
OPTIONSMKINCLUDED=	bsd.options.mk

OPTIONS_NAME?=	${PKGORIGIN:S/\//_/}
OPTIONS_FILE?=	${PORT_DBDIR}/${OPTIONS_NAME}/options

_OPTIONS_FLAGS=	ALL_TARGET BROKEN CATEGORIES CFLAGS CONFIGURE_ENV CONFLICTS \
		CONFLICTS_BUILD CONFLICTS_INSTALL CPPFLAGS CXXFLAGS \
		DESKTOP_ENTRIES DISTFILES EXTRA_PATCHES EXTRACT_ONLY \
		GH_ACCOUNT GH_PROJECT GH_SUBDIR GH_TAGNAME GH_TUPLE IGNORE \
		INFO INSTALL_TARGET LDFLAGS LIBS MAKE_ARGS MAKE_ENV \
		MASTER_SITES PATCHFILES PATCH_SITES PLIST_DIRS PLIST_FILES \
		PLIST_SUB PORTDOCS PORTEXAMPLES SUB_FILES SUB_LIST \
		TEST_TARGET USES BINARY_ALIAS
_OPTIONS_DEPENDS=	PKG FETCH EXTRACT PATCH BUILD LIB RUN

# The format here is target_family:priority:target-type
_OPTIONS_TARGETS=	fetch:300:pre fetch:500:do fetch:700:post \
			extract:300:pre extract:500:do extract:700:post \
			patch:300:pre patch:500:do patch:700:post \
			configure:300:pre configure:500:do configure:700:post \
			build:300:pre build:500:do build:700:post \
			install:300:pre install:500:do install:700:post  \
			test:300:pre test:500:do test:700:post  \
			package:300:pre package:500:do package:700:post \
			stage:800:post

# Set the default values for the global options, as defined by portmgr
.if !defined(NOPORTDOCS)
PORT_OPTIONS+=	DOCS
.else
OPTIONS_WARNINGS+=		"NOPORTDOCS"
WITHOUT+=			DOCS
OPTIONS_WARNINGS_UNSET+=	DOCS
.endif

.if !defined(WITHOUT_NLS)
PORT_OPTIONS+=	NLS
.else
WITHOUT+=		NLS
.endif

.if !defined(NOPORTEXAMPLES)
PORT_OPTIONS+=	EXAMPLES
.else
OPTIONS_WARNINGS+=		"NOPORTEXAMPLES"
WITHOUT+=			EXAMPLES
OPTIONS_WARNINGS_UNSET+=	EXAMPLES
.endif

PORT_OPTIONS+=	IPV6

# Add per arch options
.for opt in ${OPTIONS_DEFINE_${ARCH}}
.if empty(OPTIONS_DEFINE:M${opt})
OPTIONS_DEFINE+=	${opt}
.endif
.endfor

# Add per arch defaults
OPTIONS_DEFAULT+=	${OPTIONS_DEFAULT_${ARCH}}

_ALL_EXCLUDE=	${OPTIONS_EXCLUDE_${ARCH}} ${OPTIONS_EXCLUDE} \
		${OPTIONS_SLAVE} ${OPTIONS_EXCLUDE_${OPSYS}} \
		${OPTIONS_EXCLUDE_${OPSYS}_${OSREL:R}}

.for opt in ${OPTIONS_DEFINE:O:u}
.  if !${_ALL_EXCLUDE:M${opt}}
.    for opt_implied in ${${opt}_IMPLIES}
.       if ${_ALL_EXCLUDE:M${opt_implied}}
_ALL_EXCLUDE+=	${opt}
.       endif
.    endfor
.  endif
.endfor

# Remove options the port maintainer doesn't want
.for opt in ${_ALL_EXCLUDE:O:u}
OPTIONS_DEFAULT:=	${OPTIONS_DEFAULT:N${opt}}
OPTIONS_DEFINE:=	${OPTIONS_DEFINE:N${opt}}
PORT_OPTIONS:=		${PORT_OPTIONS:N${opt}}
.  for otype in SINGLE RADIO MULTI GROUP
.    for m in ${OPTIONS_${otype}}
OPTIONS_${otype}_${m}:=	${OPTIONS_${otype}_${m}:N${opt}}
.    endfor
.  endfor
.endfor

# Remove empty SINGLE/GROUP/RADIO/MULTI
# Can be empty because of exclude/slaves
.for otype in SINGLE RADIO MULTI GROUP
.  for m in ${OPTIONS_${otype}}
.    if empty(OPTIONS_${otype}_${m})
OPTIONS_${otype}:=	${OPTIONS_${otype}:N${m}}
.    endif
.  endfor
.endfor

# Sort options
ALL_OPTIONS:=	${OPTIONS_DEFINE:O:u}
OPTIONS_DEFAULT:=	${OPTIONS_DEFAULT:O:u}

# complete list
COMPLETE_OPTIONS_LIST=	${ALL_OPTIONS}
.for otype in SINGLE RADIO MULTI GROUP
.  for m in ${OPTIONS_${otype}}
COMPLETE_OPTIONS_LIST+=	${OPTIONS_${otype}_${m}}
.  endfor
.endfor

## Now create the list of activated options
.if defined(OPTIONS_OVERRIDE)
# Special case $OPTIONS_OVERRIDE; if it is defined forget about anything done
# before
NEW_OPTIONS=
PORT_OPTIONS:=	${OPTIONS_OVERRIDE}
.else
NEW_OPTIONS=	${COMPLETE_OPTIONS_LIST}

## Set default options defined by the port maintainer
PORT_OPTIONS+=	${OPTIONS_DEFAULT}

## Set system-wide defined options (set by user in make.conf)
.  for opt in ${OPTIONS_SET}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.    endif
.  endfor

## Remove the options excluded system-wide (set by user in make.conf)
.  for opt in ${OPTIONS_UNSET}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.  endfor

## Set the options specified per-port (set by user in make.conf)
.  for opt in ${${OPTIONS_NAME}_SET}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.    endif
.  endfor

## Unset the options excluded per-port (set by user in make.conf)
.  for opt in ${${OPTIONS_NAME}_UNSET}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.  endfor

## options files (from dialog)
.  if exists(${OPTIONS_FILE}) && !make(rmconfig)
.  include "${OPTIONS_FILE}"
.  endif
.  sinclude "${OPTIONS_FILE}.local"

### convert WITH and WITHOUT found in make.conf or reloaded from old optionsfile
# XXX once WITH_DEBUG is not magic any more, do remove the :NDEBUG from here.
.for opt in ${ALL_OPTIONS:NDEBUG}
.if defined(WITH_${opt})
OPTIONS_WARNINGS+=	"WITH_${opt}"
OPTIONS_WARNINGS_SET+=	${opt}
PORT_OPTIONS+=	${opt}
.endif
.if defined(WITHOUT_${opt})
OPTIONS_WARNINGS+=	"WITHOUT_${opt}"
OPTIONS_WARNINGS_UNSET+=	${opt}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
.endif
.endfor

_OPTIONS_UNIQUENAME=	${PKGNAMEPREFIX}${PORTNAME}
.for _k in SET UNSET SET_FORCE UNSET_FORCE
.if defined(${_OPTIONS_UNIQUENAME}_${_k})
WARNING+=	"You are using ${_OPTIONS_UNIQUENAME}_${_k} which is not supported any more, use:"
WARNING+=	"${OPTIONS_NAME}_${_k}=	${${_OPTIONS_UNIQUENAME}_${_k}}"
.endif
.endfor

.if defined(OPTIONS_WARNINGS)
WARNING+=	"You are using the following deprecated options: ${OPTIONS_WARNINGS}"
WARNING+=	"If you added them on the command line, you should replace them by"
WARNING+=	"WITH=\"${OPTIONS_WARNINGS_SET}\" WITHOUT=\"${OPTIONS_WARNINGS_UNSET}\""
WARNING+=	""
WARNING+=	"If they are global options set in your make.conf, you should replace them with:"
.if defined(OPTIONS_WARNINGS_SET)
WARNING+=	"OPTIONS_SET=${OPTIONS_WARNINGS_SET}"
.endif
.if defined(OPTIONS_WARNINGS_UNSET)
WARNING+=	"OPTIONS_UNSET=${OPTIONS_WARNINGS_UNSET}"
.endif
WARNING+=	""
WARNING+=	"If they are local to this port, you should use:"
.if defined(OPTIONS_WARNINGS_SET)
WARNING+=	"${OPTIONS_NAME}_SET=${OPTIONS_WARNINGS_SET}"
.endif
.if defined(OPTIONS_WARNINGS_UNSET)
WARNING+=	"${OPTIONS_NAME}_UNSET=${OPTIONS_WARNINGS_UNSET}"
.endif
.endif

## Finish by using the options set by the port config dialog, if any
.  for opt in ${OPTIONS_FILE_SET}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.    endif
.  endfor

.for opt in ${OPTIONS_FILE_UNSET}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.endfor

.endif

## FORCE
## Set system-wide defined options (set by user in make.conf)
.  for opt in ${OPTIONS_SET_FORCE}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.    endif
.  endfor

## Remove the options excluded system-wide (set by user in make.conf)
.  for opt in ${OPTIONS_UNSET_FORCE}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.  endfor

## Set the options specified per-port (set by user in make.conf)
.  for opt in ${${OPTIONS_NAME}_SET_FORCE}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.    endif
.  endfor

## Unset the options excluded per-port (set by user in make.conf)
.  for opt in ${${OPTIONS_NAME}_UNSET_FORCE}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.  endfor


## Cmdline always win over the rest
.for opt in ${WITH}
.  if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.  endif
.endfor

.for opt in ${WITHOUT}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.endfor

## Enable options implied by other options
# _PREVENTS is handled in bsd.port.mk:pre-check-config
## 1) Build dependency chain in A.B format:
_DEPCHAIN=
.for opt in ${COMPLETE_OPTIONS_LIST}
.  for o in ${${opt}_IMPLIES}
_DEPCHAIN+=	${opt}.$o
.  endfor
.endfor
## 2) Check each dependency pair and if LHS is in PORT_OPTIONS then add RHS.
##    All of RHS of "RHS.*" (i.e. indirect dependency) are also added for
##    fast convergence.
_PORT_OPTIONS:=	${PORT_OPTIONS}
.for _count in _0 ${COMPLETE_OPTIONS_LIST}
count=	${_count}
### Check if all of the nested dependency are resolved already.
.  if ${count} == _0 || ${_PORT_OPTIONS} != ${PORT_OPTIONS}
PORT_OPTIONS:=	${_PORT_OPTIONS}
.    for dc in ${_DEPCHAIN}
.      for opt in ${_PORT_OPTIONS}
_opt=${opt}
### Add all of direct and indirect dependency only if
### they are not in ${PORT_OPTIONS}.
.        if !empty(_opt:M${dc:R})
.          for d in ${dc:E} ${_DEPCHAIN:M${dc:E}.*:E}
.            if empty(_PORT_OPTIONS:M$d)
_PORT_OPTIONS+=	$d
.            endif
.          endfor
.        endif
.      endfor
.    endfor
.  endif
.endfor

# Finally, add options required by slave ports
PORT_OPTIONS+=	${OPTIONS_SLAVE}

# Sort options and eliminate duplicates
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}

## Now some compatibility
.if empty(PORT_OPTIONS:MDOCS)
NOPORTDOCS=	yes
.endif

.if empty(PORT_OPTIONS:MEXAMPLES)
NOPORTEXAMPLES=	yes
.endif

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

.if defined(NO_OPTIONS_SORT)
ALL_OPTIONS=	${OPTIONS_DEFINE}
.endif

.for target in ${_OPTIONS_TARGETS:C/:.*//:u}
_OPTIONS_${target}?=
.endfor

.for opt in ${COMPLETE_OPTIONS_LIST} ${_ALL_EXCLUDE:O:u}
# PLIST_SUB
PLIST_SUB?=
SUB_LIST?=
.  if defined(OPTIONS_SUB)
.    if ! ${PLIST_SUB:M${opt}=*}
.      if ${PORT_OPTIONS:M${opt}}
PLIST_SUB:=	${PLIST_SUB} ${opt}="" NO_${opt}="@comment "
.      else
PLIST_SUB:=	${PLIST_SUB} ${opt}="@comment " NO_${opt}=""
.      endif
.    endif
.    if ! ${SUB_LIST:M${opt}=*}
.      if ${PORT_OPTIONS:M${opt}}
SUB_LIST:=	${SUB_LIST} ${opt}="" NO_${opt}="@comment "
.      else
SUB_LIST:=	${SUB_LIST} ${opt}="@comment " NO_${opt}=""
.      endif
.    endif
.  endif

.  if ${PORT_OPTIONS:M${opt}}
.    if defined(${opt}_USE)
.      for option in ${${opt}_USE:C/=.*//:O:u}
_u=		${option}
USE_${_u:tu}+=	${${opt}_USE:M${option}=*:C/.*=//g:C/,/ /g}
.      endfor
.    endif
.    if defined(${opt}_VARS)
.      for var in ${${opt}_VARS:C/=.*//:O:u}
_u=			${var}
.        if ${_u:M*+}
${_u:C/.$//:tu}+=	${${opt}_VARS:M${var}=*:C/[^+]*\+=//:C/^"(.*)"$$/\1/}
.        else
${_u:tu}=		${${opt}_VARS:M${var}=*:C/[^=]*=//:C/^"(.*)"$$/\1/}
.        endif
.      endfor
.    endif
.    if defined(${opt}_CONFIGURE_ENABLE)
CONFIGURE_ARGS+=	${${opt}_CONFIGURE_ENABLE:S/^/--enable-/}
.    endif
.    if defined(${opt}_CONFIGURE_WITH)
CONFIGURE_ARGS+=	${${opt}_CONFIGURE_WITH:S/^/--with-/}
.    endif
.    if defined(${opt}_CMAKE_BOOL)
CMAKE_ARGS+=		${${opt}_CMAKE_BOOL:C/.*/-D&:BOOL=true/}
.    endif
.    if defined(${opt}_CMAKE_BOOL_OFF)
CMAKE_ARGS+=		${${opt}_CMAKE_BOOL_OFF:C/.*/-D&:BOOL=false/}
.    endif
.    if defined(${opt}_MESON_TRUE)
MESON_ARGS+=		${${opt}_MESON_TRUE:C/.*/-D&=true/}
.    endif
.    if defined(${opt}_MESON_FALSE)
MESON_ARGS+=		${${opt}_MESON_FALSE:C/.*/-D&=false/}
.    endif
.    if defined(${opt}_MESON_YES)
MESON_ARGS+=		${${opt}_MESON_YES:C/.*/-D&=yes/}
.    endif
.    if defined(${opt}_MESON_NO)
MESON_ARGS+=		${${opt}_MESON_NO:C/.*/-D&=no/}
.    endif
.    for configure in CONFIGURE CMAKE MESON QMAKE
.      if defined(${opt}_${configure}_ON)
${configure}_ARGS+=	${${opt}_${configure}_ON}
.      endif
.    endfor
.    for flags in ${_OPTIONS_FLAGS}
.      if defined(${opt}_${flags})
${flags}+=	${${opt}_${flags}}
.      endif
.    endfor
.    for deptype in ${_OPTIONS_DEPENDS}
.      if defined(${opt}_${deptype}_DEPENDS)
${deptype}_DEPENDS+=	${${opt}_${deptype}_DEPENDS}
.      endif
.    endfor
.    for target in ${_OPTIONS_TARGETS}
_target=	${target:C/:.*//}
_prio=		${target:C/.*:(.*):.*/\1/}
_type=		${target:C/.*://}
_OPTIONS_${_target}:=	${_OPTIONS_${_target}} ${_prio}:${_type}-${_target}-${opt}-on
.    endfor
.  else
.    if defined(${opt}_USE_OFF)
.      for option in ${${opt}_USE_OFF:C/=.*//:O:u}
_u=		${option}
USE_${_u:tu}+=	${${opt}_USE_OFF:M${option}=*:C/.*=//g:C/,/ /g}
.      endfor
.    endif
.    if defined(${opt}_VARS_OFF)
.      for var in ${${opt}_VARS_OFF:C/=.*//:O:u}
_u=			${var}
.        if ${_u:M*+}
${_u:C/.$//:tu}+=	${${opt}_VARS_OFF:M${var}=*:C/[^+]*\+=//:C/^"(.*)"$$/\1/}
.        else
${_u:tu}=		${${opt}_VARS_OFF:M${var}=*:C/[^=]*=//:C/^"(.*)"$$/\1/}
.        endif
.      endfor
.    endif
.    if defined(${opt}_CONFIGURE_ENABLE)
CONFIGURE_ARGS+=	${${opt}_CONFIGURE_ENABLE:S/^/--disable-/:C/=.*//}
.    endif
.    if defined(${opt}_CONFIGURE_WITH)
CONFIGURE_ARGS+=	${${opt}_CONFIGURE_WITH:S/^/--without-/:C/=.*//}
.    endif
.    if defined(${opt}_CMAKE_BOOL)
CMAKE_ARGS+=		${${opt}_CMAKE_BOOL:C/.*/-D&:BOOL=false/}
.    endif
.    if defined(${opt}_CMAKE_BOOL_OFF)
CMAKE_ARGS+=		${${opt}_CMAKE_BOOL_OFF:C/.*/-D&:BOOL=true/}
.    endif
.    if defined(${opt}_MESON_TRUE)
MESON_ARGS+=		${${opt}_MESON_TRUE:C/.*/-D&=false/}
.    endif
.    if defined(${opt}_MESON_FALSE)
MESON_ARGS+=            ${${opt}_MESON_FALSE:C/.*/-D&=true/}
.    endif
.    if defined(${opt}_MESON_YES)
MESON_ARGS+=		${${opt}_MESON_YES:C/.*/-D&=no/}
.    endif
.    if defined(${opt}_MESON_NO)
MESON_ARGS+=		${${opt}_MESON_NO:C/.*/-D&=yes/}
.    endif
.    for configure in CONFIGURE CMAKE MESON QMAKE
.      if defined(${opt}_${configure}_OFF)
${configure}_ARGS+=	${${opt}_${configure}_OFF}
.      endif
.    endfor
.    for flags in ${_OPTIONS_FLAGS}
.      if defined(${opt}_${flags}_OFF)
${flags}+=	${${opt}_${flags}_OFF}
.      endif
.    endfor
.    for deptype in ${_OPTIONS_DEPENDS}
.      if defined(${opt}_${deptype}_DEPENDS_OFF)
${deptype}_DEPENDS+=	${${opt}_${deptype}_DEPENDS_OFF}
.      endif
.    endfor
.    for target in ${_OPTIONS_TARGETS}
_target=	${target:C/:.*//}
_prio=		${target:C/.*:(.*):.*/\1/}
_type=		${target:C/.*://}
_OPTIONS_${_target}:=	${_OPTIONS_${_target}} ${_prio}:${_type}-${_target}-${opt}-off
.    endfor
.  endif
.endfor

.undef (SELECTED_OPTIONS)
.undef (DESELECTED_OPTIONS)
# Wait to expand PORT_OPTIONS until the last moment in case something modifies
# the selected OPTIONS after bsd.port.options.mk is included.  This uses
# bmake's :@ for loop.
_SELECTED_OPTIONS=	${ALL_OPTIONS:@opt@${PORT_OPTIONS:M${opt}}@}
_DESELECTED_OPTIONS=	${ALL_OPTIONS:@opt@${"${PORT_OPTIONS:M${opt}}":?:${opt}}@}
.for otype in MULTI GROUP SINGLE RADIO
.  for m in ${OPTIONS_${otype}}
_SELECTED_OPTIONS+=	${OPTIONS_${otype}_${m}:@opt@${PORT_OPTIONS:M${opt}}@}
_DESELECTED_OPTIONS+=	${OPTIONS_${otype}_${m}:@opt@${"${PORT_OPTIONS:M${opt}}":?:${opt}}@}
.  endfor
.endfor
SELECTED_OPTIONS=	${_SELECTED_OPTIONS:O:u}
DESELECTED_OPTIONS=	${_DESELECTED_OPTIONS:O:u}

.endif
