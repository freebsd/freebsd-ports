PORTNAME=	libsvg
PORTVERSION=	0.1.4
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Parser for SVG content in files or buffers

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USES=		gnome iconv jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	include/svg.h \
		lib/libsvg.a \
		lib/libsvg.so \
		lib/libsvg.so.1 \
		lib/libsvg.so.1.0.0 \
		libdata/pkgconfig/libsvg.pc

.include <bsd.port.mk>
