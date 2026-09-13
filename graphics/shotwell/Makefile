PORTNAME=	shotwell
DISTVERSION=	33.0
CATEGORIES=	graphics gnome
# having full DISTVERSION in the path does not play with MASTER_SITE_GNOME
MASTER_SITES=	https://download.gnome.org/sources/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Open source photo manager for GNOME
WWW=		https://wiki.gnome.org/Apps/Shotwell

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libportal.so:deskutils/libportal \
		libportal-gtk4.so:deskutils/libportal-gtk4 \
		libgio-2.0.so:devel/glib20 \
		libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee \
		libsoup-3.0.so:devel/libsoup3 \
		libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2 \
		libgexiv2-0.16.so:graphics/gexiv2_016 \
		libexif.so:graphics/libexif \
		libgphoto2.so:graphics/libgphoto2 \
		libraw.so:graphics/libraw \
		libwebp.so:graphics/webp \
		libgcr-4.so:security/gcr \
		libsecret-1.so:security/libsecret

USES=		compiler:c++11-lib cpe desktop-file-utils gettext \
		gnome gstreamer meson ninja pkgconfig python:build sqlite \
		tar:xz vala:build xorg
CPE_VENDOR=	gnome
USE_GNOME=	cairo gtk40 libxml2
USE_LDCONFIG=	yes
USE_XORG=	x11

MESON_ARGS=	-Dudev=disabled \
		-Dinstall_apport_hook=false \
		-Dpublishers=flickr,gallery3,googlephotos,piwigo,tumblr,youtube

OPTIONS_DEFINE=	FACED
OPTIONS_SUB=	yes

FACED_DESC=	Face Detection

FACED_MESON_ON=	-Dface_detection=true
FACED_MESON_OFF=	-Dface_detection=false -Dface_detection_helper=true
FACED_LIB_DEPENDS=	libopencv_core.so:graphics/opencv

PLIST_SUB=	DISTVERSION=${DISTVERSION}

GLIB_SCHEMAS=	org.yorba.shotwell.gschema.xml org.yorba.shotwell-extras.gschema.xml

.include <bsd.port.mk>
