PORTNAME=	tuner
DISTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Minimalist radio station player
WWW=		https://github.com/louis77/tuner

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgranite.so:x11-toolkits/granite \
		libsoup-2.4.so:devel/libsoup \
		libgeoclue-2.so:net/geoclue \
		libgeocode-glib.so:net/geocode-glib \
		libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee

USES=		desktop-file-utils gettext-tools gnome gstreamer \
		meson ninja pkgconfig vala:build
USE_GITHUB=	yes
USE_GSTREAMER=	bad libav
GH_ACCOUNT=	louis77
APPNAME=	com.github.louis77.tuner
PLIST_SUB=	APPNAME=${APPNAME}

USE_GNOME=	gdkpixbuf2 glib20 gtk30 intlhack
GLIB_SCHEMAS=	${APPNAME}.gschema.xml

.include <bsd.port.mk>
