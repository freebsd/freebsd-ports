# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-pulseaudio-plugin
PORTVERSION=	0.4.2
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Panel plugin for controlling PulseAudio mixer

LICENSE=	GPLv2

LIB_DEPENDS=	libpulse-mainloop-glib.so:audio/pulseaudio \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	pavucontrol>=2.0:audio/pavucontrol

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo glib20 gtk30 intltool libwnck3
USE_XFCE=	panel
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--with-mixer-command=${LOCALBASE}/bin/pavucontrol \
		--enable-mpris2 \
		--enable-wnck
CFLAGS+=	-Wno-return-type

OPTIONS_DEFINE=			KEYBINDER NLS
OPTIONS_DEFAULT=		KEYBINDER
OPTIONS_SUB=			yes

KEYBINDER_DESC=			Keyboard shortcuts
KEYBINDER_LIB_DEPENDS=		libkeybinder-3.0.so:x11/keybinder-gtk3
KEYBINDER_CONFIGURE_ENABLE=	keybinder

NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext-runtime

.include <bsd.port.mk>
