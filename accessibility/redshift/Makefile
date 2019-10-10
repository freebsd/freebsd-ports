# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redshift
PORTVERSION=	1.12
DISTVERSIONPREFIX=	v
CATEGORIES=	accessibility

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Adjusts the color temperature of your screen

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		autoreconf:build gettext gmake gnome libtool localbase \
		pkgconfig shebangfix tar:bzip2 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	jonls
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
SHEBANG_FILES=	src/redshift-gtk/redshift-gtk.in

CONFIGURE_ARGS+=	--disable-wingdi

OPTIONS_DEFINE=	GEO GUI NLS RANDR VIDMODE
OPTIONS_DEFAULT=GEO RANDR
OPTIONS_SUB=	yes

GUI_DESC=	Tray icon
RANDR_DESC=	Support RANDR for changing colors
VIDMODE_DESC=	Support VIDMODE for changing colors (NVIDIA)
GEO_DESC=	Use geoclue (requires dbus)

USE_XORG+=	x11 xcb

NLS_USES=		iconv
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG} \
			--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

RANDR_USE=		XORG=xrandr
RANDR_CONFIGURE_ENABLE=	randr

VIDMODE_USE=		XORG=xxf86vm
VIDMODE_CONFIGURE_ENABLE=	vidmode

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
