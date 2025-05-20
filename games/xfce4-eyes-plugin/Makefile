PORTNAME=	xfce4-eyes-plugin
PORTVERSION=	4.7.0
CATEGORIES=	games xfce
MASTER_SITES=	XFCE/panel-plugins

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Panel plugin that adds eyes which watch your every step
WWW=		https://docs.xfce.org/panel-plugins/xfce4-eyes-plugin

LICENSE=	GPLv2

USES=		gettext-tools gnome meson pkgconfig tar:xz xfce xorg
USE_GNOME=	gtk30
USE_XFCE=	libmenu panel
USE_XORG=	x11

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
