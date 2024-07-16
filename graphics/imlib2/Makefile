PORTNAME=	imlib2
DISTVERSION=	1.12.3
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	SF/enlightenment/imlib2-src/${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Next generation graphics library for Enlightenment
WWW=		https://docs.enlightenment.org/api/imlib2/html/

LICENSE=	imlib2
LICENSE_NAME=	imlib2 license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cpe libtool localbase:ldflags pathfix pkgconfig tar:xz
CPE_VENDOR=	enlightenment
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-visibility-hiding \
		--with-zlib

INSTALL_TARGET=	install-strip

PLIST_SUB=	SHLIB_SHORT=${DISTVERSION:R:R} \
		SHLIB_VER=${DISTVERSION}

OPTIONS_DEFINE=		GIF ID3 JPEG JXL PNG TIFF WEBP X11
OPTIONS_DEFAULT=	GIF ID3 JPEG JXL PNG TIFF WEBP X11
OPTIONS_SUB=		yes

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_WITH=	gif

ID3_LIB_DEPENDS=	libid3tag.so:audio/libid3tag
ID3_CONFIGURE_WITH=	id3

JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	jpeg

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_CONFIGURE_WITH=	jxl
JXL_CONFLICTS_INSTALL=	imlib2-jxl

PNG_LIB_DEPENDS=	libpng16.so:graphics/png
PNG_CONFIGURE_WITH=	png

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=	tiff

WEBP_LIB_DEPENDS=	libwebpdemux.so:graphics/webp
WEBP_CONFIGURE_WITH=	webp
WEBP_CONFLICTS_INSTALL=	imlib2-webp

X11_USES=		xorg
X11_USE=		XORG=sm,x11,xcb,xext
X11_CONFIGURE_WITH=	x x-shm-fd

.include <bsd.port.options.mk>

# scaling: MMX asm scaling causes segv, disable for now
.if ${ARCH} == "i386" && !empty(MACHINE_CPU:Mmmx)
CONFIGURE_ARGS+=	--disable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-amd64
.else
CONFIGURE_ARGS+=	--disable-amd64
.endif

.include <bsd.port.mk>
