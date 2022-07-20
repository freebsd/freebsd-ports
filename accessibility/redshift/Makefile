PORTNAME=	redshift
PORTVERSION=	1.12
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	accessibility wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	60f45972a543.patch:-p1 # avoid patch conflict
PATCHFILES+=	7da875d34854.patch:-p1 # wayland, see #663

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Adjusts the color temperature of your screen

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		autoreconf:build gettext gmake gnome libtool localbase \
		pkgconfig shebangfix tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	jonls
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
SHEBANG_FILES=	src/redshift-gtk/redshift-gtk.in

CONFIGURE_ARGS+=	--disable-wingdi

OPTIONS_DEFINE=	GEO GUI NLS RANDR VIDMODE WAYLAND
OPTIONS_DEFAULT=GEO RANDR WAYLAND
OPTIONS_SUB=	yes

GUI_DESC=	Tray icon
RANDR_DESC=	Support RANDR for changing colors
VIDMODE_DESC=	Support VIDMODE for changing colors (NVIDIA)
WAYLAND_DESC=	Support Wayland (wlroots) for changing colors
GEO_DESC=	Use geoclue (requires dbus)

NLS_USES=		iconv
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG} \
			--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

RANDR_USES=		xorg
RANDR_USE=		XORG=xcb,xrandr
RANDR_CONFIGURE_ENABLE=	randr

VIDMODE_USES=		xorg
VIDMODE_USE=		XORG=x11,xxf86vm
VIDMODE_CONFIGURE_ENABLE=	vidmode

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	wayland

GUI_USES=		python:3.6+
GUI_CONFIGURE_ENABLE=	gui
GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}

GEO_CONFIGURE_ON=	--enable-geoclue2
GEO_CONFIGURE_OFF=	--disable-geoclue2
GEO_LIB_DEPENDS=	libgeoclue-2.so:net/geoclue

pre-configure:
	@cd ${WRKSRC} ; ./bootstrap

.include <bsd.port.mk>
