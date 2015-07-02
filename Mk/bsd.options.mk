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
# ${opt}_QMAKE_ON		When option is enabled, it will add its content to
#				the QMAKE_ARGS.
# ${opt}_QMAKE_OFF		When option is disabled, it will add its content to
#				the QMAKE_ARGS.
#
# ${opt}_USE=	FOO=bar		When option is enabled, it will  enable
#				USE_FOO+= bar
#				If you need more than one option, you can do
#				FOO=bar,baz and you'll get USE_FOO=bar baz
# ${opt}_USE_OFF=	FOO=bar	When option is disabled, it will enable
#				USE_FOO+= bar
#
# For each of:
# ALL_TARGET CATEGORIES CFLAGS CONFIGURE_ENV CONFLICTS CONFLICTS_BUILD
# CONFLICTS_INSTALL CPPFLAGS CXXFLAGS DISTFILES EXTRA_PATCHES INFO
# INSTALL_TARGET LDFLAGS LIBS MAKE_ARGS MAKE_ENV PATCHFILES PATCH_SITES
# PLIST_DIRS PLIST_DIRSTRY PLIST_FILES PLIST_SUB SUB_FILES SUB_LIST USES,
# defining ${opt}_${variable} will add its content to the actual variable when
# the option is enabled.  Defining ${opt}_${variable}_OFF will add its content
# to the actual variable when the option is disabled.
#
# For each of the depends target PKG FETCH EXTRACT PATCH BUILD LIB RUN,
# defining ${opt}_${deptype}_DEPENDS will add its content to the actual
# dependency when the option is enabled.  Defining
# ${opt}_${deptype}_DEPENDS_OFF will add its content to the actual dependency
# when the option is disabled.

##
# Set all the options available for the ports, beginning with the
# global ones and ending with the ones decided by the maintainer.

.if !defined(OPTIONSMKINCLUDED)
OPTIONSMKINCLUDED=	bsd.options.mk

OPTIONS_NAME?=	${PKGORIGIN:S/\//_/}
OPTIONSFILE?=	${PORT_DBDIR}/${UNIQUENAME}/options
OPTIONS_FILE?=	${PORT_DBDIR}/${OPTIONS_NAME}/options

_OPTIONS_FLAGS= ALL_TARGET CATEGORIES CFLAGS CONFIGURE_ENV CONFLICTS \
		CONFLICTS_BUILD CONFLICTS_INSTALL CPPFLAGS CXXFLAGS DISTFILES \
		EXTRA_PATCHES INFO INSTALL_TARGET LDFLAGS LIBS MAKE_ARGS \
		MAKE_ENV PATCHFILES PATCH_SITES PLIST_DIRS PLIST_DIRSTRY \
		PLIST_FILES PLIST_SUB SUB_FILES SUB_LIST USES
_OPTIONS_DEPENDS=	PKG FETCH EXTRACT PATCH BUILD LIB RUN
_OPTIONS_TARGETS=	fetch extract patch configure build install package stage

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

# Remove options the port maintainer doesn't want
.for opt in ${OPTIONS_EXCLUDE_${ARCH}} ${OPTIONS_EXCLUDE} ${OPTIONS_SLAVE} \
	${OPTIONS_EXCLUDE_${OPSYS}}
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
# XXX once WITH_DEBUG is not magic any more, do remove the :NDEBUG from here.
.for opt in ${ALL_OPTIONS:NDEBUG}
.if defined(WITH_${opt})
OPTIONS_WARNINGS+= "WITH_${opt}"
OPTIONS_WARNINGS_SET+=	${opt}
PORT_OPTIONS+=	${opt}
.endif
.if defined(WITHOUT_${opt})
OPTIONS_WARNINGS+= "WITHOUT_${opt}"
OPTIONS_WARNINGS_UNSET+=	${opt}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
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

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

.if defined(NO_OPTIONS_SORT)
ALL_OPTIONS=	${OPTIONS_DEFINE}
.endif

.for target in ${_OPTIONS_TARGETS}
.for prepost in pre post
_OPTIONS_${prepost}_${target}?=
.endfor
.endfor

.for opt in ${COMPLETE_OPTIONS_LIST} ${OPTIONS_SLAVE} ${OPTIONS_EXCLUDE_${ARCH}} ${OPTIONS_EXCLUDE}
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
.      for option in ${${opt}_USE}
_u=		${option:C/=.*//g}
USE_${_u:tu}+=	${option:C/.*=//g:C/,/ /g}
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
.    for configure in CONFIGURE CMAKE QMAKE
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
.      for prepost in pre post
_OPTIONS_${prepost}_${target}+= ${prepost}-${target}-${opt}-on
.      endfor
.    endfor
.  else
.    if defined(${opt}_USE_OFF)
.      for option in ${${opt}_USE_OFF}
_u=		${option:C/=.*//g}
USE_${_u:tu}+=	${option:C/.*=//g:C/,/ /g}
.      endfor
.    endif
.    if defined(${opt}_CONFIGURE_ENABLE)
.      for iopt in ${${opt}_CONFIGURE_ENABLE}
CONFIGURE_ARGS+=	--disable-${iopt:C/=.*//}
.      endfor
.    endif
.    if defined(${opt}_CONFIGURE_WITH)
.      for iopt in ${${opt}_CONFIGURE_WITH}
CONFIGURE_ARGS+=	--without-${iopt:C/=.*//}
.      endfor
.    endif
.    for configure in CONFIGURE CMAKE QMAKE
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
.      for prepost in pre post
_OPTIONS_${prepost}_${target}+= ${prepost}-${target}-${opt}-off
.      endfor
.    endfor
.  endif
.endfor

.endif
