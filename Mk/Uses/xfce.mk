# Provide support for Xfce related ports.
#
# Feature:	xfce
# Usage:	USES=xfce or USES=xfce
#
# Variables, which can be set by the port:
#
# USE_XFCE		List of components
#
# MAINTAINER: xfce@FreeBSD.org

.if !defined(_INCLUDE_USES_XFCE_Mk)
_INCLUDE_USES_XFCE_Mk=	yes
_USES_POST+=	xfce

_USE_XFCE_ALL=	garcon libexo libmenu libutil panel thunar xdt xfconf windowing

xfce_ARGS?=	# empty

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=	-L${LOCALBASE}/lib

libmenu_LIB_DEPENDS=	libxfce4ui-2.so:x11/libxfce4menu
libmenu_USE_XFCE_REQ=	libutil

garcon_LIB_DEPENDS=	libgarcon-1.so:sysutils/garcon
garcon_USE_XFCE_REQ=	libmenu

libexo_LIB_DEPENDS=	libexo-2.so:x11/libexo
libexo_USE_XFCE_REQ=	libmenu

panel_LIB_DEPENDS=	libxfce4panel-2.0.so:x11-wm/xfce4-panel
panel_RUN_DEPENDS=	xfce4-panel:x11-wm/xfce4-panel

libutil_LIB_DEPENDS=	libxfce4util.so:x11/libxfce4util

thunar_LIB_DEPENDS=	libthunarx-3.so:x11-fm/thunar
thunar_RUN_DEPENDS=	Thunar:x11-fm/thunar

xdt_BUILD_DEPENDS=	xfce4-dev-tools>=4.19.4:devel/xfce4-dev-tools

xfconf_LIB_DEPENDS=	libxfconf-0.so:x11/xfce4-conf

windowing_LIB_DEPENDS=	libxfce4windowing-0.so:x11/libxfce4windowing

.  if defined(USE_XFCE)
# First, expand all USE_XFCE_REQ recursively.
.    for comp in ${_USE_XFCE_ALL}
.      for subcomp in ${${comp}_USE_XFCE_REQ}
${comp}_USE_XFCE_REQ+=${${subcomp}_USE_XFCE_REQ}
.      endfor
.    endfor

# Then, use already expanded USE_XFCE_REQ to expand USE_XFCE.
.    for comp in ${USE_XFCE}
.      if ${_USE_XFCE_ALL:M${comp}} == ""
IGNORE=	cannot install: Unknown component ${comp}
.      endif
_USE_XFCE+=	${${comp}_USE_XFCE_REQ} ${comp}
.    endfor

# Remove duplicate components
USE_XFCE=	${_USE_XFCE:O:u}

.    for comp in ${USE_XFCE}
.      if defined(${comp}_BUILD_DEPENDS)
BUILD_DEPENDS+=	${${comp}_BUILD_DEPENDS}
.      endif

.      if defined(${comp}_LIB_DEPENDS)
LIB_DEPENDS+=	${${comp}_LIB_DEPENDS}
.      endif

.      if defined(${comp}_RUN_DEPENDS)
RUN_DEPENDS+=	${${comp}_RUN_DEPENDS}
.      endif
.    endfor

.  endif # end of defined(USE_XFCE)

.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_XFCE_POST_MK)
_INCLUDE_USES_XFCE_POST_MK=	yes

.endif
