# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-pulseaudio-plugin
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Panel plugin for controlling PulseAudio mixer

LICENSE=	GPLv2

LIB_DEPENDS=	libpulse-mainloop-glib.so:audio/pulseaudio \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	pavucontrol>=2.0:audio/pavucontrol

USES=		gettext gmake gnome libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	glib20 gtk30 intltool cairo libwnck3
USE_XFCE=	panel
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--with-mixer-command=${LOCALBASE}/bin/pavucontrol \
		--enable-mpris2 \
		--enable-wnck
CFLAGS+=	-Wno-return-type

OPTIONS_DEFINE=			KEYBINDER
OPTIONS_DEFAULT=		KEYBINDER
KEYBINDER_DESC=			Keyboard shortcuts
KEYBINDER_LIB_DEPENDS=		libkeybinder-3.0.so:x11/keybinder-gtk3
KEYBINDER_CONFIGURE_ENABLE=	keybinder

.include <bsd.port.mk>
