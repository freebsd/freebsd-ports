# Created by: Oliver Heesakkers <dev2@heesakkers.info>
# $FreeBSD$

PORTNAME=	zbar
DISTVERSION=	0.23.90
CATEGORIES=	graphics
MASTER_SITES=	https://linuxtv.org/downloads/zbar/

MAINTAINER=	dev2@heesakkers.info
COMMENT=	ZBar barcode reader

LICENSE=	LGPL21

USES=		autoreconf gmake iconv libtool localbase:ldflags pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-java --without-npapi --without-python \
		--enable-codes=ean,databar,code128,code93,code39,codabar,i25,qrcode,sqcode,pdf417

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			DBUS DOCS GIR JPEG NLS QT5 V4L X11
OPTIONS_DEFAULT=		GTK_NONE IMAGEMAGICK JPEG NLS X11
OPTIONS_RADIO=			MAGICK
OPTIONS_RADIO_MAGICK=		GRAPHICSMAGICK IMAGEMAGICK
OPTIONS_SINGLE=			GTK
OPTIONS_SINGLE_GTK=		GTK2 GTK3 GTK_NONE
OPTIONS_SUB=			yes

GIR_DESC=			Build Gobject Introspection
GTK_DESC=			GTK support
GTK_NONE_DESC=			Build without GTK support
GRAPHICSMAGICK_DESC=		GraphicsMagick image processing support
MAGICK_DESC=			*Magick image processing support
V4L_DESC=			Build zbarcam video scanner

DBUS_LIB_DEPENDS=		libdbus-1.so:devel/dbus
DBUS_CONFIGURE_WITH=		dbus

DOCS_BUILD_DEPENDS=		xmlto:textproc/xmlto
DOCS_CONFIGURE_ENABLE=		doc

GIR_USES=			gnome
GIR_USE=			GNOME=introspection:build
GIR_CONFIGURE_WITH=		gir

GTK2_USES=			gnome gettext-runtime
GTK2_USE=			GNOME=atk,cairo,gdkpixbuf2,glib20,gtk20,pango
GTK2_LIB_DEPENDS=		libfreetype.so:print/freetype2 \
				libfontconfig.so:x11-fonts/fontconfig
GTK2_CONFIGURE_ON=		--with-gtk=gtk2

GTK3_USES=			gnome gettext-runtime
GTK3_USE=			GNOME=atk,cairo,gdkpixbuf2,glib20,gtk30,pango
GTK3_CONFIGURE_ON=		--with-gtk=gtk3

GTK_NONE_CONFIGURE_ON=		--with-gtk=no

GRAPHICSMAGICK_LIB_DEPENDS=	libGraphicsMagickWand.so:graphics/GraphicsMagick
GRAPHICSMAGICK_CONFIGURE_WITH=	graphicsmagick

IMAGEMAGICK_LIB_DEPENDS=	libMagickWand-${IMAGEMAGICK_DEFAULT}.so:graphics/ImageMagick${IMAGEMAGICK_DEFAULT}
IMAGEMAGICK_CONFIGURE_WITH=	imagemagick

JPEG_USES=			jpeg
JPEG_CONFIGURE_WITH=		jpeg

NLS_USES=			gettext
NLS_LDFLAGS=			-lintl
NLS_CONFIGURE_ENABLE=		nls

QT5_USES=			qt:5
QT5_USE=			QT=core,gui,widgets,x11extras,buildtools_build
QT5_CONFIGURE_WITH=		qt qt5
QT5_IMPLIES=			X11

V4L_BUILD_DEPENDS=		v4l_compat>=1.0.20101027:multimedia/v4l_compat
V4L_LIB_DEPENDS=		libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_ENABLE=		video

X11_USES=			xorg
X11_USE=			XORG=ice,sm,x11,xau,xcb,xdmcp,xext,xv
X11_CONFIGURE_ON=		--with-x --with-xv --with-xshm
X11_CONFIGURE_OFF=		--without-x --without-xshm --without-xv

.include <bsd.port.mk>
