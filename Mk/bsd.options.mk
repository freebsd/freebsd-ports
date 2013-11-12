#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# These variables are used in port makefiles to define the options for a port.
#
# OPTIONS_DEFINE			- List of options this ports accept
# OPTIONS_DEFINE_${ARCH}	- List of options this ports accept and are
#							  specific to ${ARCH}
# OPTIONS_DEFAULT			- List of options activated by default
# OPTIONS_DEFAULT_${ARCH}	- List of options activated by default for a
#							  given arch
#
# ${OPTION}_DESC			- Description of the ${OPTION}
#
# OPTIONS_SINGLE			- List of single-choice grouped options: 1 and
# 							  only 1 among N
# OPTIONS_RADIO				- List of radio-choice grouped options: 0 or 1
#							  among N
# OPTIONS_MULTI				- List of multiple-choice grouped options: at
#							  least 1 among N
# OPTIONS_GROUP				- List of group-choice grouped options: 0 or
#							  more among N
#
# OPTIONS_SINGLE_${NAME}	- List of OPTIONS grouped as single choice (for
#							  the single named as ${NAME} as defined in
#							  OPTIONS_SINGLE)
# OPTIONS_RADIO_${NAME}		- List of OPTIONS grouped as radio choice (for
#							  the radio named as ${NAME} as defined in
#							  OPTIONS_RADIO)
# OPTIONS_MULTI_${NAME}		- List of OPTIONS grouped as multiple-choice
#							  (for the multi named as ${NAME} as defined in
#							  OPTIONS_MULTI)
# OPTIONS_GROUP_${NAME}		- List of OPTIONS grouped as group-choice (for
#							  the group named as ${NAME} as defined in
#							  OPTIONS_GROUP)
#
# OPTIONS_EXCLUDE			- List of options unsupported (useful for slave ports)
# OPTIONS_EXCLUDE_${ARCH}	- List of options unsupported on a given ${ARCH}
# OPTIONS_SLAVE				- This is designed for slave ports, it removes an
#							  option from the options list inherited from the
#							  master port and it always adds it to PORT_OPTIONS
#							  meaning activated
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
# OPTIONS_SET				- List of options to enable for all ports.
# OPTIONS_UNSET				- List of options to disable for all ports.
# ${OPTIONS_NAME}_SET		- List of options to enable for a specific port.
# ${OPTIONS_NAME}_UNSET		- List of options to disable for a specific port.
#
# OPTIONS_SET_FORCE			- List of options to enable for all ports.
# OPTIONS_UNSET_FORCE		- List of options to disable for all ports.
# ${OPTIONS_NAME}_SET_FORCE	- List of options to enable for a specific port.
# ${OPTIONS_NAME}_UNSET_FORCE
#							- List of options to disable for a specific port.
#
# These variables can be used on the command line. They override the effects of
# the make.conf variables above.
#
# WITH						- Set options from the command line
# WITHOUT					- Unset options from the command line
#
#
# The following knobs are there to simplify the handling of OPTIONS in simple
# cases :
#
# OPTIONS_SUB				When defined it will add to PLIST_SUB:
#							Option enabled  ${opt}=""
#							Option disabled ${opt}="@comment "
#
# ${opt}_CONFIGURE_ON		When option is enabled, it will add its content to
#							the CONFIGURE_ARGS.
# ${opt}_CONFIGURE_OFF		When option is disabled, it will add its content to
#							the CONFIGURE_ARGS.
# ${opt}_CONFIGURE_ENABLE	Will add to CONFIGURE_ARGS:
#							Option enabled  --enable-${content}
#							Option disabled --disable-${content}
# ${opt}_CONFIGURE_WITH		Will add to CONFIGURE_ARGS:
#							Option enabled  --with-${content}
#							Option disabled --without-${content}
#
# ${opt}_CMAKE_ON			When option is enabled, it will add its content to
#							the CMAKE_ARGS.
# ${opt}_CMAKE_OFF			When option is disabled, it will add its content to
#							the CMAKE_ARGS.
#
# ${opt}_USE=	FOO=bar		When option is enabled, it will  enable
#							USE_FOO+= bar
#							If you need more than one option, you can do
#							FOO=bar,baz and you'll get USE_FOO=bar baz
#
# For each of CFLAGS CPPFLAGS CXXFLAGS LDFLAGS CONFIGURE_ENV MAKE_ARGS MAKE_ENV
# ALL_TARGET INSTALL_TARGET USES DISTFILES PLIST_FILES PLIST_DIRS PLIST_DIRSTRY
# EXTRA_PATCHES PATCHFILES PATCH_SITES CATEGORIES, defining ${opt}_${variable}
# will add its content to the actual variable when the option is enabled.
#
# For each of the depends target PKG EXTRACT PATCH FETCH BUILD LIB RUN,
# defining ${opt}_${deptype}_DEPENDS will add its content to the actual
# dependency when the option is enabled.

##
# Set all the options available for the ports, beginning with the
# global ones and ending with the ones decided by the maintainer.

.if !defined(OPTIONSMKINCLUDED)
OPTIONSMKINCLUDED=	bsd.options.mk

OPTIONS_NAME?=	${PKGORIGIN:S/\//_/}
OPTIONSFILE?=	${PORT_DBDIR}/${UNIQUENAME}/options
OPTIONS_FILE?=	${PORT_DBDIR}/${OPTIONS_NAME}/options

# Set the default values for the global options, as defined by portmgr
.if !defined(NOPORTDOCS)
PORT_OPTIONS+=	DOCS
.endif

.if !defined(WITHOUT_NLS)
PORT_OPTIONS+=	NLS
.endif

.if !defined(NOPORTEXAMPLES)
PORT_OPTIONS+=	EXAMPLES
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

# Remove options the port maintainer doesn't want
.for opt in ${OPTIONS_EXCLUDE_${ARCH}} ${OPTIONS_EXCLUDE} ${OPTIONS_SLAVE}
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

# XXX To remove once UNIQUENAME will be removed
## Set the options specified per-port (set by user in make.conf)
.  for opt in ${${UNIQUENAME}_SET}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.    endif
.  endfor

## Unset the options excluded per-port (set by user in make.conf)
.  for opt in ${${UNIQUENAME}_UNSET}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.  endfor
# XXX To remove once UNIQUENAME will be removed

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

# XXX to remove once UNIQUENAME is removed
## options files (from dialog)
.  if exists(${OPTIONSFILE}) && !make(rmconfig)
.  include "${OPTIONSFILE}"
.  endif
.  sinclude "${OPTIONSFILE}.local"
# XXX to remove once UNIQUENAME is removed

## options files (from dialog)
.  if exists(${OPTIONS_FILE}) && !make(rmconfig)
.  include "${OPTIONS_FILE}"
.  endif
.  sinclude "${OPTIONS_FILE}.local"

### convert WITH and WITHOUT found in make.conf or reloaded from old optionsfile
.for opt in ${ALL_OPTIONS}
.if defined(WITH_${opt})
PORT_OPTIONS+=	${opt}
.endif
.if defined(WITHOUT_${opt})
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
.endif
.endfor

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

# XXX To remove once UNIQUENAME will be removed
## Set the options specified per-port (set by user in make.conf)
.  for opt in ${${UNIQUENAME}_SET_FORCE}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.    endif
.  endfor

## Unset the options excluded per-port (set by user in make.conf)
.  for opt in ${${UNIQUENAME}_UNSET_FORCE}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
NEW_OPTIONS:=	${NEW_OPTIONS:N${opt}}
.  endfor
# XXX To remove once UNIQUENAME will be removed

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

.if empty(PORT_OPTIONS:MNLS)
WITHOUT_NLS=	yes
.endif

.if defined(NO_OPTIONS_SORT)
ALL_OPTIONS=	${OPTIONS_DEFINE}
.endif

### to be removed once old OPTIONS disappear
.for opt in ${ALL_OPTIONS}
.if empty(PORT_OPTIONS:M${opt})
.   if !defined(WITH_${opt}) && !defined(WITHOUT_${opt})
WITHOUT_${opt}:=	true
.   endif
.else
.   if !defined(WITH_${opt}) && !defined(WITHOUT_${opt})
WITH_${opt}:=  true
.   endif
.endif
.endfor
###

.for opt in ${COMPLETE_OPTIONS_LIST} ${OPTIONS_SLAVE}
# PLIST_SUB
PLIST_SUB?=
.  if defined(OPTIONS_SUB)
.    if ! ${PLIST_SUB:M${opt}=*}
.      if ${PORT_OPTIONS:M${opt}}
PLIST_SUB:=	${PLIST_SUB} ${opt}=""
.      else
PLIST_SUB:=	${PLIST_SUB} ${opt}="@comment "
.      endif
.    endif
.  endif

.  if ${PORT_OPTIONS:M${opt}}
.    if defined(${opt}_USE)
.      for option in ${${opt}_USE}
_u=		${option:C/=.*//g}
USE_${_u:U}+=	${option:C/.*=//g:C/,/ /g}
.      endfor
.    endif
.    if defined(${opt}_CONFIGURE_ENABLE)
.      for iopt in ${${opt}_CONFIGURE_ENABLE}
CONFIGURE_ARGS+=	--enable-${iopt}
.      endfor
.    endif
.    if defined(${opt}_CONFIGURE_WITH)
.      for iopt in ${${opt}_CONFIGURE_WITH}
CONFIGURE_ARGS+=	--with-${iopt}
.      endfor
.    endif
.    if defined(${opt}_CONFIGURE_ON)
CONFIGURE_ARGS+=	${${opt}_CONFIGURE_ON}
.    endif
.    if defined(${opt}_CMAKE_ON)
CMAKE_ARGS+=	${${opt}_CMAKE_ON}
.    endif
.    for flags in CFLAGS CPPFLAGS CXXFLAGS LDFLAGS CONFIGURE_ENV MAKE_ARGS \
         MAKE_ENV ALL_TARGET INSTALL_TARGET USES DISTFILES PLIST_FILES \
         PLIST_DIRS PLIST_DIRSTRY EXTRA_PATCHES PATCHFILES PATCH_SITES CATEGORIES
.      if defined(${opt}_${flags})
${flags}+=	${${opt}_${flags}}
.      endif
.    endfor
.    for deptype in PKG EXTRACT PATCH FETCH BUILD LIB RUN
.      if defined(${opt}_${deptype}_DEPENDS)
${deptype}_DEPENDS+=	${${opt}_${deptype}_DEPENDS}
.      endif
.    endfor
.  else
.    if defined(${opt}_CONFIGURE_ENABLE)
.      for iopt in ${${opt}_CONFIGURE_ENABLE}
CONFIGURE_ARGS+=	--disable-${iopt}
.      endfor
.    endif
.    if defined(${opt}_CONFIGURE_WITH)
.      for iopt in ${${opt}_CONFIGURE_WITH}
CONFIGURE_ARGS+=	--without-${iopt}
.      endfor
.    endif
.    if defined(${opt}_CONFIGURE_OFF)
CONFIGURE_ARGS+=	${${opt}_CONFIGURE_OFF}
.    endif
.    if defined(${opt}_CMAKE_OFF)
CMAKE_ARGS+=	${${opt}_CMAKE_OFF}
.    endif
.  endif
.endfor

.endif
