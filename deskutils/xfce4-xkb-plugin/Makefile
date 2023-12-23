PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.8.3
PORTREVISION=	3
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/panel-plugins

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for the Xfce panel
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-xkb-plugin

LICENSE=	GPLv2

LIB_DEPENDS=	libxklavier.so:x11/libxklavier \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gtk30 intltool librsvg2 libwnck3
USE_XFCE=	garcon libmenu panel xfconf
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
