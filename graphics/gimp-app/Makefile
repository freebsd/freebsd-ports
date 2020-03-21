# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME?=	gimp-app
PORTVERSION=	2.10.18
PORTREVISION=	1
PORTEPOCH?=	1
CATEGORIES?=	graphics gnome
MASTER_SITES=	GIMP/gimp/v${PORTVERSION:R}
DISTNAME=	gimp-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNU Image Manipulation Program

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		glib-networking>=0:net/glib-networking \
		mypaint-brushes>0:graphics/mypaint-brushes
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libasound.so:audio/alsa-lib \
		liblcms2.so:graphics/lcms2 \
		libgegl-0.4.so:graphics/gegl \
		libbabl-0.1.so:x11/babl \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libpoppler-glib.so:graphics/poppler-glib \
		libgexiv2.so:graphics/gexiv2 \
		libjson-c.so:devel/json-c \
		libmypaint.so:graphics/libmypaint \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		glib-networking>=0:net/glib-networking \
		mypaint-brushes>0:graphics/mypaint-brushes

LIB_DEPENDS+=	libjson-glib-1.0.so:devel/json-glib \
		${LIB_DEPENDS_${ARCH}}

LIB_DEPENDS_aarch64=	libunwind.so:devel/libunwind
LIB_DEPENDS_amd64=	libunwind.so:devel/libunwind
LIB_DEPENDS_i386=	libunwind.so:devel/libunwind

GNU_CONFIGURE=	yes
USES+=		compiler:c++14-lang cpe gettext gmake gnome jpeg libtool \
		localbase pkgconfig shebangfix tar:bzip2 xorg
USE_XORG=	ice sm x11 xcursor xext xfixes xmu xpm xt
USE_GNOME+=	cairo gtk20 intltool librsvg2
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
.if !defined(XAUTHORITY)
TEST_ENV=	XAUTHORITY=${HOME}/.Xauthority
.endif
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc/gimp \
		--with-bug-report-url="https://bugs.freebsd.org/" \
		--disable-gtk-doc \
		--without-linux-input \
		--with-print \
		--without-gudev \
		--enable-default-binary \
		--disable-gimp-console \
		--disable-python \
		--without-appdata-test \
		--with-desktop-dir=${PREFIX}/share \
		--docdir=${PREFIX}/share/doc/gimp \
		--with-icc-directory=${LOCALBASE}/share/color/icc \
		--without-webkit \
		--enable-default-binary
CONFIGURE_ENV=	GIMP_THREAD_LIBS=-lpthread
LIBS+=		-lexecinfo -lm
CPE_PRODUCT=	gimp
CPE_VENDOR=	gnu

SHEBANG_FILES=	plug-ins/pygimp/plug-ins/*.py

PLIST_SUB+=	LIBVER=0.1000.${PORTVERSION:E}

.if !defined(GIMP_SLAVE)

USES+=		desktop-file-utils

OPTIONS_DEFINE?=	AA GHOSTSCRIPT \
			LIBHEIF LIBMNG OPENEXR OPENJPEG SIMD WEBP WMF
OPTIONS_DEFAULT=	AA LIBMNG OPENEXR OPENJPEG SIMD WEBP WMF
OPTIONS_SUB=		yes

.endif

.if defined(GIMP_SLAVE)
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
GIMP_LIBS=	`${PKG_CONFIG} --libs gimp-2.0`
GIMP_THUMB_LIBS=`${PKG_CONFIG} --libs gimpthumb-2.0`
GIMP_UI_LIBS=	`${PKG_CONFIG} --libs gimpui-2.0`

LIB_DEPENDS+=	libgimp-2.0.so:graphics/gimp-app

.else

DEBUG_CONFIGURE_ON=	--enable-debug

AA_DESC=		Ascii-art Plug-in
AA_LIB_DEPENDS=		libaa.so:graphics/aalib
AA_CONFIGURE_WITH=	aa

LIBHEIF_DESC=		ISO/IEC 23008-12:2017 HEIF file format support
LIBHEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
LIBHEIF_CONFIGURE_WITH=	libheif

GHOSTSCRIPT_USES=		ghostscript
GHOSTSCRIPT_CONFIGURE_WITH=	gs

LIBMNG_LIB_DEPENDS=	libmng.so:graphics/libmng
LIBMNG_CONFIGURE_WITH=	libmng

OPENEXR_CONFIGURE_WITH=	openexr
OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr \
			libIex.so:graphics/ilmbase

OPENJPEG_DESC=		Enhanced JPEG (jpeg2000) graphics support
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_CONFIGURE_WITH=jpeg2000

SIMD_CONFIGURE_OFF=	--disable-mmx \
			--disable-sse \
			--disable-altivec

WEBP_CONFIGURE_WITH=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

WMF_LIB_DEPENDS=	libwmf.so:graphics/libwmf
WMF_CONFIGURE_WITH=	wmf

.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%GIMP_LIBS%%|${GIMP_LIBS}|; \
		s|%%GIMP_THUMB_LIBS%%|${GIMP_THUMB_LIBS}|; \
		s|%%GIMP_UI_LIBS%%|${GIMP_UI_LIBS}|' \
			${WRKSRC}/plug-ins/pygimp/Makefile.in
	@${REINPLACE_CMD} \
		-e 's|x86_64|amd64|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
