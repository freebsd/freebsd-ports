# $FreeBSD$
#
# Provide support for lua
#
# MAINTAINER: ports@FreeBSD.org
# Usage:
#
# USES+=	lua[:options,...]
#
# Options:
#
#   NN    (e.g. 52)  - specify an allowed Lua version (can use multiple times)
#   NN+   (e.g. 52+) - specify a minimum Lua version (discouraged)
#   -NN   (e.g. -53) - specify a maximum allowed version
#   NN-NN (e.g. 51-53) - specify a range of allowed versions
#
#   flavors	define FLAVOR / FLAVORS as luaNN from the allowed versions
#
#   noflavors	don't use flavors
#
#   module	(implies flavors) specifies that the port is a Lua module
#		(i.e. that it installes files in MODLIBDIR etc.)
#
#   build	add dependency to BUILD_DEPENDS instead of LIB_DEPENDS
#   run		add dependency to RUN_DEPENDS instead of LIB_DEPENDS
#
#   env		define only the LUA_* vars and add them to PLIST_SUB and
#		MAKE_ENV, do not add dependencies or other global state
#
#   core	for building Lua itself
#
# If more than one version is allowed, then the LUA_DEFAULT version (as set
# in DEFAULT_VERSIONS) is chosen if it is in the allowed range, otherwise
# the closest allowed version to the default is chosen, preferring the
# larger version in case of a tie.
#
# But if "flavors" was requested, and FLAVOR is set, we use that version
# exactly. (It is an error to specify a flavor that isn't supported, but
# that is checked in bsd.port.mk, not here.)
#
# LUA_FLAVOR is defined to the desired flavor whether or not "flavors" was
# selected; ports should use this to specify the flavor of dependencies
# which are Lua modules or otherwise Lua-flavored.
#
# It's not generally expected that applications that embed Lua, or apps
# written in Lua, would use USES=lua:flavors. Given that Lua is lightweight
# and does not carry around a whole lot of module ecosystem with it, it is
# best that application ports simply specify the Lua version or range of
# versions that they support, and let the default one or the latest one be
# used. However, they should still use LUA_FLAVOR as needed when specifying
# dependencies.
#
# We assume Lua versions can be represented as 2 digits.
#
.if !defined(_INCLUDE_USES_LUA_MK)
_INCLUDE_USES_LUA_MK=	yes

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
_LUA_VALID_VERSIONS:=	53 52 51
.if defined(_LUA_EXTRA_VER)
_LUA_VALID_VERSIONS+= ${_LUA_EXTRA_VER}
.endif

_LUA_DEFAULT_VERSION:=	${LUA_DEFAULT:S/.//}

# args
_LUA_ARG_FLAVORS:=
_LUA_ARG_MODULE:=
_LUA_ARG_ENV:=
_LUA_ARG_CORE:=
.if ${lua_ARGS:Mmodule}
_LUA_ARG_FLAVORS:=yes
_LUA_ARG_MODULE:=yes
.endif
.if ${lua_ARGS:Mflavors}
_LUA_ARG_FLAVORS:=yes
.endif
.if ${lua_ARGS:Mnoflavors}
_LUA_ARG_FLAVORS:=
.endif
.if ${lua_ARGS:Menv}
_LUA_ARG_ENV:=yes
.endif
.if ${lua_ARGS:Mcore}
_LUA_ARG_CORE:=yes
_LUA_ARG_ENV:=yes
_LUA_ARG_FLAVORS:=
_LUA_ARG_MODULE:=
.endif

# core is for building Lua itself, so it overrides all version checks
.if ${_LUA_ARG_CORE}

_LUA_WANTED_VERSION:=${lua_ARGS:M[1-9][0-9]:[1]}

.  if ${lua_ARGS:M[1-9][0-9]:[#]} != 1
IGNORE= USES=lua:core must also specify exactly one version number
# set to avoid spurious errors below
_LUA_WANTED_VERSION:=${_LUA_DEFAULT_VERSION}
.  endif

_LUA_VALID_VERSIONS:=${_LUA_WANTED_VERSION}
_LUA_WANTED_VERSIONS:=${_LUA_WANTED_VERSION}
_LUA_DEFAULT_VERSION:=${_LUA_WANTED_VERSION}

.endif # _LUA_ARG_CORE

.if ! ${_LUA_VALID_VERSIONS:M${_LUA_DEFAULT_VERSION}}
IGNORE=	Invalid lua version ${LUA_DEFAULT}
.endif

#
# Parse a ver+ argument
#
.if ${lua_ARGS:M??+}
_LUA_MIN_VERSION:=	${lua_ARGS:M??+:S/+//}
_LUA_MAX_VERSION:=	99
.endif

#
# Parse a -ver argument
#
.if ${lua_ARGS:M-??}
_LUA_MAX_VERSION:=	${lua_ARGS:M-??:S/-//}
_LUA_MIN_VERSION:=	0
.endif

#
# Parse a ver-ver argument
#
.if ${lua_ARGS:M??-??}
_LUA_MIN_VERSION:=	${lua_ARGS:M??-??:C/-.*//}
_LUA_MAX_VERSION:=	${lua_ARGS:M??-??:C/.*-//}
.endif

#
# Parse one or more ver arguments
#
.if ${lua_ARGS:M[1-9][0-9]}
.  for _v in ${lua_ARGS:M[1-9][0-9]}
.    if ${_LUA_VALID_VERSIONS:M${_v}}
_LUA_WANTED_VERSIONS+=${_v}
.    endif
.  endfor
.  if empty(_LUA_WANTED_VERSIONS)
IGNORE= USES=lua:nn did not find any valid version number
.  endif
.endif

#
# Resolve version ranges. Append anything within the range to the list of
# wanted versions.
#
.if defined(_LUA_MIN_VERSION) && defined(_LUA_MAX_VERSION)
.  for _v in ${_LUA_VALID_VERSIONS}
.    if ${_LUA_MIN_VERSION} <= ${_v} && ${_LUA_MAX_VERSION} >= ${_v}
_LUA_WANTED_VERSIONS+=${_v}
.    endif
.  endfor
.  if empty(_LUA_WANTED_VERSIONS)
IGNORE= USES=lua:xx-yy did not find any valid version
.  endif
.endif

#
# If no version was specified with any of the ver or ver+ arguments, allow
# all versions.
#
.if empty(_LUA_WANTED_VERSIONS)
_LUA_WANTED_VERSIONS:=	${_LUA_VALID_VERSIONS}
.endif

# The "preferred" version, which must always exist, is defined as the
# closest value to the default version, preferring higher versions in
# case of ties. We find this by constructing values in sequence:
#  VV VV+1 VV-1 VV+2 VV-2 ...
# and then filtering against the allowed versions. The result is the
# final list of "wanted" versions, with the preferred version first.

_LUA_NUM_ASC:=	\
	${:U:range=99:@_v@${${_v} > ${_LUA_DEFAULT_VERSION}:?${_v}:}@}
_LUA_NUM_DESC:=	\
	${:U:range=99:[-1..1]:@_v@${${_v} <= ${_LUA_DEFAULT_VERSION}:?${_v}:}@}
_LUA_NUM_ALL:=	\
	${:U:range=99:@_v@${_LUA_NUM_DESC:[${_v}]} ${_LUA_NUM_ASC:[${_v}]}@}

_LUA_WANTED_VERSIONS:= \
	${_LUA_NUM_ALL:@_v@${_LUA_WANTED_VERSIONS:M${_v}}@}

.if ${_LUA_ARG_FLAVORS}
.  if empty(FLAVORS)
FLAVORS= ${_LUA_WANTED_VERSIONS:S/^/lua/}
.  endif
.  if empty(FLAVOR)
FLAVOR= ${FLAVORS:[1]}
.  endif
_LUA_WANTED_VERSION:= ${FLAVOR:S/^lua//}
.else
_LUA_WANTED_VERSION:= ${_LUA_WANTED_VERSIONS:[1]}
.endif

# If we're building Lua itself, everything should be in $PREFIX. If
# we're building a module or app, then the stuff we're installing goes
# in $PREFIX but references to Lua itself are in $LOCALBASE.
#
# The assumption is the LUA_MOD* directories are where we're going to
# install (this is common for both modules and apps), and so we also
# define LUA_REFMOD* relative to LOCALBASE for use when specifying
# dependencies and so on.

.if ${_LUA_ARG_CORE}
LUA_BASE=${PREFIX}
.else
LUA_BASE=${LOCALBASE}
.endif

LUA_PREFIX=${PREFIX}

#
# Exported variables
#
LUA_VER_STR=		${_LUA_WANTED_VERSION}
LUA_VER=		${_LUA_WANTED_VERSION:S/^5/5./}
LUA_FLAVOR=		${_LUA_WANTED_VERSION:S/^/lua/}

LUA_CMD=		lua${LUA_VER_STR}
LUAC_CMD=		luac${LUA_VER_STR}
LUA_PKGNAMEPREFIX=	lua${LUA_VER_STR}-

LUA_LIBDIR=		${LUA_BASE}/lib
LUA_INCDIR=		${LUA_BASE}/include/lua${LUA_VER_STR}

LUA_MODLIBDIR=		${LUA_PREFIX}/lib/lua/${LUA_VER}
LUA_MODSHAREDIR=	${LUA_PREFIX}/share/lua/${LUA_VER}
LUA_MODDOCSDIR=		${LUA_PREFIX}/share/doc/lua${LUA_VER_STR}
LUA_MODEXAMPLESDIR=	${LUA_PREFIX}/share/examples/lua${LUA_VER_STR}

LUA_REFMODLIBDIR=	${LUA_BASE}/lib/lua/${LUA_VER}
LUA_REFMODSHAREDIR=	${LUA_BASE}/share/lua/${LUA_VER}

PLIST_SUB+=	LUA_MODLIBDIR=${LUA_MODLIBDIR:S,^${LUA_PREFIX}/,,} \
		LUA_MODSHAREDIR=${LUA_MODSHAREDIR:S,^${LUA_PREFIX}/,,} \
		LUA_MODDOCSDIR=${LUA_MODDOCSDIR:S,^${LUA_PREFIX}/,,} \
		LUA_INCDIR=${LUA_INCDIR:S,^${LUA_BASE}/,,} \
		LUA_LIBDIR=${LUA_LIBDIR:S,^${LUA_BASE}/,,} \
		LUA_VER=${LUA_VER} \
		LUA_VER_STR=${LUA_VER_STR}
MAKE_ENV+=	LUA_MODLIBDIR=${LUA_MODLIBDIR} \
		LUA_MODSHAREDIR=${LUA_MODSHAREDIR} \
		LUA_MODDOCSDIR=${LUA_MODDOCSDIR} \
		LUA_INCDIR=${LUA_INCDIR} \
		LUA_LIBDIR=${LUA_LIBDIR} \
		LUA_VER=${LUA_VER} \
		LUA_VER_STR=${LUA_VER_STR}

# if building a module or Lua itself, or if the port defined LUA_DOCSUBDIR,
# then define LUA_DOCSDIR and LUA_EXAMPLESDIR too
.if ${_LUA_ARG_CORE} || ${_LUA_ARG_MODULE}
LUA_DOCSUBDIR?=${PORTNAME}
.endif
.if !empty(LUA_DOCSUBDIR)
LUA_DOCSDIR=	${LUA_MODDOCSDIR}/${LUA_DOCSUBDIR}
LUA_EXAMPLESDIR=${LUA_MODEXAMPLESDIR}/${LUA_DOCSUBDIR}
PLIST_SUB+=	LUA_DOCSDIR=${LUA_DOCSDIR:S,^${LUA_PREFIX}/,,}
PLIST_SUB+=	LUA_EXAMPLESDIR=${LUA_EXAMPLESDIR:S,^${LUA_PREFIX}/,,}
MAKE_ENV+=	LUA_DOCSDIR=${LUA_DOCSDIR}
MAKE_ENV+=	LUA_EXAMPLESDIR=${LUA_EXAMPLESDIR}
.endif

.if empty(_LUA_ARG_ENV)
.  if ${lua_ARGS:Mbuild}
BUILD_DEPENDS+=	${LUA_CMD}:lang/lua${LUA_VER_STR}
.  endif
.  if ${lua_ARGS:Mrun}
RUN_DEPENDS+=	${LUA_CMD}:lang/lua${LUA_VER_STR}
.  endif
.  if !${lua_ARGS:Mbuild} && !${lua_ARGS:Mrun}
LIB_DEPENDS+=	liblua-${LUA_VER}.so:lang/lua${LUA_VER_STR}
.  endif
.endif

.endif
