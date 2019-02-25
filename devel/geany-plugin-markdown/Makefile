# $FreeBSD$

PORTNAME=	geany-plugin-markdown
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

FLAVORS=	gtk3

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
