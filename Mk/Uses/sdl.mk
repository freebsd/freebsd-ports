# $FreeBSD$
#
# Support for SDL-based ports
#
# Feature:	sdl
# Usage:	USES=sdl
#		USE_SDL=sdl console gfx image mixer mm net pango sound ttf
#		        sdl2 gfx2 image2 mixer2 net2 ttf2
#
#		USE_SDL specifies which SDL components to add as dependencies.
#		Not specifying USE_SDL with USES=sdl is an error.
#		USE_SDL=yes implies USE_SDL=sdl.  This is deprecated
#
# MAINTAINER:	amdmi3@FreeBSD.org

.if !defined(_INCLUDE_USES_SDL_MK)
_INCLUDE_USES_SDL_MK=		yes

# These are the current supported SDL1.2 modules
_SDL_USE_ALL=	sdl console gfx image mixer mm net pango sound ttf

_SDL_sdl_LIB_DEPENDS=		libSDL.so:devel/sdl12

_SDL_console_LIB_DEPENDS=	libSDL_console.so:devel/sdl_console
_SDL_console_REQUIRES=		sdl

_SDL_gfx_LIB_DEPENDS=		libSDL_gfx.so:graphics/sdl_gfx
_SDL_gfx_REQUIRES=		sdl

_SDL_image_LIB_DEPENDS=		libSDL_image.so:graphics/sdl_image
_SDL_image_REQUIRES=		sdl

_SDL_mixer_LIB_DEPENDS=		libSDL_mixer.so:audio/sdl_mixer
_SDL_mixer_REQUIRES=		sdl

_SDL_mm_LIB_DEPENDS=		libSDLmm.so:devel/sdlmm
_SDL_mm_REQUIRES=		sdl

_SDL_net_LIB_DEPENDS=		libSDL_net.so:net/sdl_net
_SDL_net_REQUIRES=		sdl

_SDL_pango_LIB_DEPENDS=		libSDL_Pango.so:x11-toolkits/sdl_pango
_SDL_pango_REQUIRES=		sdl

_SDL_sound_LIB_DEPENDS=		libSDL_sound.so:audio/sdl_sound
_SDL_sound_REQUIRES=		sdl

_SDL_ttf_LIB_DEPENDS=		libSDL_ttf.so:graphics/sdl_ttf
_SDL_ttf_REQUIRES=		sdl

# These are the current supported SDL2 modules
_SDL_USE_ALL+=	sdl2 gfx2 image2 mixer2 net2 ttf2

_SDL_sdl2_LIB_DEPENDS=		libSDL2.so:devel/sdl20

_SDL_gfx2_LIB_DEPENDS=		libSDL2_gfx.so:graphics/sdl2_gfx
_SDL_gfx2_REQUIRES=		sdl2

_SDL_image2_LIB_DEPENDS=	libSDL2_image.so:graphics/sdl2_image
_SDL_image2_REQUIRES=		sdl2

_SDL_mixer2_LIB_DEPENDS=	libSDL2_mixer.so:audio/sdl2_mixer
_SDL_mixer2_REQUIRES=		sdl2

_SDL_net2_LIB_DEPENDS=		libSDL2_net.so:net/sdl2_net
_SDL_net2_REQUIRES=		sdl2

_SDL_ttf2_LIB_DEPENDS=		libSDL2_ttf.so:graphics/sdl2_ttf
_SDL_ttf2_REQUIRES=		sdl2

# Basic checks
.if !empty(sdl_ARGS)
IGNORE=		USES=sdl takes no arguments
.endif

.if !defined(USE_SDL)
IGNORE=		need to specify sdl component(s) with USE_SDL
.endif

# Expand implied dependencies on main SDL/SDL2 ports
_USE_SDL=
.for _component in ${USE_SDL}
. if !${_SDL_USE_ALL:M${_component}}
IGNORE=		uses unknown SDL component ${_component}
. else
_USE_SDL+=	${_component} ${_SDL_${_component}_REQUIRES}
. endif
.endfor

# Provide LIB_DEPENDS
.for _component in ${_USE_SDL:O:u}
LIB_DEPENDS+=	${_SDL_${_component}_LIB_DEPENDS}
.endfor

# Provide dependency on main SDL ports
.if ${_USE_SDL:Msdl}
SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config
BUILD_DEPENDS+=	${SDL_CONFIG}:devel/sdl12
CONFIGURE_ENV+=	SDL_CONFIG=${SDL_CONFIG}
MAKE_ENV+=	SDL_CONFIG=${SDL_CONFIG}
.endif

.if ${_USE_SDL:Msdl2}
SDL2_CONFIG?=	${LOCALBASE}/bin/sdl2-config
BUILD_DEPENDS+=	${SDL2_CONFIG}:devel/sdl20
CONFIGURE_ENV+=	SDL2_CONFIG=${SDL2_CONFIG}
MAKE_ENV+=	SDL2_CONFIG=${SDL2_CONFIG}
.endif

# _INCLUDE_USES_SDL_MK
.endif

