# $FreeBSD$

PORTNAME=	webp-pixbuf-loader
PORTVERSION=	20160329
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	WebP image loader plugin for GdkPixbuf2

LICENSE=	LGPL20+

LIB_DEPENDS=	libwebp.so:graphics/webp

USES=		gnome perl5 pkgconfig waf
USE_GNOME=	gdkpixbuf2
USE_GITHUB=	yes
GH_ACCOUNT=	aruiz
GH_TAGNAME=	9b92950d49d7

PLIST_FILES=	lib/gdk-pixbuf-2.0/${GTK2_VERSION}/loaders/libpixbufloader-webp.so \
		share/thumbnailers/gdk-pixbuf-webp-thumbnailer.thumbnailer

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gdk-pixbuf-2.0/*/loaders/*
	${MKDIR} ${STAGEDIR}${PREFIX}/share/thumbnailers
	${SED} -e 's|@PREFIX@|${LOCALBASE}|g' ${FILESDIR}/gdk-pixbuf-webp-thumbnailer.thumbnailer \
			> ${STAGEDIR}${PREFIX}/share/thumbnailers/gdk-pixbuf-webp-thumbnailer.thumbnailer

.include <bsd.port.mk>
