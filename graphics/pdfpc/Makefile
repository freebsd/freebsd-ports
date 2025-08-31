PORTNAME=	pdfpc
DISTVERSION=	4.7.0
PORTREVISION=	2
CATEGORIES=	graphics
DISTVERSIONPREFIX=	v
PORTREVISION=	1

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Keynote-like multi-monitor presentation viewer
WWW=		https://pdfpc.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libmarkdown.a:textproc/discount
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libharfbuzz.so:print/harfbuzz \
		libjson-glib-1.0.so:devel/json-glib \
		libmarkdown.so:textproc/discount \
		libpoppler-glib.so:graphics/poppler-glib \
		libqrencode.so:graphics/libqrencode \
		libsoup-3.0.so:devel/libsoup3 \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41

USES=		cmake compiler:c11 gnome gstreamer pkgconfig vala:build xorg
USE_GNOME=	cairo gdkpixbuf gtk30
USE_XORG=	x11

USE_GITHUB=	yes

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/pdfpcrc \
		${STAGEDIR}${PREFIX}/etc/pdfpcrc.sample

.include <bsd.port.mk>
