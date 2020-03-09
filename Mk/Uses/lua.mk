# $FreeBSD$
#
# Provide support for lua
#
# MAINTAINER: ports@FreeBSD.org
# Usage:
#
# USES+=	lua[:version]
#
.if !defined(_INCLUDE_USES_LUA_MK)
_INCLUDE_USES_LUA_MK=	yes

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
_LUA_VALID_VERSIONS=	53 52 51

_LUA_DEFAULT_VERSION=	${LUA_DEFAULT:S/.//}
.if ! ${_LUA_VALID_VERSIONS:M${_LUA_DEFAULT_VERSION}}
IGNORE=	Invalid lua version ${LUA_DEFAULT}
.endif

#
# Parse a ver+ argument
#
.if ${lua_ARGS:M*+}
_LUA_MIN_VERSION:=	${lua_ARGS:M*+:S/+//}
#
# Resolve minimum versions (ver+). Append anything greater or equal than the
# specified minimum version to the list of wanted versions.
#
.  for _v in ${_LUA_VALID_VERSIONS}
.    if ${_LUA_MIN_VERSION} <= ${_v}
_LUA_WANTED_VERSIONS+=${_v}
.    endif
.  endfor
.endif

#
# Parse one or more ver arguments
#
.if ${lua_ARGS:M5[1-3]}
_LUA_WANTED_VERSIONS:=	${lua_ARGS:M5[1-3]}
.endif

#
# If no version was specified with any of the ver or ver+ arguments, set the
# default version.
#
.if !defined(_LUA_WANTED_VERSIONS)
_LUA_WANTED_VERSIONS=	${_LUA_DEFAULT_VERSION}
.endif

#
# Right now we have built a list of potential versions that we may depend on.
# Let's sort them and remove any duplicates. We then locate the highest one
# already installed, if any.
#
.for _v in ${_LUA_WANTED_VERSIONS:O:u}
_LUA_HIGHEST_VERSION:=${_v}
.  if exists(${LOCALBASE}/bin/lua${_v})
_LUA_HIGHEST_INSTALLED_VERSION:=	${_v}
.  endif
.endfor

#
# Depend on the default version if it fits, or the highest installed version,
# or the highest version.
#
.if ${_LUA_WANTED_VERSIONS:M${_LUA_DEFAULT_VERSION}}
_LUA_WANTED_VERSION:=	${_LUA_DEFAULT_VERSION}
.elif defined(_LUA_HIGHEST_INSTALLED_VERSION)
_LUA_WANTED_VERSION:=	${_LUA_HIGHEST_INSTALLED_VERSION}
.else
_LUA_WANTED_VERSION:=	${_LUA_HIGHEST_VERSION}
.endif

#
# Exported variables
#
LUA_VER_STR=		${_LUA_WANTED_VERSION}
LUA_VER=		${_LUA_WANTED_VERSION:S/5/5./}
LUA_CMD=		lua${_LUA_WANTED_VERSION}
LUAC_CMD=		luac${_LUA_WANTED_VERSION}
LUA_INCDIR=		${LOCALBASE}/include/lua${_LUA_WANTED_VERSION}
LUA_MODLIBDIR=		${LOCALBASE}/lib/lua/${LUA_VER}
LUA_MODSHAREDIR=	${LOCALBASE}/share/lua/${LUA_VER}
LUA_LIBDIR=		${LOCALBASE}/lib
LUA_PKGNAMEPREFIX=	lua${LUA_VER_STR}-

PLIST_SUB+=	LUA_MODLIBDIR=${LUA_MODLIBDIR:S,^${LOCALBASE}/,,} \
		LUA_MODSHAREDIR=${LUA_MODSHAREDIR:S,^${LOCALBASE}/,,} \
		LUA_VER=${LUA_VER} \
		LUA_INCDIR=${LUA_INCDIR:S,^${LOCALBASE}/,,} \
		LUA_LIBDIR=${LUA_LIBDIR:S,^${LOCALBASE}/,,} \
		LUA_VER_STR=${LUA_VER_STR}
MAKE_ENV+=	LUA_MODLIBDIR=${LUA_MODLIBDIR} \
		LUA_MODSHAREDIR=${LUA_MODSHAREDIR} \
		LUA_VER=${LUA_VER} \
		LUA_INCDIR=${LUA_INCDIR} \
		LUA_LIBDIR=${LUA_LIBDIR}

.if ${lua_ARGS:Mbuild}
BUILD_DEPENDS+=	${LUA_CMD}:lang/lua${LUA_VER_STR}
.elif ${lua_ARGS:Mrun}
RUN_DEPENDS+=	${LUA_CMD}:lang/lua${LUA_VER_STR}
.else
LIB_DEPENDS+=	liblua-${LUA_VER}.so:lang/lua${LUA_VER_STR}
.endif

.endif
