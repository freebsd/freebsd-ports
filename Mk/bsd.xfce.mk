#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Xfce_Pre_Include)

Xfce_Pre_Include=		bsd.xfce.mk
Xfce_Include_MAINTAINER=	oliver@FreeBSD.org

# This file contains some variable definitions that are supposed to
# make your life easier when dealing with ports related to the Xfce
# desktop environment. It's automatically included when USE_XFCE
# is defined in the ports' makefile.

_USE_XFCE_ALL=			configenv libexo libgui libutil libmcs mcsmanager panel \
				thunar wm xfdev

MASTER_SITE_SUBDIR?=		xfce-4.4.1

configenv_CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

libexo_BUILD_DEPENDS=		libexo>=0.3.2:${PORTSDIR}/x11/libexo
libexo_RUN_DEPENDS=		libexo>=0.3.2:${PORTSDIR}/x11/libexo

libgui_BUILD_DEPENDS=		libxfce4gui>=4.4.1:${PORTSDIR}/x11-toolkits/libxfce4gui
libgui_RUN_DEPENDS=		libxfce4gui>=4.4.1:${PORTSDIR}/x11-toolkits/libxfce4gui

libutil_BUILD_DEPENDS=		libxfce4util>=4.4.1:${PORTSDIR}/x11/libxfce4util
libutil_RUN_DEPENDS=		libxfce4util>=4.4.1:${PORTSDIR}/x11/libxfce4util

libmcs_BUILD_DEPENDS=		libxfce4mcs>=4.4.1:${PORTSDIR}/x11/libxfce4mcs
libmcs_RUN_DEPENDS=		libxfce4mcs>=4.4.1:${PORTSDIR}/x11/libxfce4mcs

mcsmanager_BUILD_DEPENDS=	xfce4-mcs-manager>=4.4.1:${PORTSDIR}/sysutils/xfce4-mcs-manager
mcsmanager_RUN_DEPENDS=		xfce4-mcs-manager>=4.4.1:${PORTSDIR}/sysutils/xfce4-mcs-manager

panel_BUILD_DEPENDS=		xfce4-panel>=4.4.1:${PORTSDIR}/x11-wm/xfce4-panel
panel_RUN_DEPENDS=		xfce4-panel>=4.4.1:${PORTSDIR}/x11-wm/xfce4-panel

thunar_BUILD_DEPENDS=		Thunar>=0.8.0:${PORTSDIR}/x11-fm/thunar
thunar_RUN_DEPENDS=		Thunar>=0.8.0:${PORTSDIR}/x11-fm/thunar

wm_BUILD_DEPENDS=		xfce4-wm>=4.4.1:${PORTSDIR}/x11-wm/xfce4-wm
wm_RUN_DEPENDS=			xfce4-wm>=4.4.1:${PORTSDIR}/x11-wm/xfce4-wm

xfdev_RUN_DEPENDS=		xfce4-dev-tools:${PORTSDIR}/devel/xfce4-dev-tools

.endif

.if defined(_POSTMKINCLUDED) && !defined(Xfce_Post_Include)

Xfce_Post_Include=		bsd.xfce.mk

.for component in ${USE_XFCE}
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
CONFIGURE_ENV+=	${${component}_CONFIGURE_ENV}
.endfor

.for component in ${USE_XFCE}
. if ${_USE_XFCE_ALL:M${component}}==""
IGNORE=	cannot install: Unknown component ${component}
. endif
.endfor

.endif
