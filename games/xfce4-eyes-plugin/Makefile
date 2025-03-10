PORTNAME=	xfce4-eyes-plugin
PORTVERSION=	4.6.2
CATEGORIES=	games xfce
MASTER_SITES=	XFCE/panel-plugins

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Panel plugin that adds eyes which watch your every step
WWW=		https://docs.xfce.org/panel-plugins/xfce4-eyes-plugin

LICENSE=	GPLv2

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gtk30
USE_XFCE=	libmenu panel
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
