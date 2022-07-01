# Created by: erich@FreeBSD.org

PORTNAME?=	gimp
PORTVERSION=	2.10.32
PORTREVISION=	2
PORTEPOCH?=	1
CATEGORIES?=	graphics gnome
MASTER_SITES=	GIMP/gimp/v${PORTVERSION:R}
PKGNAMESUFFIX=	-app
#DISTNAME=	gimp-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNU Image Manipulation Program

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		glib-networking>=0:net/glib-networking \
		mypaint-brushes>0:graphics/mypaint-brushes

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libbabl-0.1.so:x11/babl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgegl-0.4.so:graphics/gegl \
		libgexiv2.so:graphics/gexiv2 \
		libharfbuzz.so:print/harfbuzz \
		libjson-c.so:devel/json-c \
		libjson-glib-1.0.so:devel/json-glib \
		liblcms2.so:graphics/lcms2 \
		libmypaint.so:graphics/libmypaint \
		libpng.so:graphics/png \
		libpoppler-glib.so:graphics/poppler-glib \
		libtiff.so:graphics/tiff
LIB_DEPENDS+=	${LIB_DEPENDS_${ARCH}}

LIB_DEPENDS_aarch64=	libunwind.so:devel/libunwind
LIB_DEPENDS_amd64=	libunwind.so:devel/libunwind
LIB_DEPENDS_armv7=	libunwind.so:devel/libunwind
LIB_DEPENDS_i386=	libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64=		libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64le=	libunwind.so:devel/libunwind

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		glib-networking>=0:net/glib-networking \
		mypaint-brushes>0:graphics/mypaint-brushes

USES+=		compiler:c++14-lang cpe gettext gmake gnome jpeg libtool \
		localbase pkgconfig shebangfix tar:bzip2 xorg
CPE_VENDOR=	gimp
CPE_PRODUCT=	gimp
USE_GNOME+=	cairo gtk20 intltool librsvg2
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xcursor xext xfixes xmu xpm xt

SHEBANG_FILES=	plug-ins/pygimp/plug-ins/*.py

GNU_CONFIGURE=		yes
CONFIGURE_ARGS?=	--with-html-dir=${PREFIX}/share/doc/gimp \
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
CONFIGURE_ENV=		GIMP_THREAD_LIBS=-lpthread

INSTALL_TARGET=	install-strip
.if !defined(XAUTHORITY)
TEST_ENV=	XAUTHORITY=${HOME}/.Xauthority
.endif
TEST_TARGET=	check

LIBS+=		-lexecinfo -lm

PLIST_SUB+=	LIBVER=0.1000.${PORTVERSION:E}

.if !defined(GIMP_SLAVE)

USES+=		desktop-file-utils

OPTIONS_DEFINE?=	AALIB GHOSTSCRIPT HEIF JXL LIBMNG OPENEXR OPENJPEG SIMD \
			WEBP WMF
OPTIONS_DEFAULT=	AALIB HEIF JXL LIBMNG OPENEXR OPENJPEG SIMD WEBP WMF
OPTIONS_SUB=		yes

.endif

.if defined(GIMP_SLAVE)
PKG_CONFIG?=		${LOCALBASE}/bin/pkg-config
GIMP_LIBS=		`${PKG_CONFIG} --libs gimp-2.0`
GIMP_THUMB_LIBS=	`${PKG_CONFIG} --libs gimpthumb-2.0`
GIMP_UI_LIBS=		`${PKG_CONFIG} --libs gimpui-2.0`

LIB_DEPENDS+=	libgimp-2.0.so:graphics/gimp-app

.else

DEBUG_CONFIGURE_ON=	--enable-debug

AALIB_DESC=	Ascii-art Plug-in
OPENJPEG_DESC=	Enhanced JPEG (jpeg2000) graphics support

AALIB_LIB_DEPENDS=	libaa.so:graphics/aalib
AALIB_CONFIGURE_WITH=	aa

GHOSTSCRIPT_USES=		ghostscript
GHOSTSCRIPT_CONFIGURE_WITH=	gs

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_CONFIGURE_WITH=	libheif

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_CONFIGURE_WITH=	jpegxl

LIBMNG_LIB_DEPENDS=	libmng.so:graphics/libmng
LIBMNG_CONFIGURE_WITH=	libmng

OPENEXR_LIB_DEPENDS=	libImath.so:math/Imath \
			libOpenEXR.so:graphics/openexr
OPENEXR_CONFIGURE_WITH=	openexr

OPENJPEG_LIB_DEPENDS=		libopenjp2.so:graphics/openjpeg
OPENJPEG_CONFIGURE_WITH=	jpeg2000

SIMD_CONFIGURE_OFF=	--disable-mmx \
			--disable-sse \
			--disable-altivec

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_WITH=	webp

WMF_LIB_DEPENDS=	libexpat.so:textproc/expat2 \
			libwmf.so:graphics/libwmf

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
