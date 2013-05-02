#-*- tab-width: 4; -*-
# $FreeBSD$
# Global options
#
# OPTIONS_DEFINE		- List of options this ports accept
# OPTIONS_DEFINE_${ARCH}	- List of options this ports accept and are
#				specific to ${ARCH}
# OPTIONS_DEFAULT		- List of options activated by default
# OPTIONS_DEFAULT_${ARCH}	- List of options activated by default for a
#				given arch
#
# OPTIONS_EXCLUDE		- List of options unsupported (useful for slave ports)
# OPTIONS_EXCLUDE_${ARCH}	- List of options unsupported on a given ${ARCH}
# ${OPTION}_DESC		- Description the the ${OPTION}
#
# OPTIONS_SINGLE		- List of single-choice grouped options: 1 and
# 				  only 1 among N
# OPTIONS_RADIO			- List of radio-choice grouped options: 0 or 1
#				  among N
# OPTIONS_MULTI			- List of multiple-choice grouped options: at
#				  least 1 among N
# OPTIONS_GROUP			- List of group-choice grouped options: 0 or
#				  more among N
#
# OPTIONS_SINGLE_${NAME}	- List of OPTIONS grouped as single choice (for
#				the single named as ${NAME} as defined in
#				OPTIONS_SINGLE)
# OPTIONS_RADIO_${NAME}		- List of OPTIONS grouped as radio choice (for
#				the radio named as ${NAME} as defined in
#				OPTIONS_RADIO)
# OPTIONS_MULTI_${NAME}		- List of OPTIONS grouped as multiple-choice
#				(for the multi named as ${NAME} as defined in
#				OPTIONS_MULTI)
# OPTIONS_GROUP_${NAME}		- List of OPTIONS grouped as group-choice (for
#				the group named as ${NAME} as defined in
#				OPTIONS_GROUP)
#
# WITH				Set options from the command line
# WITHOUT			Unset options from the command line
#
# OPTIONS_SLAVE			This is designed for slave ports, it removes an option
# 				from the options list inherited from the master port
# 				and it always adds it to PORT_OPTIONS meaning activated

##
# Set all the options available for the ports, beginning with the
# global ones and ending with the ones decided by the maintainer.
# Options global to the entire ports tree
.if !defined(OPTIONSMKINCLUDED)
OPTIONSMKINCLUDED=	bsd.options.mk

OPTIONSFILE?=	${PORT_DBDIR}/${UNIQUENAME}/options

#ALL_OPTIONS=	DOCS \
#		NLS

# Set the default values for the global options, as defined by portmgr
.if !defined(NOPORTDOCS)
PORT_OPTIONS+=	DOCS
.endif

.if !defined(WITHOUT_NLS)
PORT_OPTIONS+=	NLS
.endif

# Set the default values for the global options, as defined by portmgr
.if !defined(NOPORTEXAMPLES)
PORT_OPTIONS+=	EXAMPLES
.endif

# Activate IPV6 by default
PORT_OPTIONS+=	IPV6

# Exclude per arch options
_ALL_EXCLUDE=	${OPTIONS_EXCLUDE_${ARCH}} ${OPTIONS_EXCLUDE} ${OPTIONS_SLAVE}

# Add per arch options
.for opt in ${OPTIONS_DEFINE_${ARCH}}
.if empty(OPTIONS_DEFINE:M${opt})
OPTIONS_DEFINE+=	${opt}
.endif
.endfor

# Add per arch defaults
.for opt in ${OPTIONS_DEFAULT_${ARCH}}
.if empty(OPTIONS_DEFAULT:M${opt})
OPTIONS_DEFAULT+=	${opt}
.endif
.endfor

# Append options set by the port Makefile
.for opt in ${OPTIONS_DEFINE}
ALL_OPTIONS+=	${opt}
.endfor

ALL_OPTIONS:=	${ALL_OPTIONS:O:u}

#XXX  to kill when old option framework won't be used anymore
.if defined(OPTIONS)
NO_OPTIONS_SORT=	yes
.  undef optname
.  for O in ${OPTIONS:S|\#|\\\#|g}
opt:=	${O}
.    if !defined(optname)
optname:=	${O}
ALL_OPTIONS+=	${O}
.if !defined(OPTIONS_DEFINE) || empty(OPTIONS_DEFINE:M${O})
OPTIONS_DEFINE+=	${O}
.endif
PORT_OPTIONS+=	${O}
.    elif !defined(optdesc)
optdesc:=	${opt}
${optname}_DESC:=	${opt:S|"||g}
.    else
.      if ${opt:L} == off
.        if defined(PORT_OPTIONS) && defined(optname)
NO_OPTIONS+=	${optname}
NO_OPTIONS:=	${NO_OPTIONS:O:u}
.        else
.        endif
.      endif
.      undef optname
.      undef optdesc
.    endif
.  endfor
.  if defined(NO_OPTIONS)
.    for O in ${NO_OPTIONS}
PORT_OPTIONS:=	 ${PORT_OPTIONS:N${O}}
.    endfor
.  endif
#.  undef NO_OPTIONS
.endif
#XXX end of compatibility

ALL_OPTIONS:=	${ALL_OPTIONS:O:u}
OPTIONS_DEFAULT:=	${OPTIONS_DEFAULT:O:u}

# Remove global options the port maintainer doesn't want
.for opt in ${_ALL_EXCLUDE}
OPTIONS_DEFAULT:=	${OPTIONS_DEFAULT:N${opt}}
ALL_OPTIONS:=		${ALL_OPTIONS:N${opt}}
.endfor

# Remove illegal per-arch options
.for opt in ${_ALL_EXCLUDE}
.  for single in ${OPTIONS_SINGLE}
OPTIONS_SINGLE_${single}:=	${OPTIONS_SINGLE_${single}:N${opt}}
.  endfor
.  for radio in ${OPTIONS_RADIO}
OPTIONS_RADIO_${radio}:=	${OPTIONS_RADIO_${radio}:N${opt}}
.  endfor
.  for multi in ${OPTIONS_MULTI}
OPTIONS_MULTI_${multi}:=	${OPTIONS_MULTI_${multi}:N${opt}}
.  endfor
.  for group in ${OPTIONS_GROUP}
OPTIONS_GROUP_${group}:=	${OPTIONS_GROUP_${group}:N${opt}}
.  endfor
.endfor

# complete list
COMPLETE_OPTIONS_LIST=	${ALL_OPTIONS}
.for single in ${OPTIONS_SINGLE}
COMPLETE_OPTIONS_LIST+=	${OPTIONS_SINGLE_${single}}
.endfor
.for radio in ${OPTIONS_RADIO}
COMPLETE_OPTIONS_LIST+=	${OPTIONS_RADIO_${radio}}
.endfor
.for multi in ${OPTIONS_MULTI}
COMPLETE_OPTIONS_LIST+=	${OPTIONS_MULTI_${multi}}
.endfor
.for group in ${OPTIONS_GROUP}
COMPLETE_OPTIONS_LIST+= ${OPTIONS_GROUP_${group}}
.endfor

## Now create the list of activated options
.if defined(OPTIONS_OVERRIDE)
# Special case $OPTIONS_OVERRIDE; if it is defined forget about anything done
# before
PORT_OPTIONS:=	${OPTIONS_OVERRIDE}
.else

## Set default options defined by the port maintainer
.  for opt in ${OPTIONS_DEFAULT}
PORT_OPTIONS+=	${opt}
.  endfor
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}

## Set system-wide defined options (set by user in make.conf)
.  for opt in ${OPTIONS_SET}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
.    endif
.  endfor
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}

## Remove the options excluded system-wide (set by user in make.conf)
.  for opt in ${OPTIONS_UNSET}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
.  endfor

## Set the options specified per-port (set by user in make.conf)
.  for opt in ${${UNIQUENAME}_SET}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
.    endif
.  endfor
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}

## Unset the options excluded per-port (set by user in make.conf)
.  for opt in ${${UNIQUENAME}_UNSET}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
.  endfor

## options files (from dialog)
.  if exists(${OPTIONSFILE}) && !make(rmconfig)
.  include "${OPTIONSFILE}"
.  endif
.  if exists(${OPTIONSFILE}.local)
.  include "${OPTIONSFILE}.local"
.  endif

### convert WITH and WITHOUT found in make.conf or reloaded from old optionsfile
.for opt in ${ALL_OPTIONS}
.if defined(WITH_${opt})
PORT_OPTIONS+=	${opt}
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}
.endif
.if defined(WITHOUT_${opt})
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
.endif
.endfor

## Finish by using the options set by the port config dialog, if any
.  for opt in ${OPTIONS_FILE_SET}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
.    endif
.  endfor
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}

.for opt in ${OPTIONS_FILE_UNSET}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
.endfor
.undef opt

.endif

## FORCE
## Set system-wide defined options (set by user in make.conf)
.  for opt in ${OPTIONS_SET_FORCE}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
.    endif
.  endfor
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}

## Remove the options excluded system-wide (set by user in make.conf)
.  for opt in ${OPTIONS_UNSET_FORCE}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
.  endfor

## Set the options specified per-port (set by user in make.conf)
.  for opt in ${${UNIQUENAME}_SET_FORCE}
.    if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
.    endif
.  endfor
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}

## Unset the options excluded per-port (set by user in make.conf)
.  for opt in ${${UNIQUENAME}_UNSET_FORCE}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
.  endfor


## Cmdline always win over the rest
.for opt in ${WITH}
.  if !empty(COMPLETE_OPTIONS_LIST:M${opt})
PORT_OPTIONS+=	${opt}
.  endif
.endfor
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}

.for opt in ${WITHOUT}
PORT_OPTIONS:=	${PORT_OPTIONS:N${opt}}
.endfor

.for opt in ${OPTIONS_SLAVE}
PORT_OPTIONS+=	${opt}
.endfor
.undef opt

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
_SORTED_OPTIONS:=	${ALL_OPTIONS}
ALL_OPTIONS:=
.for opt in ${OPTIONS_DEFINE}
.if ${_SORTED_OPTIONS:M${opt}}
ALL_OPTIONS+=	${opt}
.endif
.endfor
.undef opt
.undef _SORTED_OPTIONS
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
.      undef opt
.endfor
.endif
###
