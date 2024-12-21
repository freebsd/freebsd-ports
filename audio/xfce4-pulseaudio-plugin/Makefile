PORTNAME=	xfce4-pulseaudio-plugin
PORTVERSION=	0.4.9
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Panel plugin for controlling PulseAudio mixer
WWW=		https://gitlab.xfce.org/panel-plugins/xfce4-pulseaudio-plugin

LICENSE=	GPLv2

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libharfbuzz.so:print/harfbuzz \
		libnotify.so:devel/libnotify \
		libpulse-mainloop-glib.so:audio/pulseaudio
RUN_DEPENDS=	pavucontrol>=2.0:audio/pavucontrol

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libwnck3
USE_XFCE=	libexo panel windowing xfconf
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libxfce4windowing \
		--enable-mpris2 \
		--enable-wnck \
		--with-mixer-command=${LOCALBASE}/bin/pavucontrol
INSTALL_TARGET=	install-strip

CFLAGS+=	-Wno-return-type

OPTIONS_DEFINE=		KEYBINDER NLS
OPTIONS_DEFAULT=	KEYBINDER
OPTIONS_SUB=		yes

KEYBINDER_DESC=			Keyboard shortcuts
KEYBINDER_LIB_DEPENDS=		libkeybinder-3.0.so:x11/keybinder-gtk3
KEYBINDER_CONFIGURE_ENABLE=	keybinder

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
