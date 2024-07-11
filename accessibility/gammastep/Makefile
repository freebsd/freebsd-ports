PORTNAME=	gammastep
PORTVERSION=	2.0.9
DISTVERSIONPREFIX=	v
CATEGORIES=	accessibility

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Adjust the color temperature of your screen
WWW=		https://gitlab.com/chinstrap/gammastep

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=			autoreconf gettext-tools gmake gnome libtool \
			localbase pkgconfig shebangfix tar:bzip2
USE_GITLAB=		yes
GL_ACCOUNT=		chinstrap
USE_GNOME=		intltool
GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
SHEBANG_FILES=		src/gammastep_indicator/gammastep-indicator.in

OPTIONS_DEFINE=		GEO GUI NLS RANDR VIDMODE WAYLAND
OPTIONS_DEFAULT=	GEO RANDR WAYLAND
OPTIONS_SUB=		yes

GEO_DESC=		Use geoclue (requires dbus)
GUI_DESC=		Tray icon
RANDR_DESC=		Support RANDR for changing colors
VIDMODE_DESC=		Support VIDMODE for changing colors (NVIDIA)
WAYLAND_DESC=		Support Wayland (wlroots) for changing colors

GEO_BUILD_DEPENDS=	geoclue>=0:net/geoclue
GEO_RUN_DEPENDS=	geoclue>=0:net/geoclue
GEO_USE=		GNOME=glib20
GEO_CONFIGURE_ENABLE=	geoclue2

GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}
GUI_USES=		python
GUI_CONFIGURE_ENABLE=	gui

NLS_USES=		gettext-runtime iconv
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}
NLS_CONFIGURE_ENABLE=	nls

RANDR_USES=		xorg
RANDR_USE=		XORG=xcb,xrandr
RANDR_CONFIGURE_ENABLE=	randr

VIDMODE_USES=			xorg
VIDMODE_USE=			XORG=x11,xxf86vm
VIDMODE_CONFIGURE_ENABLE=	vidmode

WAYLAND_CATEGORIES=		wayland
WAYLAND_LIB_DEPENDS=		libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	wayland

.include <bsd.port.mk>
