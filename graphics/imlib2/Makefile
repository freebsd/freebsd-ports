# Created by: Jeremy Norris <ishmael27@home.com>

PORTNAME=	imlib2
PORTVERSION=	1.7.0
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	SF/enlightenment/imlib2-src/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The next generation graphics library for Enlightenment

LICENSE=	imlib2
LICENSE_NAME=	imlib2 license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cpe libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPE_VENDOR=	enlightenment

CONFIGURE_ARGS=	--enable-visibility-hiding --disable-static \
		--with-zlib --with-bzip2
CONFIGURE_ENV=	ac_cv_lib_dl_dlopen=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	imlib2-webp

OPTIONS_DEFINE=		GIF ID3 JPEG PNG TIFF WEBP X11
OPTIONS_DEFAULT=	GIF ID3 JPEG PNG TIFF WEBP X11
OPTIONS_SUB=	yes

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_WITH=	gif

ID3_LIB_DEPENDS=	libid3tag.so:audio/libid3tag
ID3_CONFIGURE_WITH=	id3

JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	jpeg

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=	tiff

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_WITH=	webp

X11_USES=		xorg
X11_USE=		XORG=x11,sm,xcb,xext
X11_CONFIGURE_WITH=	x x-shm-fd

.include <bsd.port.options.mk>

.if ${ARCH} == "i386" && !empty(MACHINE_CPU:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-amd64
.else
CONFIGURE_ARGS+=	--disable-amd64
.endif

.include <bsd.port.mk>
