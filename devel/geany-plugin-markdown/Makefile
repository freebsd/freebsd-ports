# $FreeBSD$

PORTNAME=	geany-plugin-markdown
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

gtk2_LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2
gtk3_LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
