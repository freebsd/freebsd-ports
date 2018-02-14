# Created by: arved
# $FreeBSD$

PORTNAME=	gradio
PORTVERSION=	7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	arved@FreeBSD.org
COMMENT=	GTK3 app for finding and listening to internet radio stations

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libsqlite3.so:databases/sqlite3

USES=		meson ninja gettext
USE_GITHUB=	yes
GH_ACCOUNT=	haecker-felix
USE_GNOME=	glib20 gtk30 gdkpixbuf2 cairo
USE_GSTREAMER1=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
