# New ports collection makefile for: apvlv
# Date created:                03 May 2010
# Whom:                        Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	apvlv
PORTVERSION=	0.1.4
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/naihe2010/apvlv/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	xors@mailup.net
COMMENT=	PDF/DJVU Viewer that behaves like Vim

LICENSE=	GPLv2

LIB_DEPENDS=	poppler-glib.8:${PORTSDIR}/graphics/poppler-glib

USE_GNOME=	gtk20
USES=		cmake
CMAKE_ARGS+=	-DSYSCONFDIR=${PREFIX}/etc \
		-DMANDIR=${MANPREFIX}/man \
		-DDOCDIR=${DOCSDIR} \
		-DAPVLV_WITH_UMD=OFF \
		-DAPVLV_WITH_TXT=ON

MAN1=		apvlv.1

OPTIONS_DEFINE=	DJVU WEBKIT

DJVU_DESC=	Build with DjVu support
WEBKIT_DESC=	Build with WebKit support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDJVU}
CMAKE_ARGS+=	-DAPVLV_WITH_DJVU=ON
LIB_DEPENDS+=	djvulibre:${PORTSDIR}/graphics/djvulibre
.else
CMAKE_ARGS+=	-DAPVLV_WITH_DJVU=OFF
.endif

.if ${PORT_OPTIONS:MWEBKIT}
CMAKE_ARGS+=	-DAPVLV_WITH_HTML=ON
LIB_DEPENDS+=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2
.else
CMAKE_ARGS+=	-DAPVLV_WITH_HTML=OFF
.endif

.include <bsd.port.mk>
