#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.sdl.mk - Support for SDL-based ports.
#
# Created by: Edwin Groothuis <edwin@freebsd.org>
#
# For FreeBSD committers:
# - Changes in the version number of the shared libraries are encouraged.
# - For the rest, please try to run them via the maintainer but feel free
#   to commit themselves if nothing breaks.
#
# For ports-developers:
# If your port needs SDL or one of the SDL modules, you can easily
# include them with the "USE_SDL=" statement. For example if you need
# the standard SDL and SDL_sound, use "USE_SDL=sdl sound" and the
# required libraries are included in your LIB_DEPENDS.
#
# If you want to check for the availability for certain SDL ports, you
# can set WANT_SDL and run it through bsd.port.pre.mk:
#	WANT_SDL=	yes
#	USE_SDL=	sdl
#	.include <bsd.port.pre.mk>
#	.if ${HAVE_SDL:Mgraphics}
#	USE_SDL+=	graphics
#	.endif
#	.include <bsd.port.post.mk>
# Run "make -V USE_SDL" to see which libs are asked for at the end.
#

#
# $FreeBSD$
#

SDL_Include_MAINTAINER=		edwin@FreeBSD.org

#
# These are the current supported SDL modules
#
_USE_SDL_ALL=	gfx gui image mixer ldbad mm net sdl sound ttf

#
# Variables used to determine what is needed:
# _VERSION_xxx	version of the shared library (required)
# _SUBDIR_xxx	subdirectory below ${PORTSDIR} (required)
# _PORTDIR_xxx	subdirectory below ${PORTSDIR}/${_SUBDIR_xxx}, default sdl_xxx
# _LIB_xxx		name of the shared lib, default SDL_xxx
# _REQUIRES_xxx	also needs these SDL libraries
# 

_VERSION_gfx=	10
_SUBDIR_gfx=	graphics
_REQUIRES_gfx=	sdl

_VERSION_gui=	0
_SUBDIR_gui=	x11-toolkits
_REQUIRES_gui=	sdl image ttf

_VERSION_image=	10
_SUBDIR_image=	graphics
_REQUIRES_image=sdl

_VERSION_ldbad=	4
_SUBDIR_ldbad=	devel
_REQUIRES_ldbad=sdl

_VERSION_mixer=	2
_SUBDIR_mixer=	audio
_REQUIRES_mixer=sdl

_VERSION_mm=	8
_SUBDIR_mm=		devel
_LIB_mm=		SDLmm
_PORTDIR_mm=	sdlmm
_REQUIRES_mm=	sdl

_VERSION_net=	0
_SUBDIR_net=	net
_REQUIRES_net=	sdl

_VERSION_sdl=	5
_SUBDIR_sdl=	devel
_LIB_sdl=		SDL-1.1
_PORTDIR_sdl=	sdl12

_VERSION_sound=	1
_SUBDIR_sound=	audio
_LIB_sound=		SDL_sound-1.0
_REQUIRES_sound=sdl

_VERSION_ttf=	3
_SUBDIR_ttf=	graphics
_REQUIRES_ttf=	sdl

#
# Update the variables if they need the default values.
#
.for component in ${_USE_SDL_ALL}
. if !defined(_LIB_${component})
_LIB_${component}=SDL_${component}
. endif
. if !defined(_PORTDIR_${component})
_PORTDIR_${component}=sdl_${component}
. endif
. if !defined(_REQUIRES_${component})
_REQUIRES_${component}=
. endif
.endfor

#
# If WANT_SDL is defined, check for the available libraries
#
.if !defined(AFTERPORTMK)
.if !defined(SDL_Include_pre)

SDL_Include_pre=	bsd.sdl.mk

HAVE_SDL?=
.if defined(WANT_SDL)
.for component in ${_USE_SDL_ALL}
.if exists(${LOCALBASE}/lib/lib${_LIB_${component}}.so.${_VERSION_${component}})
HAVE_SDL+=	${component}
.endif
.endfor
.endif

.endif
.endif

#
# If USE_SDL is defined, make dependencies for the libraries
#
.if !defined(BEFOREPORTMK)
.if !defined(SDL_Include_post)
.if defined(USE_SDL)

SDL_Include_post=	bsd.sdl.mk

#
# Keep some backward compatibility
#
.if ${USE_SDL}=="yes"
USE_SDL=	sdl
.endif

#
# Check if all the values given in USE_SDL are valid.
#
_USE_SDL=
.for component in ${USE_SDL}
. if ${_USE_SDL_ALL:M${component}}==""
BROKEN=	"Unknown SDL component ${component}"
. endif
_USE_SDL+=	${_REQUIRES_${component}} ${component}
.endfor

#
# Uniquefy[sp] the list of libs required
#
__USE_SDL=
.for component in ${_USE_SDL}
. if ${__USE_SDL:M${component}}==""
__USE_SDL+= ${component}
. endif
.endfor

#
# Finally make the list of libs required
#
.for component in ${__USE_SDL}
LIB_DEPENDS+=	${_LIB_${component}}.${_VERSION_${component}}:${PORTSDIR}/${_SUBDIR_${component}}/${_PORTDIR_${component}}
.endfor

#
# "Normal" dependencies and variables
#
BUILD_DEPENDS+=	${SDL_CONFIG}:${PORTSDIR}/${_SUBDIR_sdl}/${_PORTDIR_sdl}
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV+=	SDL_CONFIG=${SDL_CONFIG}
MAKE_ENV+=		SDL_CONFIG=${SDL_CONFIG}

.endif
.endif
.endif
