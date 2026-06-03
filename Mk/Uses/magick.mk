# Handle dependency on ImageMagick
#
# Feature:	magick
# Usage:	USES=magick:ARGS
# Valid ARGS:	[version],[flavor],[kinds]
#
# version	The chooseable versions are <none>, 6 and 7.
#		USES=magick   -- depend on version from DEFAULT_VERSIONS
#		USES=magick:6 -- depend on ImageMagick6
#		USES=magick:7 -- depend on ImageMagick7
#
# flavor	The flavors are <none>, x11 and nox11
# 		USES=magick       -- depend on flavor from DEFAULT_VERSIONS
# 		USES=magick:x11   -- depend on the x11 flavor
# 		USES=magick:nox11 -- depend on the nox11 flavor
#
# kinds		The dependency kinds are <none>, lib, build, run and test
#		USES=magick           -- add a LIB_DEPENDS (default)
#		USES=magick:lib       -- add a LIB_DEPENDS
#		USES=magick:build     -- add a BUILD_DEPENDS
#		USES=magick:run       -- add a RUN_DEPENDS
#		USES=magick:test      -- add a TEST_DEPENDS
#		USES=magick:build,run -- add a BUILD_- and RUN_DEPENDS
#
# In short, on a default ports tree without custom DEFAULT_VERSIONS
# 	USES=magick
# is equivalent to
# 	USES=magick:7,x11,lib
#
# Make sure to only add arguments strictly needed, as [version] and [flavor]
# will override user configuration in DEFAULT_VERSIONS.
#
# MAINTAINER: ports@FreeBSD.org
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
.  if empty(_magick_version)
_magick_version=	${IMAGEMAGICK_DEFAULT:C/-.*//}
.  endif
.  if !${_magick_versions:M${_magick_version}}
IGNORE=		Invalid version of ImageMagick: "${_magick_version}"
.  endif

#=== Flavor selection ===
_magick_flavors=	x11 nox11
_magick_flavor=		#
_magick_portflavor=	#
_magick_pkgflavor=	#
.  for _flavor in ${_magick_flavors:O:u}
.    if ${magick_ARGS:M${_flavor}}
.      if empty(_magick_flavor)
_magick_flavor=	${_flavor}
.      else
IGNORE=		Incorrect USES=magick:${magick_ARGS} - multiple flavors defined
.      endif
.    endif
.  endfor
# Fallback to the default flavor
.  if empty(_magick_flavor) && ${IMAGEMAGICK_DEFAULT:M*-*}
_magick_flavor=		${IMAGEMAGICK_DEFAULT:C/.*-//}
.  endif
.  if !empty(_magick_flavor)
.    if !${_magick_flavors:M${_magick_flavor}}
IGNORE=		Invalid flavor of ImageMagick: "${_magick_flavor}"
.    else
_magick_portflavor=	@${_magick_flavor}
.      if ${_magick_flavor:Mnox11}
_magick_pkgflavor=	-nox11
.      endif
.    endif
.  endif

#=== Dependency selection ===
_magick_depends=	lib build run test
_magick_depend=		#
.  for _depend in ${_magick_depends:O:u}
.    if ${magick_ARGS:M${_depend}}
_magick_depend+=	${_depend}
.    endif
.  endfor
.  if empty(_magick_depend)
_magick_depend=		lib
.  endif

#=== Check for invalid arguments ===
_magick_unknown_args:=	${magick_ARGS:N${_magick_version}:N${_magick_flavor}}
.  for _depend in ${_magick_depend}
_magick_unknown_args:=	${_magick_unknown_args:N${_depend}}
.  endfor
.  if !empty(_magick_unknown_args)
IGNORE=		Invalid USES=magick - unsupported argument(s): ${_magick_unknown_args}
.  endif

#=== Dependency setup ===
_MAGICK_PORT=	graphics/ImageMagick${_magick_version}${_magick_portflavor}
_MAGICK_LIB=	libMagick++-${_magick_version}.so
_MAGICK_PKG=	ImageMagick${_magick_version}${_magick_pkgflavor}

_MAGICK_BUILD_DEPENDS=	${_MAGICK_PKG}>=${_magick_version}:${_MAGICK_PORT}
_MAGICK_LIB_DEPENDS=	${_MAGICK_LIB}:${_MAGICK_PORT}
_MAGICK_RUN_DEPENDS=	${_MAGICK_PKG}>=${_magick_version}:${_MAGICK_PORT}
_MAGICK_TEST_DEPENDS=	${_MAGICK_PKG}>=${_magick_version}:${_MAGICK_PORT}

#=== Actual dependency creation ===
.  for _kind in ${_magick_depend}
${_kind:tu}_DEPENDS+=	${_MAGICK_${_kind:tu}_DEPENDS}
.  endfor

.endif
