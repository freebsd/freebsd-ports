# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$

PORTNAME=	gdk-pixbuf
PORTVERSION=	2.32.1
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for GTK+

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	xt xi x11
USES=		cpe gmake libtool pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME+=	glib20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-introspection=yes --with-x11
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JASPER JPEG PNG TIFF NLS
OPTIONS_DEFAULT=JASPER JPEG PNG TIFF NLS
JASPER_CONFIGURE_WITH=	libjasper
JASPER_LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper
JPEG_CONFIGURE_WITH=	libjpeg
JPEG_USES=		jpeg
PNG_CONFIGURE_WITH=	libpng
PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
TIFF_CONFIGURE_WITH=	libtiff
TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-install:
	@cd ${WRKSRC}/docs/reference/gdk-pixbuf && env DESTDIR=${STAGEDIR} ${GMAKE} install-man1

.include <bsd.port.mk>
