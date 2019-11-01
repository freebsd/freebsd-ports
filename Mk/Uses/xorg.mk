# $FreeBSD$
#
# Originally from bsd.xorg.mk
# Created by: Florent Thoumie <flz@FreeBSD.org>
#
# Feature:		xorg
# Usage:		USES=xorg
# 			USE_XORG=<component>
#
# 			Not specifying USE_XORG with USES=xorg is an error.
#			
#			Components can be found in the XORG_MODULES list below.
#
#
# If you feel something is missing from the list, please let us know.
#
# MAINTAINER:	x11@FreeBSD.org

.if !defined(_INCLUDE_USES_XORG_MK)
_INCLUDE_USES_XORG_MK=		yes
_USES_POST+=	xorg
.endif

# Set up things after bsd.port.post.mk.
# This way ports can add things to USE_XORG even after bsd.port.pre.mk is
# included.
.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_XORG_POST_MK)
_INCLUDE_USES_XORG_POST_MK=	yes

.  if !empty(xorg_ARGS)
IGNORE=		USES=xorg takes no arguments
.  endif

.  if !defined(USE_XORG)
IGNORE=		need to specify xorg modules with USE_XORG
.  endif

# List of xorg modules
XORG_MODULES=	dmx \
		fontenc \
		fontutil \
		ice \
		libfs \
		pciaccess \
		pixman \
		sm \
		x11 \
		xau \
		xaw \
		xaw6 \
		xaw7 \
		xbitmaps \
		xcb \
		xcomposite \
		xcursor \
		xdamage \
		xdmcp \
		xext \
		xfixes \
		xfont \
		xfont2 \
		xft \
		xi \
		xinerama \
		xkbfile \
		xmu \
		xmuu \
		xorg-macros \
		xorg-server \
		xorgproto \
		xpm \
		xpresent \
		xrandr \
		xrender \
		xres \
		xscrnsaver \
		xshmfence \
		xt \
		xtrans \
		xtst \
		xv \
		xvmc \
		xxf86dga \
		xxf86vm

# Register all xorg .pc files here.
# foo_LIB_PC_DEPENDS means it should go to BUILD_DEPENDS *and* RUN_DEPENDS.
dmx_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/dmx.pc:x11/libdmx
fontenc_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/fontenc.pc:x11-fonts/libfontenc
fontutil_BUILD_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/fontutil.pc:x11-fonts/font-util
ice_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/ice.pc:x11/libICE
libfs_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/libfs.pc:x11-fonts/libFS
pciaccess_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pciaccess.pc:devel/libpciaccess
pixman_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/pixman-1.pc:x11/pixman
sm_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/sm.pc:x11/libSM
x11_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/x11.pc:x11/libX11
xau_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xau.pc:x11/libXau
xaw_LIB_PC_DEPENDS=		${xaw7_LIB_PC_DEPENDS}
xaw6_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xaw6.pc:x11-toolkits/libXaw
xaw7_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xaw7.pc:x11-toolkits/libXaw
xbitmaps_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xbitmaps.pc:x11/xbitmaps
xcb_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xcb.pc:x11/libxcb
xcomposite_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcomposite.pc:x11/libXcomposite
xcursor_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xcursor.pc:x11/libXcursor
xdamage_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xdamage.pc:x11/libXdamage
xdmcp_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xdmcp.pc:x11/libXdmcp
xext_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xext.pc:x11/libXext
xfixes_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xfixes.pc:x11/libXfixes
xfont_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xfont.pc:x11-fonts/libXfont
xfont2_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xfont2.pc:x11-fonts/libXfont2
xft_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xft.pc:x11-fonts/libXft
xi_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xi.pc:x11/libXi
xinerama_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xinerama.pc:x11/libXinerama
xkbfile_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:x11/libxkbfile
xmu_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xmu.pc:x11-toolkits/libXmu
xmuu_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xmuu.pc:x11-toolkits/libXmu
xorg-macros_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xorg-macros.pc:devel/xorg-macros
xorg-server_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xorg-server.pc:x11-servers/xorg-server
xorgproto_BUILD_DEPENDS=	xorgproto>=0:x11/xorgproto
xp_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xp.pc:x11/libXp
xpm_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xpm.pc:x11/libXpm
xpresent_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xpresent.pc:x11/libXpresent
xrandr_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xrandr.pc:x11/libXrandr
xrender_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xrender.pc:x11/libXrender
xres_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xres.pc:x11/libXres
xscrnsaver_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xscrnsaver.pc:x11/libXScrnSaver
xt_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xt.pc:x11-toolkits/libXt
xshmfence_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xshmfence.pc:x11/libxshmfence
xtrans_BUILD_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xtrans.pc:x11/xtrans
xtst_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xtst.pc:x11/libXtst
xv_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xv.pc:x11/libXv
xvmc_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xvmc.pc:x11/libXvMC
xxf86dga_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xxf86dga.pc:x11/libXxf86dga
xxf86misc_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xxf86misc.pc:x11/libXxf86misc
xxf86vm_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xxf86vm.pc:x11/libXxf86vm

# Add explicit X options to avoid problems with false positives in configure
.  if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=--x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
.  endif

.  for _module in ${USE_XORG:M*\:both:C/\:.*//g}
.    if ${XORG_MODULES:M${_module}} == ""
IGNORE=		requires unknown xorg module (${_module})
.    endif
RUN_DEPENDS+=	${${_module}_BUILD_DEPENDS}
.  endfor

.  for _module in ${USE_XORG:C/\:both$//g}
.    if ${XORG_MODULES:M${_module}} == ""
IGNORE=		requires unknown xorg module (${_module})
.    endif
LIB_PC_DEPENDS+=${${_module}_LIB_PC_DEPENDS}
BUILD_DEPENDS+=	${${_module}_BUILD_DEPENDS}
.  endfor

RUN_DEPENDS+=	${LIB_PC_DEPENDS}
BUILD_DEPENDS+=	${LIB_PC_DEPENDS}

.endif
