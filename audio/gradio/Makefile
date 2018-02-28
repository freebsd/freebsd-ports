# Created by: arved
# $FreeBSD$

PORTNAME=	gradio
PORTVERSION=	7.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	arved@FreeBSD.org
COMMENT=	GTK3 app for finding and listening to internet radio stations

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext meson pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	haecker-felix
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_GSTREAMER1=	mpg123 soup
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	de.haeckerfelix.gradio.gschema.xml

.include <bsd.port.mk>
