# Created by: Ron van Daal
# $FreeBSD$

PORTNAME=	GraphicsMagick
PORTVERSION=	1.3.23
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF \
		ftp://ftp.graphicsmagick.org/pub/GraphicsMagick/${PORTVERSION:R}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast image processing tools based on ImageMagick

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libjbig.so:graphics/jbigkit \
		libjasper.so:graphics/jasper \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

OPTIONS_DEFINE=	DOCS DPS FPX OPENMP Q8BIT SSE TEST WEBP WMF X11 XML
OPTIONS_DEFAULT=OPENMP WEBP WMF X11 XML
DPS_DESC=	Display Ghostscript support
Q8BIT_DESC=	Use 8-bit pixels (speed) instead of 16-bit (quality)
TEST_DESC=	Run bundled self-tests after build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static \
		--with-windows-font-dir=${WINDOWS_FONT_DIR} --without-perl
CONFIGURE_ENV=	PTHREAD_LIBS=-lpthread
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		jpeg libtool localbase tar:bzip2

PORTDATA=	*
PORTDOCS=	*

# Use fonts installed by x11-fonts/webfonts by default
WINDOWS_FONT_DIR?=	${LOCALBASE}/share/fonts/webfonts

DPS_CONFIGURE_WITH=	dps
DPS_IMPLIES=		X11
DPS_LIB_DEPENDS=	libdps.so:x11/dgs
DPS_USE=		XORG=xt
FPX_CONFIGURE_WITH=	fpx
FPX_LIB_DEPENDS=	libfpx.so:graphics/libfpx
OPENMP_CONFIGURE_OFF=	--without-threads --disable-openmp
OPENMP_CONFIGURE_ON=	--with-threads --enable-openmp --disable-openmp-slow
OPENMP_USES=		compiler:openmp
Q8BIT_CONFIGURE_OFF=	--with-quantum-depth=16
Q8BIT_CONFIGURE_ON=	--with-quantum-depth=8
Q8BIT_PLIST_SUB=	Q=8
Q8BIT_PLIST_SUB_OFF=	Q=16
TEST_BUILD_DEPENDS=	webfonts>=0:x11-fonts/webfonts
TEST_RUN_DEPENDS=	webfonts>=0:x11-fonts/webfonts
WEBP_CONFIGURE_WITH=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WMF_CONFIGURE_WITH=	wmf
X11_CONFIGURE_WITH=	x
X11_USE=		XORG=xext
XML_CONFIGURE_WITH=	xml
XML_USE=		GNOME=libxml2

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

# The OPENMP option may select gcc as compiler but on architectures
# that have switched to libc++ clang should be used for C++ code.
CXX=		c++
