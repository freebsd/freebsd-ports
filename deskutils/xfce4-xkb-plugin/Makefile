PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.9.0
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/panel-plugins

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for the Xfce panel
WWW=		https://docs.xfce.org/panel-plugins/xfce4-xkb-plugin

LICENSE=	GPLv2

LIB_DEPENDS=	libxklavier.so:x11/libxklavier

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce \
		xorg
USE_GNOME=	gtk30 librsvg2 libwnck3
USE_XFCE=	garcon libmenu panel xfconf
USE_XORG=	x11

OPTIONS_DEFINE=		NLS NOTIFY
OPTIONS_DEFAULT=	NOTIFY
OPTIONS_SUB=		yes

NLS_USES=	gettext-runtime

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MESON_ENABLED=	libnotify

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
