# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	apvlv
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/naihe2010/apvlv/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	xors@mailup.net
COMMENT=	PDF/DJVU Viewer that behaves like Vim

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib

USE_GNOME=	gtk20
USES=		cmake pkgconfig
CMAKE_ARGS+=	-DSYSCONFDIR=${PREFIX}/etc \
		-DMANDIR=${MANPREFIX}/man \
		-DDOCDIR=${DOCSDIR} \
		-DAPVLV_WITH_UMD=OFF \
		-DAPVLV_WITH_TXT=ON
CFLAGS+=	-pthread
LDFLAGS+=	-pthread

OPTIONS_DEFINE=	DJVU WEBKIT

DJVU_DESC=	DjVu document support

DJVU_CMAKE_ON=	-DAPVLV_WITH_DJVU=ON
DJVU_CMAKE_OFF=	-DAPVLV_WITH_DJVU=OFF
DJVU_LIB_DEPENDS=	libdjvulibre.so:${PORTSDIR}/graphics/djvulibre

WEBKIT_CMAKE_ON=	-DAPVLV_WITH_HTML=ON
WEBKIT_CMAKE_OFF=	-DAPVLV_WITH_HTML=OFF
WEBKIT_LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2

.include <bsd.port.mk>
