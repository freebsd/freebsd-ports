# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	imv
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
CATEGORIES=	graphics

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple image viewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
TEST_DEPENDS=	${LOCALBASE}/lib/libcmocka.so:sysutils/cmocka

USES=		desktop-file-utils gmake pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	eXeC64
USE_SDL=	sdl2 ttf2

MAKE_ARGS=	CONFIGPREFIX=${PREFIX}/etc \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		MANPREFIX=${PREFIX}/man \
		V=1
ALL_TARGET=	imv doc
TEST_TARGET=	check

PLIST_FILES=	bin/imv \
		etc/imv_config \
		man/man1/imv.1.gz \
		man/man5/imv.5.gz \
		share/applications/imv.desktop

OPTIONS_DEFINE=		FREEIMAGE JPEG PNG SVG TIFF
OPTIONS_DEFAULT=	FREEIMAGE SVG

FREEIMAGE_DESC=	FreeImage backend (support for many image formats)

FREEIMAGE_LIB_DEPENDS=		libfreeimage.so:graphics/freeimage
FREEIMAGE_MAKE_ARGS_OFF=	BACKEND_FREEIMAGE=no
FREEIMAGE_MAKE_ARGS=		BACKEND_FREEIMAGE=yes

JPEG_LIB_DEPENDS=	libturbojpeg.so:graphics/libjpeg-turbo
JPEG_MAKE_ARGS_OFF=	BACKEND_LIBJPEG=no
JPEG_MAKE_ARGS=		BACKEND_LIBJPEG=yes

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MAKE_ARGS_OFF=	BACKEND_LIBPNG=no
PNG_MAKE_ARGS=		BACKEND_LIBPNG=yes

SVG_USES=		gnome
SVG_USE=		GNOME=cairo,librsvg2
SVG_MAKE_ARGS_OFF=	BACKEND_LIBRSVG=no
SVG_MAKE_ARGS=		BACKEND_LIBRSVG=yes

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MAKE_ARGS_OFF=	BACKEND_LIBTIFF=no
TIFF_MAKE_ARGS=		BACKEND_LIBTIFF=yes

.include <bsd.port.mk>
