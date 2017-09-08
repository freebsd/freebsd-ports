# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME?=	gimp-app
PORTVERSION=	2.8.22
PORTREVISION=	1
PORTEPOCH?=	1
CATEGORIES?=	graphics gnome
MASTER_SITES=	GIMP/gimp/v${PORTVERSION:R}
DISTNAME=	gimp-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNU Image Manipulation Program

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		liblcms2.so:graphics/lcms2 \
		libgegl-0.2.so:graphics/gegl \
		libbabl-0.1.so:x11/babl \
		libfontconfig.so:x11-fonts/fontconfig \
		libdbus-1.so:devel/dbus \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes

GNU_CONFIGURE=	yes
USES+=		cpe execinfo gettext gmake jpeg libtool \
		localbase pathfix pkgconfig shebangfix tar:bzip2
USE_XORG=	ice sm xcursor xext xfixes xmu xpm xt x11
USE_GNOME+=	cairo gtk20 intlhack
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
.if !defined(XAUTHORITY)
TEST_ENV=	XAUTHORITY=${HOME}/.Xauthority
.endif
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc/gimp \
		--disable-gtk-doc \
		--without-linux-input \
		--with-print \
		--enable-default-binary \
		--with-lcms=lcms2 \
		--disable-gimp-console \
		--disable-python \
		--with-desktop-dir=${PREFIX}/share \
		--docdir=${PREFIX}/share/doc/gimp \
		--enable-default-binary
CONFIGURE_ENV=	GIMP_THREAD_LIBS=-lpthread
LIBS+=		-lexecinfo
CPE_PRODUCT=	gimp
CPE_VENDOR=	gnu

SHEBANG_FILES=	plug-ins/pygimp/plug-ins/*.py

PLIST_SUB+=	LIBVER=0.800.${PORTVERSION:E}

.if !defined(GIMP_SLAVE)

USES+=		desktop-file-utils

OPTIONS_DEFINE?=	AA DBUS LIBEXIF GHOSTSCRIPT GVFS HELPBROWSER JASPER \
			LIBMNG LIBRSVG2 POPPLER SIMD WMF
OPTIONS_DEFAULT=	AA DBUS LIBEXIF GVFS HELPBROWSER LIBMNG LIBRSVG2 \
			POPPLER WMF
OPTIONS_SUB=		yes
AA_DESC=		Ascii-art Plug-in
HELPBROWSER_DESC=	Internal help browser

.endif

.if defined(GIMP_SLAVE)
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
GIMP_LIBS=	`${PKG_CONFIG} --libs gimp-2.0`
GIMP_THUMB_LIBS=`${PKG_CONFIG} --libs gimpthumb-2.0`
GIMP_UI_LIBS=	`${PKG_CONFIG} --libs gimpui-2.0`

LIB_DEPENDS+=	libgimp-2.0.so:graphics/gimp-app

.else

DEBUG_CONFIGURE_ON=	--enable-debug

AA_LIB_DEPENDS=		libaa.so:graphics/aalib
AA_CONFIGURE_OFF=	--without-aa

DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_CONFIGURE_WITH=	dbus

GHOSTSCRIPT_USES=		ghostscript
GHOSTSCRIPT_CONFIGURE_WITH=	gs

GVFS_USE=		GNOME=gvfs
GVFS_LIB_DEPENDS_OFF=	libcurl.so:ftp/curl
GVFS_CONFIGURE_OFF=	--without-gvfs

HELPBROWSER_LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2 \
				libsoup-2.4.so:devel/libsoup
HELPBROWSER_CONFIGURE_WITH=	webkit

JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_CONFIGURE_WITH=	libjasper

LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBEXIF_CONFIGURE_OFF=	--without-libexif

LIBMNG_LIB_DEPENDS=	libmng.so:graphics/libmng
LIBMNG_CONFIGURE_OFF=	--without-libmng

LIBRSVG2_USE= 		GNOME=librsvg2
LIBRSVG2_CONFIGURE_WITH=librsvg

POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_CONFIGURE_OFF=	--without-poppler

SIMD_CONFIGURE_OFF=	--disable-mmx \
			--disable-sse \
			--disable-altivec

WMF_LIB_DEPENDS=	libwmf.so:graphics/libwmf
WMF_CONFIGURE_OFF=	--without-wmf

.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%GIMP_LIBS%%|${GIMP_LIBS}|; \
		s|%%GIMP_THUMB_LIBS%%|${GIMP_THUMB_LIBS}|; \
		s|%%GIMP_UI_LIBS%%|${GIMP_UI_LIBS}|' \
			${WRKSRC}/plug-ins/pygimp/Makefile.in
	@${REINPLACE_CMD} -e 's/-u /-Wl,-u,/' \
		${WRKSRC}/app/Makefile.in
	@${REINPLACE_CMD} -e 's|"libpng"|"libpng15"|' \
		-e 's|x86_64|amd64|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
