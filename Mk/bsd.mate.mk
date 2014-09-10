#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#	$NetBSD$
#     $MCom: ports-experimental/Mk/bsd.mate.mk,v 1.13 2012/09/03 17:02:31 mezz Exp $
#
# Please view me with 4 column tabs!

#######################################################
#
# *** WARNING: Disable MARCUSCOM before merge in FreeBSD!
#     Please also remove this section before merging into FreeBSD.
#
#MARCUSCOM_CVS=yes

# ======================= USERS =================================
#
# There are no significant user-definable settings in here.
# This file is a framework to make it easier to create MATE ports.
#
# ======================= /USERS ================================

.if !defined(_POSTMKINCLUDED) && !defined(Mate_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Mate_Include_MAINTAINER=	gnome@FreeBSD.org
Mate_Pre_Include=			bsd.mate.mk

# This section defines possible names of MATE components and all information
# necessary for ports to use those components.

# Ports can use this as follows:
#
# USE_MATE=	caja common desktop
#
# .include <bsd.port.mk>
#
# As a result proper LIB_DEPENDS/RUN_DEPENDS will be added and CONFIGURE_ENV
# and MAKE_ENV defined.
#

# non-version specific components. Do not use :build/:run on those.
_USE_MATE_ALL=	autogen intlhack intltool

# MATE components, you can use the :build or :run if need. Without the :build
# and :run, it will be added in both build and run dependency. It will check
# for the library dependency first. If not exists then do the build/run on
# the *.pc file instead.
_USE_MATE_ALL+=	caja common controlcenter desktop dialogs docutils icontheme \
		libmatekbd libmateweather \
		marco menus mucharmap notificationdaemon panel polkit pluma \
		settingsdaemon

SCROLLKEEPER_DIR=	/var/db/rarian

caja_DETECT=		${LOCALBASE}/libdata/pkgconfig/libcaja-extension.pc
caja_BUILD_DEPENDS=	${caja_DETECT}:${PORTSDIR}/x11-fm/caja
caja_LIB_DEPENDS=	libcaja-extension.so:${PORTSDIR}/x11-fm/caja
caja_RUN_DEPENDS=	${caja_DETECT}:${PORTSDIR}/x11-fm/caja

mucharmap_DETECT=		${LOCALBASE}/libdata/pkgconfig/mucharmap-2.pc
mucharmap_BUILD_DEPENDS=${mucharmap_DETECT}:${PORTSDIR}/deskutils/mate-character-map
mucharmap_LIB_DEPENDS=	libmucharmap.so:${PORTSDIR}/deskutils/mate-character-map
mucharmap_RUN_DEPENDS=	${mucharmap_DETECT}:${PORTSDIR}/deskutils/mate-character-map

common_DETECT=		${LOCALBASE}/bin/mate-autogen
common_BUILD_DEPENDS=	${common_DETECT}:${PORTSDIR}/devel/mate-common
common_RUN_DEPENDS=	${common_DETECT}:${PORTSDIR}/devel/mate-common

controlcenter_DETECT=		${LOCALBASE}/libdata/pkgconfig/mate-window-settings-2.0.pc
controlcenter_BUILD_DEPENDS=	${controlcenter_DETECT}:${PORTSDIR}/sysutils/mate-control-center
controlcenter_LIB_DEPENDS=	libmate-window-settings.so:${PORTSDIR}/sysutils/mate-control-center
controlcenter_RUN_DEPENDS=	${controlcenter_DETECT}:${PORTSDIR}/sysutils/mate-control-center

desktop_DETECT=		${LOCALBASE}/libdata/pkgconfig/mate-desktop-2.0.pc
desktop_BUILD_DEPENDS=	${desktop_DETECT}:${PORTSDIR}/x11/mate-desktop
desktop_LIB_DEPENDS=	libmate-desktop-2.so:${PORTSDIR}/x11/mate-desktop
desktop_RUN_DEPENDS=	${desktop_DETECT}:${PORTSDIR}/x11/mate-desktop

dialogs_DETECT=		${LOCALBASE}/bin/matedialog
dialogs_BUILD_DEPENDS=	${dialogs_DETECT}:${PORTSDIR}/x11/mate-dialogs
dialogs_RUN_DEPENDS=	${dialogs_DETECT}:${PORTSDIR}/x11/mate-dialogs

docutils_DETECT=	${LOCALBASE}/libdata/pkgconfig/mate-doc-utils.pc
docutils_BUILD_DEPENDS=	${docutils_DETECT}:${PORTSDIR}/textproc/mate-doc-utils
docutils_RUN_DEPENDS=	${docutils_DETECT}:${PORTSDIR}/textproc/mate-doc-utils

icontheme_DETECT=	${LOCALBASE}/libdata/pkgconfig/mate-icon-theme.pc
icontheme_BUILD_DEPENDS=${icontheme_DETECT}:${PORTSDIR}/x11-themes/mate-icon-theme
icontheme_RUN_DEPENDS=	${icontheme_DETECT}:${PORTSDIR}/x11-themes/mate-icon-theme

intltool_DETECT=	${LOCALBASE}/bin/intltool-extract
intltool_BUILD_DEPENDS=	${intltool_DETECT}:${PORTSDIR}/textproc/intltool

intlhack_PRE_PATCH=		${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${REINPLACE_CMD} -e \
				's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
				 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";| ; \
				 s|/usr/bin/iconv|${LOCALBASE}/bin/iconv|g ; \
				 s|unpack *[(]'"'"'U\*'"'"'|unpack ('"'"'C*'"'"'|'
.if ${USE_MATE:Mintlhack}!=""
USE_MATE+=				intltool
.endif

libmatekbd_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmatekbd.pc
libmatekbd_BUILD_DEPENDS=	${libmatekbd_DETECT}:${PORTSDIR}/x11/libmatekbd
libmatekbd_LIB_DEPENDS=		libmatekbd.so:${PORTSDIR}/x11/libmatekbd
libmatekbd_RUN_DEPENDS=		${libmatekbd_DETECT}:${PORTSDIR}/x11/libmatekbd

libmateweather_DETECT=		${LOCALBASE}/libdata/pkgconfig/mateweather.pc
libmateweather_BUILD_DEPENDS=	${libmateweather_DETECT}:${PORTSDIR}/net/libmateweather
libmateweather_LIB_DEPENDS=	libmateweather.so:${PORTSDIR}/net/libmateweather
libmateweather_RUN_DEPENDS=	${libmateweather_DETECT}:${PORTSDIR}/net/libmateweather

marco_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmarco-private.pc
marco_BUILD_DEPENDS=	${marco_DETECT}:${PORTSDIR}/x11-wm/marco
marco_LIB_DEPENDS=	libmarco-private.so:${PORTSDIR}/x11-wm/marco
marco_RUN_DEPENDS=	${marco_DETECT}:${PORTSDIR}/x11-wm/marco

menus_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmate-menu.pc
menus_BUILD_DEPENDS=	${menus_DETECT}:${PORTSDIR}/x11/mate-menus
menus_LIB_DEPENDS=	libmate-menu.so:${PORTSDIR}/x11/mate-menus
menus_RUN_DEPENDS=	${menus_DETECT}:${PORTSDIR}/x11/mate-menus

notificationdaemon_DETECT=		${LOCALBASE}/libexec/mate-notification-daemon
notificationdaemon_BUILD_DEPENDS=	${notificationdaemon_DETECT}:${PORTSDIR}/deskutils/mate-notification-daemon
notificationdaemon_RUN_DEPENDS=		${notificationdaemon_DETECT}:${PORTSDIR}/deskutils/mate-notification-daemon

panel_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmatepanelapplet-4.0.pc
panel_BUILD_DEPENDS=	${panel_DETECT}:${PORTSDIR}/x11/mate-panel
panel_LIB_DEPENDS=	libmate-panel-applet-4.so:${PORTSDIR}/x11/mate-panel
panel_RUN_DEPENDS=	${panel_DETECT}:${PORTSDIR}/x11/mate-panel

polkit_DETECT=		${LOCALBASE}/libdata/pkgconfig/polkit-gtk-mate-1.pc
polkit_BUILD_DEPENDS=	${polkit_DETECT}:${PORTSDIR}/sysutils/mate-polkit
polkit_LIB_DEPENDS=	libpolkit-gtk-mate-1.so:${PORTSDIR}/sysutils/mate-polkit
polkit_RUN_DEPENDS=	${polkit_DETECT}:${PORTSDIR}/sysutils/mate-polkit

pluma_DETECT=		${LOCALBASE}/libdata/pkgconfig/pluma.pc
pluma_BUILD_DEPENDS=	${pluma_DETECT}:${PORTSDIR}/editors/pluma
pluma_RUN_DEPENDS=	${pluma_DETECT}:${PORTSDIR}/editors/pluma

settingsdaemon_DETECT=		${LOCALBASE}/libdata/pkgconfig/mate-settings-daemon.pc
settingsdaemon_BUILD_DEPENDS=	${settingsdaemon_DETECT}:${PORTSDIR}/sysutils/mate-settings-daemon
settingsdaemon_RUN_DEPENDS=	${settingsdaemon_DETECT}:${PORTSDIR}/sysutils/mate-settings-daemon

# End component definition section

.endif
# End of optional part.

.if defined(_POSTMKINCLUDED) && !defined(Mate_Post_Include)

Mate_Post_Include=		bsd.mate.mk

.if defined(USE_MATE)
# Comparing between USE_MATE and _USE_MATE_ALL to make sure the component
# exists in _USE_MATE_ALL. If it does not exist then give an error about it.
#. for component in ${USE_MATE:O:u:C/^([^:]+).*/\1/}
. for component in ${USE_MATE:C/^([^:]+).*/\1/}
#. for component in ${USE_GNOME:C/^([^:]+).*/\1/}
.  if ${_USE_MATE_ALL:M${component}}==""
.error cannot install: Unknown component USE_MATE=${component}
.  endif
. endfor

. for component in ${USE_MATE:O:u:C/^([^:]+).*/\1/}
.  if defined(${component}_PATCH_DEPENDS)
PATCH_DEPENDS+=	${${component}_PATCH_DEPENDS}
.  endif

.  if defined(${component}_DETECT)
.   if ${USE_MATE:M${component}\:build}!=""
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
.   elif ${USE_MATE:M${component}\:run}!=""
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.   else
.    if defined(${component}_LIB_DEPENDS)
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
.    else
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.    endif
.   endif
.  endif

.  if defined(${component}_CONFIGURE_TARGET)
CONFIGURE_ARGS+=${${component}_CONFIGURE_ARGS}
.  endif

.  if defined(${component}_CONFIGURE_ENV)
CONFIGURE_ENV+=	${${component}_CONFIGURE_ENV}
.  endif

.  if defined(${component}_MAKE_ENV)
MAKE_ENV+=	${${component}_MAKE_ENV}
.  endif

.  if !defined(CONFIGURE_TARGET) && defined(${component}_CONFIGURE_TARGET)
CONFIGURE_TARGET=	${${component}_CONFIGURE_TARGET}
.  endif

.  if defined(${component}_PRE_PATCH)
MATE_PRE_PATCH+=	; ${${component}_PRE_PATCH}
.  endif
. endfor
.endif # USE_MATE check

.if ${USE_MATE:Mautogen}!=""

CONFIGURE_ENV+=	NOCONFIGURE=yes

pre-configure: mate-pre-configure

mate-pre-configure:
	@(cd ${CONFIGURE_WRKSRC} ; ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)
.endif

.if defined(MATE_PRE_PATCH)

pre-configure-script: mate-pre-configure-script

mate-pre-configure-script:
	@${MATE_PRE_PATCH:C/^;//1}
.endif

.if ${MAINTAINER}=="gnome@FreeBSD.org"
CONFIGURE_FAIL_MESSAGE= "Please run the gnomelogalyzer, available from \"http://www.freebsd.org/gnome/gnomelogalyzer.sh\", which will diagnose the problem and suggest a solution. If - and only if - the gnomelogalyzer cannot solve the problem, report the build failure to the FreeBSD MATE team at ${MAINTAINER}, and attach (a) \"${CONFIGURE_WRKSRC}/${CONFIGURE_LOG}\", (b) the output of the failed make command, and (c) the gnomelogalyzer output. Also, it might be a good idea to provide an overview of all packages installed on your system (i.e. an \`ls ${PKG_DBDIR}\`). Put your attachment up on any website, copy-and-paste into http://freebsd-gnome.pastebin.com, or use send-pr(1) with the attachment. Try to avoid sending any attachments to the mailing list (${MAINTAINER}), because attachments sent to FreeBSD mailing lists are usually discarded by the mailing list software."
.endif

.endif
# End of use part.
