PORTNAME=	fotocx
PORTVERSION=	26.8.1
CATEGORIES=	graphics
MASTER_SITES=	https://kornelix.net/downloads/downloads/ \
		https://fossies.org/linux/misc/ \
		https://fossies.org/linux/misc/legacy/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Image editing and collection management program
WWW=		https://kornelix.net/fotocx/fotocx.html

LICENSE=	GPLv3+

LIB_DEPENDS=	libjxl.so:graphics/libjxl \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		exiftool:graphics/p5-Image-ExifTool \
		ufraw-batch:graphics/ufraw

USES=		desktop-file-utils gmake gnome jpeg pkgconfig
USE_GNOME=	cairo glib20 gdkpixbuf gtk30
ALL_TARGET=	${PORTNAME}
CXXFLAGS+=	-Wno-register -Wno-writable-strings

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS NETMAP
OPTIONS_DEFAULT=	NETMAP
NETMAP_DESC=	World map support (requires WebKit)

NETMAP_LIB_DEPENDS=	libwebkit2gtk-4.1.so:www/webkit2-gtk@41
NETMAP_MAKE_ENV=	NETMAP_SUPPORT=1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
