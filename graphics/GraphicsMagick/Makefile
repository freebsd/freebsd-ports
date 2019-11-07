# Created by: Ron van Daal
# $FreeBSD$

PORTNAME=	GraphicsMagick
PORTVERSION=	1.3.33
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF \
		ftp://ftp.graphicsmagick.org/pub/GraphicsMagick/${PORTVERSION:R}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast image processing tools based on ImageMagick

LICENSE=	MIT

USES=		libtool localbase pathfix tar:bzip2

CONFIGURE_ARGS=	--enable-shared --enable-static \
		--with-windows-font-dir=${WINDOWS_FONT_DIR} \
		--without-perl --without-trio
CONFIGURE_ENV=	PTHREAD_LIBS=-lpthread
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

# Use fonts installed by x11-fonts/webfonts by default
WINDOWS_FONT_DIR?=	${LOCALBASE}/share/fonts/webfonts

OPTIONS_DEFINE=	BZIP2 DOCS FPX FREETYPE JASPER JBIG JPEG LCMS2 LZMA OPENMP Q8BIT PNG SSE TEST TIFF UMEM WEBP WMF X11 XML ZLIB ZSTD
OPTIONS_DEFAULT=BZIP2 FREETYPE JASPER JBIG JPEG LCMS2 LZMA OPENMP PNG TIFF WEBP WMF X11 XML ZLIB
Q8BIT_DESC=	Use 8-bit pixels (speed) instead of 16-bit (quality)
UMEM_DESC=	UMEM memory allocation library support
TEST_DESC=	Run bundled self-tests after build

BZIP2_CONFIGURE_WITH=	bzlib
FPX_CONFIGURE_WITH=	fpx
FPX_LIB_DEPENDS=	libfpx.so:graphics/libfpx
FREETYPE_CONFIGURE_WITH=ttf
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
JASPER_CONFIGURE_WITH=	jp2
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JBIG_CONFIGURE_WITH=	jbig
JBIG_LIB_DEPENDS=	libjbig.so:graphics/jbigkit
JPEG_CONFIGURE_WITH=	jpeg
JPEG_USES=		jpeg
LCMS2_CONFIGURE_WITH=	lcms2
LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LZMA_CONFIGURE_WITH=	lzma
OPENMP_CONFIGURE_OFF=	--disable-openmp --without-threads
OPENMP_CONFIGURE_ON=	--disable-openmp-slow --enable-openmp --with-threads
OPENMP_USES=		compiler:gcc-c++11-lib
PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png
Q8BIT_CONFIGURE_OFF=	--with-quantum-depth=16
Q8BIT_CONFIGURE_ON=	--with-quantum-depth=8
Q8BIT_PLIST_SUB=	Q=8
Q8BIT_PLIST_SUB_OFF=	Q=16
TEST_BUILD_DEPENDS=	webfonts>=0:x11-fonts/webfonts
TEST_RUN_DEPENDS=	webfonts>=0:x11-fonts/webfonts
TIFF_CONFIGURE_WITH=	tiff
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
UMEM_CONFIGURE_WITH=	umem
WEBP_CONFIGURE_WITH=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WMF_CONFIGURE_WITH=	wmf
X11_CONFIGURE_OFF=	ac_cv_lib_ICE_IceConnectionNumber=no
X11_CONFIGURE_WITH=	x
X11_USES=		xorg
X11_USE=		XORG=ice,sm,x11,xext
XML_CONFIGURE_WITH=	xml
XML_USE=		GNOME=libxml2
XML_USES=		gnome
ZLIB_CONFIGURE_WITH=	zlib
ZSTD_CONFIGURE_WITH=	zstd
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSE}
.if ${MACHINE_CPU:Msse}
CFLAGS+=	-msse
.endif
.if ${MACHINE_CPU:Msse2}
CFLAGS+=	-msse2
.endif
.if ${MACHINE_CPU:Msse3}
CFLAGS+=	-msse3
.endif
.endif

.if ${PORT_OPTIONS:MWMF}
.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=	libwmflite.so:graphics/libwmf
.else
LIB_DEPENDS+=	libwmflite.so:graphics/libwmf-nox11
.endif
.endif

post-install-Q8BIT-off:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/GraphicsMagick/modules-Q16/coders ${STAGEDIR}${PREFIX}/lib/GraphicsMagick/modules-Q16/filters

post-install-Q8BIT-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/GraphicsMagick/modules-Q8/coders ${STAGEDIR}${PREFIX}/lib/GraphicsMagick/modules-Q8/filters

.include <bsd.port.mk>
