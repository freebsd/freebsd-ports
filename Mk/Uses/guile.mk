# Provide support for guile
#
# MAINTAINER: ports@FreeBSD.org
# Usage:
#
# USES+=	guile[:options,...]
#
# Options:
#
#   X.Y		specify a Guile version, e.g. 2.2 or 3.0
#
#   flavors	define FLAVOR / FLAVORS as guileX from the allowed versions
#
#   build	add dependency to BUILD_DEPENDS instead of LIB_DEPENDS
#   run		add dependency to RUN_DEPENDS instead of LIB_DEPENDS
#
#   env		define only the GUIL[DE]_* vars and add them to PLIST_SUB,
#		do not add dependencies or other global state
#
#   alias	add BINARY_ALIAS for guile tools
#
#   conflicts	add GUILE_NEWER_PKGS to CONFLICTS_BUILD, this tries to
#		ensure that non-clean builds of programs that insist on
#		using the latest available version (there are a surprising
#		number of these) will fail if the selected version is wrong.
#
#   noextra	don't add _GUILE_EXTRA_LIB_DEPENDS
#
#   nopkgconf	don't add to PKGCONFIG_PATHS
#
#   nocmds	don't add GUILE_*CMD* to CONFIGURE_ENV and MAKE_ENV
#		(but still define them)
#
# Variables defined for use by the port:
#
#   GUILE_VER		e.g. 2.2
#   GUILE_SFX		e.g. 2  (be careful, consider the possibility of 3.1)
#   GUILE_FLAVOR	e.g. guile22
#   GUILE_PORT		e.g. lang/guile2
#   GUILE_CMD		name of guile binary, e.g. guile-2.2
#   GUILE_*_CMD		name of guile-* binary (legacy)
#   GUILD_CMD		name of guild binary, e.g. guild-2.2
#   GUIL*_CMDPATH	full paths of commands
#   GUILE_PKGCONFIG_DIR	directory for version-specific .pc files
#			(relative to PREFIX or LOCALBASE)
#   GUILE_PREFIX
#   GUILE_GLOBAL_SITE_DIR
#   GUILE_SITE_DIR
#   GUILE_SITE_CCACHE_DIR
#   GUILE_DOCS_DIR	where to put version-specific docs
#   GUILE_EXAMPLES_DIR	where to put version-specific examples
#   GUILE_INFO_PATH	a suitable value for INFO_PATH
#
# (the _DIR vars are relativized and added to PLIST_SUB without the
# _DIR suffix)
#
.if !defined(_INCLUDE_USES_GUILE_MK)
_INCLUDE_USES_GUILE_MK=	yes

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
_GUILE_VALID_VERSIONS:=	1.8 2.2 3.0
.  if defined(_GUILE_EXTRA_VER)
_GUILE_VALID_VERSIONS+= ${_GUILE_EXTRA_VER}
.  endif

_GUILE_DEFAULT_VERSION:= ${GUILE_DEFAULT}

.  if ! ${_GUILE_VALID_VERSIONS:M${_GUILE_DEFAULT_VERSION}}
IGNORE=	Invalid default Guile version ${GUILE_DEFAULT}
.  endif

# args. Allow a list of numeric versions
_GUILE_ARG_VERSIONS:=	${guile_ARGS:M[1-9].[0-9]}

# We anticipate which args will be almost universally required
# and define them negatively. In practice "alias" is needed a lot
# thanks to makefile assumptions, but it's intrusive enough that
# we require it to be stated explicitly.
_GUILE_ARG_NAMES:=	flavors build run env alias conflicts \
			noextra nopkgconf nocmds

# Define an 0/1 flag for each arg
.  for _v in ${_GUILE_ARG_NAMES}
.    if ${_v:Mno*}
_GUILE_ARG_${_v:tu:S/^NO//}:=${"${guile_ARGS:M${_v}}":?0:1}
.    else
_GUILE_ARG_${_v:tu}:=${"${guile_ARGS:M${_v}}":?1:0}
.    endif
.  endfor

#
# Parse ver arguments
#
# If multiple versions are specified, we are either doing flavors (in
# which case we build them all) or we are supposed to pick just one, in
# which case we pick the default version if it was specified, otherwise
# the highest.
#
_GUILE_CHOSEN_VER:=
_GUILE_REQUESTED_VERS:=

# check args for validity first
.  for _v in ${_GUILE_ARG_VERSIONS}
.    if ! ${_GUILE_VALID_VERSIONS:M${_v}}
IGNORE=	Invalid Guile version ${_v}
.    else
_GUILE_REQUESTED_VERS+= ${_v}
.    endif
.  endfor

.  if ${_GUILE_ARG_FLAVORS}

# default to all versions (unlikely in practice)
.    if empty(_GUILE_REQUESTED_VERS)
_GUILE_REQUESTED_VERS:= ${_GUILE_VALID_VERSIONS}
.    endif

# Note that we organize the FLAVORS list so that the
# first (default) one corresponds to the default version.
.    if empty(FLAVORS)
FLAVORS=${_GUILE_DEFAULT_VERSION:S/.//:S/^/guile/} \
	${_GUILE_REQUESTED_VERS:N${_GUILE_DEFAULT_VERSION}:S/.//:S/^/guile/}
.    endif
# User may have specified this; we must respect that.
.    if empty(FLAVOR)
FLAVOR= ${FLAVORS:[1]}
.    endif
# Translate the selected (possibly by the user) flavor back to the
# corresponding Guile version.
_GUILE_CHOSEN_VER:= ${FLAVOR:S/^guile//:C/./&./}

.  else # !${_GUILE_ARG_FLAVORS}

# default to default version
.    if empty(_GUILE_REQUESTED_VERS)
_GUILE_REQUESTED_VERS:= ${_GUILE_DEFAULT_VERSION}
.    endif

# Find default version, or highest. (We abuse alphabetic sort here.)
_GUILE_CHOSEN_VER:= ${_GUILE_REQUESTED_VERS:M${_GUILE_DEFAULT_VERSION}}
.    if empty(_GUILE_CHOSEN_VER)
_GUILE_CHOSEN_VER:= ${_GUILE_REQUESTED_VERS:O:[-1]}
.    endif

.  endif # ${_GUILE_ARG_FLAVORS}

# _GUILE_CHOSEN_VER is now the desired version in all cases.
#
# The GUILE_VER / GUILE_SFX here is the existing usage, but if a
# version 3.1 comes along, that'll all need to be revisited. (So
# we discourage the use of GUILE_SFX for anything important.)
#
# GUILE_VER= 3.0  (for example)
# GUILE_SFX= 3
# GUILE_FLAVOR= guile30
#
# GUILE_OTHER/NEWER_PKGS is defined such that it can be placed in
# CONFLICTS_BUILD for ports that use non-overridable version searches.
# This gives a proper diagnostic for non-clean builds.

GUILE_VER=	${_GUILE_CHOSEN_VER}
GUILE_SFX=	${_GUILE_CHOSEN_VER:R}

GUILE_OTHER_PKGS:=${_GUILE_VALID_VERSIONS:@_v@${${_v} != ${_GUILE_CHOSEN_VER}:?guile${_v:R}:}@}
GUILE_NEWER_PKGS:=${_GUILE_VALID_VERSIONS:@_v@${${_v} > ${_GUILE_CHOSEN_VER}:?guile${_v:R}:}@}

.  if ${_GUILE_ARG_CONFLICTS}
CONFLICTS_BUILD+=${GUILE_NEWER_PKGS}
.  endif

GUILE_PORT=	lang/guile${GUILE_SFX}
GUILE_FLAVOR=	guile${GUILE_VER:S/.//}

GUILE_PREFIX=	${PREFIX}

GUILE_GLOBAL_SITE_DIR=	${GUILE_PREFIX}/share/guile/site
GUILE_SITE_DIR=		${GUILE_GLOBAL_SITE_DIR}/${GUILE_VER}
GUILE_SITE_CCACHE_DIR=	${GUILE_PREFIX}/lib/guile/${GUILE_VER}/site-ccache
GUILE_DOCS_DIR=		${GUILE_PREFIX}/share/doc/${GUILE_FLAVOR}
GUILE_EXAMPLES_DIR=	${GUILE_PREFIX}/share/examples/${GUILE_FLAVOR}
GUILE_INFO_PATH=	share/info/guile${GUILE_SFX}

_GUILE_CMDNAMES:=	guile guile-snarf guile-config guile-tools
.  if ${GUILE_SFX} > 1
_GUILE_CMDNAMES+=	guild
.  endif

.  for _c in ${_GUILE_CMDNAMES}
${_c:S/-/_/:tu}_CMD:=	${_c}-${GUILE_VER}
${_c:S/-/_/:tu}_CMDPATH:=	${LOCALBASE}/bin/${_c}-${GUILE_VER}
.  endfor

PLIST_SUB+=	GUILE_VER=${GUILE_VER} GUILE_SFX=${GUILE_SFX} \
		GUILE_SITE=${GUILE_SITE_DIR:S,^${GUILE_PREFIX}/,,} \
		GUILE_GLOBAL_SITE=${GUILE_GLOBAL_SITE_DIR:S,^${GUILE_PREFIX}/,,} \
		GUILE_SITE_CCACHE=${GUILE_SITE_CCACHE_DIR:S,^${GUILE_PREFIX}/,,} \
		GUILE_DOCS=${GUILE_DOCS_DIR:S,^${GUILE_PREFIX}/,,} \
		GUILE_EXAMPLES=${GUILE_EXAMPLES_DIR:S,^${GUILE_PREFIX}/,,}

# This may reduce the need for BINARY_ALIAS
GUILE_ENV=	${_GUILE_CMDNAMES:tu:S/-/_/:@t@${t}=${${t}_CMDPATH}@}

# XXX XXX XXX
#
# This all assumes that the underlying Guile >= 2 is built with the
# threading option, which is on by default.

_GUILE_1.8_EXTRA_LIB_DEPENDS= \
	libgmp.so:math/gmp \
	libltdl.so:devel/libltdl
_GUILE_2.2_EXTRA_LIB_DEPENDS= \
	libgc-threaded.so:devel/boehm-gc-threaded
_GUILE_3.0_EXTRA_LIB_DEPENDS= \
	libgc-threaded.so:devel/boehm-gc-threaded

.  if ${_GUILE_ARG_EXTRA}
_GUILE_EXTRA_LIB_DEPENDS= ${_GUILE_${GUILE_VER}_EXTRA_LIB_DEPENDS}
.  else
_GUILE_EXTRA_LIB_DEPENDS?=
.  endif

.  if !${_GUILE_ARG_ENV}
.    if ${_GUILE_ARG_BUILD}
BUILD_DEPENDS+=	${GUILE_CMD}:${GUILE_PORT}
.    endif
.    if ${_GUILE_ARG_RUN}
RUN_DEPENDS+=	${GUILE_CMD}:${GUILE_PORT}
.    endif
.    if !${_GUILE_ARG_BUILD} && !${_GUILE_ARG_RUN}
.      if ${GUILE_SFX} > 1
LIB_DEPENDS+=	libguile-${GUILE_VER}.so:${GUILE_PORT} ${_GUILE_EXTRA_LIB_DEPENDS}
.      else
LIB_DEPENDS+=	libguile.so:${GUILE_PORT} ${_GUILE_EXTRA_LIB_DEPENDS}
.      endif
.    endif
.    if ${_GUILE_ARG_CMDS}
.      if ${_GUILE_ARG_ALIAS}
# If we're doing binary-alias, then only add GUILE itself to the
# environment, not the build-only tools. This helps when dealing with
# broken configure scripts that respect e.g. GUILE_CONFIG but then
# barf on the output if the program name has a suffix.
CONFIGURE_ENV+=	GUILE=${GUILE_CMDPATH}
MAKE_ENV+=	GUILE=${GUILE_CMDPATH}
.      else
CONFIGURE_ENV+=	${GUILE_ENV}
MAKE_ENV+=	${GUILE_ENV}
.      endif
.    endif # ${_GUILE_ARG_CMDS}
CONFIGURE_ENV+=	GUILE_EFFECTIVE_VERSION=${GUILE_VER}
.  endif # !${_GUILE_ARG_ENV}

.  if ${_GUILE_ARG_ALIAS}
BINARY_ALIAS+=	${_GUILE_CMDNAMES:@t@${t}=${${t:tu:S/-/_/}_CMD}@}
.  endif

.  if ${_GUILE_ARG_PKGCONF}
GUILE_PKGCONFIG_DIR:=	libdata/pkgconfig/guile/${GUILE_VER}
PKGCONFIG_PATHS+=	${LOCALBASE}/${GUILE_PKGCONFIG_DIR}
PLIST_SUB+=		GUILE_PKGCONFIG_DIR=${GUILE_PKGCONFIG_DIR}
.  endif

.endif
