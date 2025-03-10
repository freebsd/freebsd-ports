PORTNAME=	photos
DISTVERSION=	8.0.1
CATEGORIES=	graphics
PKGNAMEPREFIX=	elementary-

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Photo viewer and organizer designed for elementary OS
WWW=		https://github.com/elementary/photos

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libgee-0.8.so:devel/libgee \
		libgeocode-glib-2.so:net/geocode-glib2 \
		libgexiv2.so:graphics/gexiv2 \
		libgphoto2.so:graphics/libgphoto2 \
		libgphoto2_port.so:graphics/libgphoto2 \
		libgranite.so:x11-toolkits/granite \
		libgudev-1.0.so:devel/libgudev \
		libhandy-1.so:x11-toolkits/libhandy \
		libjson-glib-1.0.so:devel/json-glib \
		libraw.so:graphics/libraw \
		libwebp.so:graphics/webp \
		libportal.so:deskutils/libportal \
		libportal-gtk3.so:deskutils/libportal-gtk3

USES=		compiler:c11 desktop-file-utils gettext gnome gstreamer meson \
		pkgconfig sqlite:3 vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libxml2
GLIB_SCHEMAS=	io.elementary.photos.gschema.xml
USE_LDCONFIG=	yes

.include <bsd.port.mk>
