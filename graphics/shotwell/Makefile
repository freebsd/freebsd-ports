PORTNAME=	shotwell
PORTVERSION=	0.30.18
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME

PATCH_SITES=	https://gitlab.gnome.org/GNOME/shotwell/-/commit/
PATCHFILES=	cd82759231e5ece2fa0dea40397c9051d15fd5c2.diff:-p1

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Open source photo manager for GNOME
WWW=		https://wiki.gnome.org/Apps/Shotwell

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libportal.so:deskutils/libportal \
		libportal-gtk3.so:deskutils/libportal-gtk3 \
		libgio-2.0.so:devel/glib20 \
		libjson-glib-1.0.so:devel/json-glib \
		libgdata.so:devel/libgdata \
		libgee-0.8.so:devel/libgee \
		libsoup-2.4.so:devel/libsoup \
		libexiv2.so:graphics/exiv2 \
		libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2 \
		libgexiv2.so:graphics/gexiv2 \
		libexif.so:graphics/libexif \
		libgphoto2.so:graphics/libgphoto2 \
		libraw.so:graphics/libraw \
		libgcr-ui-3.so:security/gcr \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libxml2.so:textproc/libxml2

USES=		compiler:c++11-lib cpe desktop-file-utils gettext gnome gstreamer meson \
		ninja pkgconfig python:build shebangfix sqlite tar:xz vala:build xorg
CPE_VENDOR=	gnome
USE_GNOME=	cairo dconf gtk30
USE_LDCONFIG=	yes
USE_XORG=	x11

SHEBANG_FILES=	build-aux/meson/postinstall.py
python_OLD_CMD=	"/usr/bin/env python3"
python_CMD=	${SETENV} ${PYTHON_VERSION}

MESON_ARGS=	-Dudev=false -Dextra-plugins=true -Dinstall-apport-hook=false \
		-Dpublishers=facebook,flickr,gallery3,picasa,piwigo,rajce,tumblr,yandex,youtube
PORTSCOUT=	limitw:1,even
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	FACED
OPTIONS_SUB=	yes

FACED_DESC=	Face Detection

FACED_CONFIGURE_ON=	-Dface-detection=true
FACED_CONFIGURE_OFF=	-Dface-detection=false
FACED_LIB_DEPENDS=	libopencv_core.so:graphics/opencv \
			libopencv_photo.so:graphics/opencv

PLIST_SUB=	DISTVERSION=${DISTVERSION}

GLIB_SCHEMAS=	org.yorba.shotwell.gschema.xml org.yorba.shotwell-extras.gschema.xml

.include <bsd.port.mk>
