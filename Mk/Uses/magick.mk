# Handle dependency on ImageMagick
#
# Feature:	magick
# Usage:	USES=magick:ARGS
# Valid ARGS:	[version],[kinds],[flavor]
#
# version	The chooseable versions are <none>, 6 and 7.
#		USES=magick   -- depend on ${IMAGEMAGICK_DEFAULT} (default)
#		USES=magick:6 -- depend on ImageMagick6
#		USES=magick:7 -- depend on ImageMagick7
#
# flavor	The flavors are <none> and nox11
# 		USES=magick       -- depend on the default flavor (default)
# 		USES=magick:nox11 -- depend on the nox11 flavor
#
# kinds		The dependency kinds are <none>, lib, build, run and test
#		USES=magick       -- add a LIB_DEPENDS (default)
#		USES=magick:lib   -- add a LIB_DEPENDS
#		USES=magick:build -- add a BUILD_DEPENDS
#		USES=magick:run   -- add a RUN_DEPENDS
#		USES=magick:test  -- add a TEST_DEPENDS
#		USES=build,run    -- add a BUILD_- and RUN_DEPENDS
#
# In short, on a default ports tree
# 	USES=magick
# is equivalent to
# 	USES=magick:7,lib
#
# MAINTAINER: tcberner@FreeBSD.org
#

.if ! defined(_INCLUDE_USES_MAGICK_MK)
_INCLUDE_USES_MAGICK_MK=	YES

#=== Version selection ===
_magick_versions=	6 7

_magick_version=	#
.  for _ver in ${_magick_versions:O:u}
.    if ${magick_ARGS:M${_ver}}
.      if empty(_magick_version)
_magick_version=	${_ver}
.      else
IGNORE=		Incorrect USES=magick:${magick_ARGS} - multiple versions defined
.      endif
.    endif
.  endfor
# Fallback to the default version
.if empty(_magick_version)
_magick_version=	${IMAGEMAGICK_DEFAULT}
.endif

#=== Flavor selection ===
_magick_flavors=	nox11
_magick_flavor=		#
.  for _flavor in ${_magick_flavors:O:u}
.    if ${magick_ARGS:M${_flavor}}
.      if empty(_magick_flavor)
_magick_flavor=	-${_flavor}
.      else
IGNORE=		Incorrect USES=magick:${magick_ARGS} - multiple flavors defined
.      endif
.    endif
.  endfor

#=== Dependeny selection ===
_magick_depends=	lib build run test
_magick_depend=		#
.  for _depend in ${_magick_depends:O:u}
.    if ${magick_ARGS:M${_depend}}
_magick_depend+=	${_depend}
.    endif
.  endfor
.if empty(_magick_depend)
_magick_depend=		lib
.endif

#=== Dependency setup ===
_MAGICK_PORT=	graphics/ImageMagick${_magick_version}${_magick_flavor}
_MAGICK_LIB=	libMagick++-${_magick_version}.so
_MAGICK_PKG=	ImageMagick${_magick_version}${_magick_flavor}

_MAGICK_BUILD_DEPENDS=	${_MAGICK_PKG}>=${_magick_version}:${_MAGICK_PORT}
_MAGICK_LIB_DEPENDS=	${_MAGICK_LIB}:${_MAGICK_PORT}
_MAGICK_RUN_DEPENDS=	${_MAGICK_PKG}>=${_magick_version}:${_MAGICK_PORT}
_MAGICK_TEST_DEPENDS=	${_MAGICK_PKG}>=${_magick_version}:${_MAGICK_PORT}

#=== Actual dependency creation ===
.  for _kind in ${_magick_depend}
${_kind:tu}_DEPENDS+=	${_MAGICK_${_kind:tu}_DEPENDS}
.  endfor

.endif
