# $FreeBSD$
# 
# xorg ports categories and other things needed to build xorg ports.
# This is intended only for ports of xorg and freedesktop.org applications.
#
# Use USES=xorg and USE_XORG to depend on various xorg components.
#
# Feature:	xorg-cat
# Usage:	USES=xorg-cat:category[,buildsystem]
#
# 		category is one of:
# 		* app      Installs applications, no shared libraries.
# 		* data     Installs only data.
# 		* doc      no particular notes
# 		* driver   depends on xorgproto at least
# 		* font     don't install .pc file
# 		* lib      various dependencies, install .pc file, needs
# 		           pathfix
# 		* proto    install .pc file, needs pathfix, most only needed at
# 		           build time.
# 		* util     no particular notes
# 		* xserver  xorg x servers
#
# 		These categories has to match upstream categories.  Don't invent
# 		your own.
#
# 		builsystem is one of:
# 		* autotools (default)
# 		* meson (experimental)
#
#
# By defining USE_GITLAB and GL_COMMIT, it is possible to pull code straight
# from the freedesktop.org gitlab, instead of official release tarballs.
#
#.MAINTAINER:	x11@FreeBSD.org

.if !defined(_INCLUDE_USES_XORG_CAT_MK)
_INCLUDE_USES_XORG_CAT_MK=yes

_XORG_CATEGORIES=	app data doc driver font lib proto util xserver
_XORG_BUILDSYSTEMS=	autotools meson

_XORG_CAT=		# empty
_XORG_BUILDSYS=		# empty

.  if empty(xorg-cat_ARGS)
IGNORE=		no arguments specified to xorg-cat
.  endif

.  for _arg in ${xorg-cat_ARGS}
.    if ${_XORG_CATEGORIES:M${_arg}}
.      if empty(_XORG_CAT)
_XORG_CAT=	${_arg}
.      else
IGNORE=		multipe xorg categories specified via xorg-cat:${xorg-cat_ARGS:ts,}
.      endif
.    elif ${_XORG_BUILDSYSTEMS:M${_arg}}
.      if empty(_XORG_BUILDSYS)
_XORG_BUILDSYS=	${_arg}
.      else
IGNORE=		multipe xorg build systems specified via xorg-cat:${xorg-cat_ARGS:ts,}
.      endif
.    else
IGNORE=		unknown argument specified via xorg-cat:${xorg-cat_ARGS:ts,}
.    endif
.  endfor

# Default to the autotools build system
.  if empty(_XORG_BUILDSYS)
_XORG_BUILDSYS=		autotools
.  endif

# Default variables, common to all new modular xorg ports.
.  if empty(USES:Mtar)
EXTRACT_SUFX?=		.tar.bz2
.  endif

DIST_SUBDIR=	xorg/${_XORG_CAT}

.  if ${_XORG_BUILDSYS} == meson
IGNORE=		meson build not supported yet
.include "${USESDIR}/meson.mk"
.  elif ${_XORG_BUILDSYS} == autotools
GNU_CONFIGURE=		yes
.  else
# This should not happen
IGNORE=		unknown build system specified via xorg-cat:${xorg-cat_ARGS:ts,}
.  endif

.  if defined(USE_GITLAB)
# Set up things for fetching from freedesktop.org gitlab.
# This can be overridden using normal GL_* macros in the ports Makefile.
# We make a best guess for GL_ACCOUNT and GL_PROJECT.
GL_SITE?=		https://gitlab.freedesktop.org/xorg
GL_ACCOUNT?=		${_XORG_CAT}
GL_PROJECT?=		${PORTNAME:tl}
.    if ${_XORG_BUILDSYS} == meson
# set up meson stuff here
.    else
# Things from GL doesn't come with pre-generated configure, add dependency on
# autoreconf and run it, if we're using autotools.
.include "${USESDIR}/autoreconf.mk"
.    endif
.  else
MASTER_SITES?=		XORG/individual/${_XORG_CAT}
.  endif

#
## All xorg ports needs pkgconfig to build, but some ports look for pkgconfig
## and then continues the build.
.include "${USESDIR}/pkgconfig.mk"

#
## All xorg ports needs xorg-macros.
.  if ${PORTNAME} != xorg-macros
USE_XORG+=      xorg-macros
.  endif

.  if ${_XORG_CAT} == app
# Nothing at the moment

.  elif ${_XORG_CAT} == data
# Nothing at the moment.

.  elif ${_XORG_CAT} == driver
USE_XORG+=	xi xorg-server xorgproto
CFLAGS+=	-Werror=uninitialized
.    if ${_XORG_BUILDSYS} == meson
# Put special stuff for meson here
.    else
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4x DRIVER_MAN_DIR='$$(mandir)/man4'
libtool_ARGS?=	# empty
.include "${USESDIR}/libtool.mk"
INSTALL_TARGET=	install-strip
.    endif

.  elif ${_XORG_CAT} == font
FONTNAME?=	${PORTNAME:C/.*-//g:S/type/Type/:S/ttf/TTF/:S/speedo/Speedo/}
.    if ${_XORG_BUILDSYS} == meson
# Put special stuff for meson here
.    else
CONFIGURE_ARGS+=	--with-fontrootdir=${PREFIX}/share/fonts
CONFIGURE_ENV+=	FONTROOTDIR=${PREFIX}/share/fonts
.    endif
.    if !defined(NOFONT)
.include "${USESDIR}/fonts.mk"
BUILD_DEPENDS+=	mkfontscale>=0:x11-fonts/mkfontscale \
		bdftopcf:x11-fonts/bdftopcf
PLIST_FILES+=	"@comment ${FONTSDIR}/fonts.dir" \
		"@comment ${FONTSDIR}/fonts.scale"
.    endif

.  elif ${_XORG_CAT} == lib
CFLAGS+=	-Werror=uninitialized
.include "${USESDIR}/pathfix.mk"
.    if ${_XORG_BUILDSYS} == meson
# put meson stuff here
.    else
libtool_ARGS?=	# empty
.include "${USESDIR}/libtool.mk"
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--enable-malloc0returnsnull
.    endif

.  elif ${_XORG_CAT} == proto
.include "${USESDIR}/pathfix.mk"

.  elif ${_XORG_CAT} == xserver
DISTNAME?=	xorg-server-${PORTVERSION}
CFLAGS+=	-Werror=uninitialized
.include "${USESDIR}/pathfix.mk"
.    if ${_XORG_BUILDSYS} == meson
# put meson stuff here
.    else
CONFIGURE_ARGS+=	--with-xkb-path=${LOCALBASE}/share/X11/xkb \
			--with-fontrootdir=${LOCALBASE}/share/fonts
libtool_ARGS?=	# empty
.include "${USESDIR}/libtool.mk"
.    endif
LIB_PC_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-dri
USE_XORG+=	fontutil

.  endif # ${_XORG_CAT} == <category>

# We only need to include xorg.mk if we want USE_XORG modules
# USES+=xorg does not provide any functionality, it just silences an error
# message about USES=xorg not being set
.  if defined(USE_XORG) && !empty(USE_XORG)
USES+=		xorg
.include "${USESDIR}/xorg.mk"
.  endif

.endif
