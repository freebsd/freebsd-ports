PORTNAME=	xfce4-pulseaudio-plugin
PORTVERSION=	0.5.1
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Panel plugin for controlling PulseAudio mixer
WWW=		https://gitlab.xfce.org/panel-plugins/xfce4-pulseaudio-plugin

LICENSE=	GPLv2

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libnotify.so:devel/libnotify \
		libpulse-mainloop-glib.so:audio/pulseaudio
RUN_DEPENDS=	pavucontrol>=2.0:audio/pavucontrol

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz \
		xfce xorg
USE_GNOME=	cairo gdkpixbuf glib20 gtk30
USE_XFCE=	libexo panel windowing xfconf
USE_XORG=	x11

MESON_ARGS=	-Dlibcanberra=enabled \
		-Dlibnotify=enabled \
		-Dlibxfce4windowing=enabled \
		-Dmixer-command=${LOCALBASE}/bin/pavucontrol \
		-Dmpris2=enabled

OPTIONS_DEFINE=		KEYBINDER NLS
OPTIONS_DEFAULT=	KEYBINDER
OPTIONS_SUB=		yes

KEYBINDER_DESC=			Keyboard shortcuts
KEYBINDER_LIB_DEPENDS=		libkeybinder-3.0.so:x11/keybinder-gtk3
KEYBINDER_MESON_ENABLED=	keybinder

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
