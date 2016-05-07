# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-pulseaudio-plugin
PORTVERSION=	0.2.4
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Panel plugin for controlling PulseAudio mixer

LICENSE=	GPLv2

LIB_DEPENDS=	libpulse-mainloop-glib.so:audio/pulseaudio
RUN_DEPENDS=	pavucontrol>=2.0:audio/pavucontrol

USES=	gettext gmake libtool pkgconfig tar:bzip2 xfce:gtk3
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 intltool intlhack
USE_XFCE=	panel
USE_XORG=	x11
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--with-mixer-command=${LOCALBASE}/bin/pavucontrol
CFLAGS+=	-Wno-return-type

OPTIONS_DEFINE=	KEYBINDER
OPTIONS_DEFAULT=	KEYBINDER
KEYBINDER_DESC=	Keyboard shortcuts
KEYBINDER_LIB_DEPENDS=	libkeybinder-3.0.so:x11/keybinder-gtk3
KEYBINDER_CONFIGURE_ENABLE=	keybinder

.include <bsd.port.mk>
