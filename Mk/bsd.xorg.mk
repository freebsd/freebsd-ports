#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.xorg.mk - Support for X.Org ports and dependencies
#
# Created by: Florent Thoumie <flz@FreeBSD.org>
#
# !!! Here be dragons !!! (yeah, here as well...)
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Xorg_Pre_Include)

Xorg_Include_MAINTAINER=	x11@FreeBSD.org
Xorg_Pre_Include=		bsd.xorg.mk

# Some notes:
#
# app - requires pkgconfig, don't install shared libraries (I guess)
# data - nothing I could factorize
# doc - no particular notes
# driver - input depends on inputproto/randrproto at least
#          video depends on randrproto/renderproto at least
# font - don't install .pc file
# lib - various dependencies, install .pc file
# proto - install .pc file, no dependencies, needed only at build time for most of them
# xserver - there's only one atm, I guess everything can fit into the port itself

.if defined(XORG_CAT)
# Default variables, common to all new modular xorg ports.
.if !defined(USE_TGZ)
USE_BZIP2=    	yes
.endif
GNU_CONFIGURE= 	yes
DIST_SUBDIR=	xorg/${XORG_CAT}

MASTER_SITES?=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR?=	individual/${XORG_CAT}

. if ${XORG_CAT} == "app"
USE_GNOME+=	pkgconfig
. endif

. if ${XORG_CAT} == "data"
# Nothing at the moment.
. endif

. if ${XORG_CAT} == "driver"
USE_GNOME+=	pkgconfig
USE_XORG+=	xorg-server xproto randrproto xi
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4x DRIVER_MAN_DIR='$$(mandir)/man4'
.  if ${PORTNAME:M*input*}x != x
USE_XORG+=	inputproto
.  elif ${PORTNAME:M*video*}x != x
USE_XORG+=	fontsproto renderproto
.  else
IGNORE=		doesn't contain either "driver" or "input"
.  endif
.  if ${PORTNAME:M*-sun*}x != x && ${ARCH} != sparc64
IGNORE=		is for sparc64 only
.  endif
. endif

. if ${XORG_CAT} == "font"
FONTDIR?=	${PORTNAME:C/.*-//g:S/type/Type/:S/ttf/TTF/:S/speedo/Speedo/}
CONFIGURE_ARGS+=	--with-fontrootdir=${PREFIX}/lib/X11/fonts
CONFIGURE_ENV+=	FONTROOTDIR=${PREFIX}/lib/X11/fonts
NEED_MKFONTFOO=	yes

.  if ${PORTNAME:M*type1*}x != x
INSTALLS_TTF?=	yes
.  elif ${PORTNAME:M*ttf*}x != x
INSTALLS_TTF?=	yes
.  elif ${PORTNAME:M*encodings*}x != x
# This is terrific, we want mkfontscale at build time, but don't use it like for the other ports.
NEED_MKFONTFOO=	no
BUILD_DEPENDS+=	${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
INSTALLS_TTF?=	no
.  else
INSTALLS_TTF?=	no
.  endif

.  if ${PORTNAME:M*font-util*}x != x
USE_GNOME+=	gnomehack
NEED_MKFONTFOO=	no
.  elif ${INSTALLS_TTF} == "yes"
USE_GNOME+=	pkgconfig
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig
.  else
BUILD_DEPENDS+=	${LOCALBASE}/bin/bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
.  endif

.  if ${NEED_MKFONTFOO} == "yes"
BUILD_DEPENDS+=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
				${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
RUN_DEPENDS+=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
				${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
.  endif

post-install:
.  if ${INSTALLS_TTF} == "yes"
.   for _fontdir in ${FONTDIR}
	@${ECHO_CMD} "@exec fc-cache -s %D/lib/X11/fonts/${_fontdir} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec fc-cache -s %D/lib/X11/fonts/${_fontdir} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/X11/fonts/${_fontdir} 2>/dev/null || true" >> ${TMPPLIST}
.   endfor
.  endif
.  for _fontdir in ${FONTDIR}
.   if ${NEED_MKFONTFOO} == "yes"
	@${ECHO_CMD} "@exec mkfontscale %D/lib/X11/fonts/${_fontdir} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec mkfontscale %D/lib/X11/fonts/${_fontdir} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec if [ -e %D/lib/X11/fonts/${_fontdir}/fonts.scale -a \"\`stat -f '%%z' %D/lib/X11/fonts/${_fontdir}/fonts.scale 2>/dev/null\`\" = '2' ]; then rm %D/lib/X11/fonts/${_fontdir}/fonts.scale; fi" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec mkfontdir %D/lib/X11/fonts/${_fontdir} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec mkfontdir %D/lib/X11/fonts/${_fontdir} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec if [ -e %D/lib/X11/fonts/${_fontdir}/fonts.dir -a \"\`stat -f '%%z' %D/lib/X11/fonts/${_fontdir}/fonts.dir 2>/dev/null\`\" = '2' ]; then rm %D/lib/X11/fonts/${_fontdir}/fonts.dir; fi" >> ${TMPPLIST}
.   endif
	@${ECHO_CMD} "@unexec rmdir %D/lib/X11/fonts/${_fontdir} 2>/dev/null || true" >> ${TMPPLIST}
.  endfor
. endif

. if ${XORG_CAT} == "lib"
USE_GNOME+=	gnomehack pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--enable-malloc0returnsnull
. endif

. if ${XORG_CAT} == "proto"
USE_GNOME+=	gnomehack
. endif

. if ${XORG_CAT} == "xserver"
DISTFILES?=	xorg-server-${PORTVERSION}.tar.bz2
WRKSRC=		${WRKDIR}/xorg-server-${PORTVERSION}
USE_GNOME+=	gnomehack
CONFIGURE_ARGS+=	--with-xkb-path=${LOCALBASE}/share/X11/xkb

LIB_PC_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dri.pc:${PORTSDIR}/graphics/dri
USE_XORG+=	pciaccess
. endif

.endif

.endif

.if defined(_POSTMKINCLUDED) && !defined(Xorg_Post_Include)

Xorg_Post_Include=		bsd.xorg.mk

# Register all xorg .pc files here.
# foo_LIB_PC_DEPENDS means it should go to BUILD_DEPENDS *and* RUN_DEPENDS.

XORG_MODULES=	bigreqsproto compositeproto damageproto dmx dmxproto dri2proto evieproto fixesproto fontcacheproto fontenc fontsproto fontutil glproto ice inputproto kbproto libfs oldx pciaccess pixman printproto randrproto recordproto renderproto resourceproto scrnsaverproto sm trapproto videoproto x11 xau xaw xaw6 xaw7 xbitmaps xcmiscproto xcomposite xcursor xdamage xdmcp xevie xext xextproto xf86bigfontproto xf86dgaproto xf86driproto xf86miscproto xf86rushproto xf86vidmodeproto xfixes xfont xfontcache xft xi xinerama xineramaproto xkbfile xkbui xmu xmuu xorg-server xp xpm xprintapputil xprintutil xproto xproxymngproto xrandr xrender xres xscrnsaver xt xtrans xtrap xtst xv xvmc xxf86dga xxf86misc xxf86vm

bigreqsproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bigreqsproto.pc:${PORTSDIR}/x11/bigreqsproto
compositeproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compositeproto.pc:${PORTSDIR}/x11/compositeproto
damageproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/damageproto.pc:${PORTSDIR}/x11/damageproto
dmx_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/dmx.pc:${PORTSDIR}/x11/libdmx
dmxproto_BUILD_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/dmxproto.pc:${PORTSDIR}/x11/dmxproto
dri2proto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dri2proto.pc:${PORTSDIR}/x11/dri2proto
evieproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/evieproto.pc:${PORTSDIR}/x11/evieext
fixesproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fixesproto.pc:${PORTSDIR}/x11/fixesproto
fontcacheproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontcacheproto.pc:${PORTSDIR}/x11-fonts/fontcacheproto
fontenc_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/fontenc.pc:${PORTSDIR}/x11-fonts/libfontenc
fontsproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontsproto.pc:${PORTSDIR}/x11-fonts/fontsproto
fontutil_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontutil.pc:${PORTSDIR}/x11-fonts/font-util
glproto_BUILD_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/glproto.pc:${PORTSDIR}/x11/glproto
ice_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/ice.pc:${PORTSDIR}/x11/libICE
inputproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/inputproto.pc:${PORTSDIR}/x11/inputproto
kbproto_BUILD_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/kbproto.pc:${PORTSDIR}/x11/kbproto
libfs_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/libfs.pc:${PORTSDIR}/x11-fonts/libFS
oldx_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/oldx.pc:${PORTSDIR}/x11/liboldX
pciaccess_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pciaccess.pc:${PORTSDIR}/devel/libpciaccess
pixman_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/pixman-1.pc:${PORTSDIR}/x11/pixman
printproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/printproto.pc:${PORTSDIR}/x11/printproto
randrproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/randrproto.pc:${PORTSDIR}/x11/randrproto
recordproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/recordproto.pc:${PORTSDIR}/x11/recordproto
renderproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/renderproto.pc:${PORTSDIR}/x11/renderproto
resourceproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/resourceproto.pc:${PORTSDIR}/x11/resourceproto
scrnsaverproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/scrnsaverproto.pc:${PORTSDIR}/x11/scrnsaverproto
sm_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/sm.pc:${PORTSDIR}/x11/libSM
trapproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/trapproto.pc:${PORTSDIR}/x11/trapproto
videoproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/videoproto.pc:${PORTSDIR}/x11/videoproto
x11_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11
xau_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xau.pc:${PORTSDIR}/x11/libXau
xaw_LIB_PC_DEPENDS=		${xaw7_LIB_PC_DEPENDS}
xaw6_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xaw6.pc:${PORTSDIR}/x11-toolkits/libXaw
xaw7_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xaw7.pc:${PORTSDIR}/x11-toolkits/libXaw
xbitmaps_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xbitmaps.pc:${PORTSDIR}/x11/xbitmaps
xcmiscproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcmiscproto.pc:${PORTSDIR}/x11/xcmiscproto
xcomposite_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcomposite.pc:${PORTSDIR}/x11/libXcomposite
xcursor_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xcursor.pc:${PORTSDIR}/x11/libXcursor
xdamage_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xdamage.pc:${PORTSDIR}/x11/libXdamage
xdmcp_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xdmcp.pc:${PORTSDIR}/x11/libXdmcp
xevie_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xevie.pc:${PORTSDIR}/x11/libXevie
xext_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xext.pc:${PORTSDIR}/x11/libXext
xextproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xextproto.pc:${PORTSDIR}/x11/xextproto
xf86bigfontproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xf86bigfontproto.pc:${PORTSDIR}/x11-fonts/xf86bigfontproto
xf86dgaproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xf86dgaproto.pc:${PORTSDIR}/x11/xf86dgaproto
xf86driproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xf86driproto.pc:${PORTSDIR}/x11/xf86driproto
xf86miscproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xf86miscproto.pc:${PORTSDIR}/x11/xf86miscproto
xf86rushproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xf86rushproto.pc:${PORTSDIR}/x11/xf86rushproto
xf86vidmodeproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xf86vidmodeproto.pc:${PORTSDIR}/x11/xf86vidmodeproto
xfixes_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xfixes.pc:${PORTSDIR}/x11/libXfixes
xfont_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xfont.pc:${PORTSDIR}/x11-fonts/libXfont
xfontcache_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xfontcache.pc:${PORTSDIR}/x11-fonts/libXfontcache
xft_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xft.pc:${PORTSDIR}/x11-fonts/libXft
xi_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xi.pc:${PORTSDIR}/x11/libXi
xinerama_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xinerama.pc:${PORTSDIR}/x11/libXinerama
xineramaproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xineramaproto.pc:${PORTSDIR}/x11/xineramaproto
xkbfile_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:${PORTSDIR}/x11/libxkbfile
xkbui_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xkbui.pc:${PORTSDIR}/x11/libxkbui
xmu_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xmu.pc:${PORTSDIR}/x11-toolkits/libXmu
xmuu_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xmuu.pc:${PORTSDIR}/x11-toolkits/libXmu
xorg-server_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xorg-server.pc:${PORTSDIR}/x11-servers/xorg-server
xp_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xp.pc:${PORTSDIR}/x11/libXp
xpm_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xpm.pc:${PORTSDIR}/x11/libXpm
xprintapputil_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xprintapputil.pc:${PORTSDIR}/x11/libXprintAppUtil
xprintutil_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xprintutil.pc:${PORTSDIR}/x11/libXprintUtil
xproto_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto
xproxymngproto_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xproxymngproto.pc:${PORTSDIR}/x11/xproxymanagementprotocol
xrandr_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xrandr.pc:${PORTSDIR}/x11/libXrandr
xrender_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xrender.pc:${PORTSDIR}/x11/libXrender
xres_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xres.pc:${PORTSDIR}/x11/libXres
xscrnsaver_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xscrnsaver.pc:${PORTSDIR}/x11/libXScrnSaver
xt_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xt.pc:${PORTSDIR}/x11-toolkits/libXt
xtrans_BUILD_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xtrans.pc:${PORTSDIR}/x11/xtrans
xtrap_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xtrap.pc:${PORTSDIR}/x11/libXTrap
xtst_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xtst.pc:${PORTSDIR}/x11/libXtst
xv_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xv.pc:${PORTSDIR}/x11/libXv
xvmc_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xvmc.pc:${PORTSDIR}/x11/libXvMC
xxf86dga_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xxf86dga.pc:${PORTSDIR}/x11/libXxf86dga
xxf86misc_LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xxf86misc.pc:${PORTSDIR}/x11/libXxf86misc
xxf86vm_LIB_PC_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/xxf86vm.pc:${PORTSDIR}/x11/libXxf86vm

.for _module in ${USE_XORG:M*\:both:C/\:.*//g}
. if ${XORG_MODULES:M${_module}} == ""
IGNORE=				requires unknown xorg module (${_module})
. endif
RUN_DEPENDS+=			${${_module}_BUILD_DEPENDS}
.endfor

.for _module in ${USE_XORG:C/\:.*//g}
. if ${XORG_MODULES:M${_module}} == ""
IGNORE=				requires unknown xorg module (${_module})
. endif
LIB_PC_DEPENDS+=		${${_module}_LIB_PC_DEPENDS}
BUILD_DEPENDS+=			${${_module}_BUILD_DEPENDS}
.endfor

RUN_DEPENDS+=			${LIB_PC_DEPENDS}
BUILD_DEPENDS+=			${LIB_PC_DEPENDS}

.if !target(check-latest)
check-latest:
	@AVAIL_VER=`fetch -qo - http://xorg.freedesktop.org/releases/individual/${XORG_CAT}/ | sed -ne 's/.*${PORTNAME}-\(.*\).tar.bz2\".*/\1/p'` && \
		${ECHO_CMD} "Available versions for ${PORTNAME} are: $${AVAIL_VER}." && \
		for ver in $${AVAIL_VER}; do \
			if [ `pkg_version -t $$ver ${PORTVERSION}` = ">" ]; then \
				${ECHO_CMD} "${PORTNAME} $$ver is newer than current version."; \
			fi; \
		done
.endif

.endif
