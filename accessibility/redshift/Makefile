# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redshift
PORTVERSION=	1.11
CATEGORIES=	accessibility
DISTVERSIONPREFIX=	v

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Adjusts the color temperature of your screen

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake libtool localbase pkgconfig shebangfix tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	jonls
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
SHEBANG_FILES=	src/redshift-gtk/redshift-gtk.in

CONFIGURE_ARGS+=	--disable-wingdi

BUILD_DEPENDS=	autoconf-2.69:devel/autoconf \
		automake-1.15:devel/automake \
		libtoolize:devel/libtool \
		intltool>=0:textproc/intltool

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libgeoclue-2.so:net/geoclue

OPTIONS_DEFINE=	GNOME GUI NLS RANDR VIDMODE
OPTIONS_DEFAULT=RANDR
OPTIONS_SUB=	yes

GNOME_DESC=	GNOME clock support
GUI_DESC=	Tray icon
RANDR_DESC=	Support RANDR for changing colors
VIDMODE_DESC=	Support VIDMODE for changing colors (NVIDIA)

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


GNOME_CONFIGURE_ENABLE=	gnome-clock
GNOME_USE=		GNOME=glib20,gconf2

pre-configure:
	@cd ${WRKSRC} ; ./bootstrap

.include <bsd.port.mk>
