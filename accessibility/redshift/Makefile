# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redshift
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	accessibility
MASTER_SITES=	http://launchpad.net/redshift/trunk/${PORTVERSION}/+download/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Adjusts the color temperature of your screen

USES=		gmake pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS+=	--disable-wingdi

OPTIONS_DEFINE=	GNOME GUI NLS RANDR VIDMODE
OPTIONS_DEFAULT=RANDR
OPTIONS_SUB=	yes

GNOME_DESC=	GNOME clock support
GUI_DESC=	Tray icon
RANDR_DESC=	Support RANDR for changing colors
VIDMODE_DESC=	Support VIDMODE for changing colors (NVIDIA)

USE_XORG+=	x11 xcb

NLS_USES=		gettext iconv
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG} \
			--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

RANDR_USE=		XORG=xrandr
RANDR_CONFIGURE_ENABLE=	randr

VIDMODE_USE=		XORG=xxf86vm
VIDMODE_CONFIGURE_ENABLE=	vidmode

GUI_USES=		python
GUI_CONFIGURE_ENABLE=	gui
GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk2>0:x11-toolkits/py-gtk2 \
			${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg

GNOME_CONFIGURE_ENABLE=	gnome-clock
GNOME_USE=		GNOME=glib20,gconf2

.include <bsd.port.mk>
