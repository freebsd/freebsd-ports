#-*- tab-width: 4; -*-
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

SDL_Include_MAINTAINER=		mva@FreeBSD.org

#
# These are the current supported SDL1.2 modules
#
_USE_SDL_ALL=	console gfx image mixer mm net pango sdl sound ttf
#
# These are the current supported SDL2 modules
#
_USE_SDL_ALL+=	gfx2 image2 mixer2 net2 sdl2 ttf2

#
# Variables used to determine what is needed:
# _SUBDIR_xxx	subdirectory below ${PORTSDIR} (required)
# _PORTDIR_xxx	subdirectory below ${PORTSDIR}/${_SUBDIR_xxx}
# _LIB_xxx		name of the shared lib
# _REQUIRES_xxx	also needs these SDL libraries
#

_SUBDIR_console=	devel
_PORTDIR_console=	sdl_console
_LIB_console=		libSDL_console.so
_REQUIRES_console=	sdl

_SUBDIR_gfx=	graphics
_PORTDIR_gfx=	sdl_gfx
_LIB_gfx=	libSDL_gfx.so
_REQUIRES_gfx=	sdl

_SUBDIR_image=	graphics
_PORTDIR_image=	sdl_image
_LIB_image=	libSDL_image.so
_REQUIRES_image=sdl

_SUBDIR_mixer=	audio
_PORTDIR_mixer=	sdl_mixer
_LIB_mixer=	libSDL_mixer.so
_REQUIRES_mixer=sdl

_SUBDIR_mm=	devel
_PORTDIR_mm=	sdlmm
_LIB_mm=	libSDLmm.so
_REQUIRES_mm=	sdl

_SUBDIR_net=	net
_PORTDIR_net=	sdl_net
_LIB_net=	libSDL_net.so
_REQUIRES_net=	sdl

_SUBDIR_pango=	x11-toolkits
_PORTDIR_pango=	sdl_pango
_LIB_pango=	libSDL_Pango.so
_REQUIRES_pango=sdl

_SUBDIR_sdl=	devel
_PORTDIR_sdl=	sdl12
_LIB_sdl=	libSDL.so
_REQUIRES_sdl=

_SUBDIR_sound=	audio
_PORTDIR_sound=	sdl_sound
_LIB_sound=	libSDL_sound.so
_REQUIRES_sound=sdl

_SUBDIR_ttf=	graphics
_PORTDIR_ttf=	sdl_ttf
_LIB_ttf=	libSDL_ttf.so
_REQUIRES_ttf=	sdl

_SUBDIR_gfx2=	graphics
_PORTDIR_gfx2=	sdl2_gfx
_LIB_gfx2=	libSDL2_gfx.so
_REQUIRES_gfx2=	sdl2

_SUBDIR_image2=		graphics
_PORTDIR_image2=	sdl2_image
_LIB_image2=		libSDL2_image.so
_REQUIRES_image2=	sdl2

_SUBDIR_mixer2=		audio
_PORTDIR_mixer2=	sdl2_mixer
_LIB_mixer2=		libSDL2_mixer.so
_REQUIRES_mixer2=	sdl2

_SUBDIR_net2=	net
_PORTDIR_net2=	sdl2_net
_LIB_net2=	libSDL2_net.so
_REQUIRES_net2=	sdl2

_SUBDIR_sdl2=	devel
_PORTDIR_sdl2=	sdl20
_LIB_sdl2=	libSDL2.so
_REQUIRES_sdl2=

_SUBDIR_ttf2=	graphics
_PORTDIR_ttf2=	sdl2_ttf
_LIB_ttf2=	libSDL2_ttf.so
_REQUIRES_ttf2=	sdl2

#
# If WANT_SDL is defined, check for the available libraries
#
.if !defined(AFTERPORTMK)
.if !defined(SDL_Include_pre)

SDL_Include_pre=	bsd.sdl.mk

HAVE_SDL?=
.if defined(WANT_SDL)
.for component in ${_USE_SDL_ALL}
.if exists(${LOCALBASE}/lib/lib${_LIB_${component}}.so)
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
IGNORE=	cannot install: unknown SDL component ${component}
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
LIB_DEPENDS+=	${_LIB_${component}}:${PORTSDIR}/${_SUBDIR_${component}}/${_PORTDIR_${component}}
.endfor

#
# "Normal" dependencies and variables
#
.if ${__USE_SDL:Msdl} != ""
BUILD_DEPENDS+=	${SDL_CONFIG}:${PORTSDIR}/${_SUBDIR_sdl}/${_PORTDIR_sdl}
SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config
CONFIGURE_ENV+=	SDL_CONFIG=${SDL_CONFIG}
MAKE_ENV+=		SDL_CONFIG=${SDL_CONFIG}
.endif
.if ${__USE_SDL:Msdl2} != ""
BUILD_DEPENDS+=	${SDL2_CONFIG}:${PORTSDIR}/${_SUBDIR_sdl2}/${_PORTDIR_sdl2}
SDL2_CONFIG?=	${LOCALBASE}/bin/sdl2-config
CONFIGURE_ENV+=	SDL2_CONFIG=${SDL2_CONFIG}
MAKE_ENV+=		SDL2_CONFIG=${SDL2_CONFIG}
.endif

.endif
.endif
.endif
