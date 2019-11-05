# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org> et al.
# $FreeBSD$

PORTNAME=	shotwell
PORTVERSION=	0.30.7
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Open source photo manager for GNOME

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala>=0.20.1:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libgio-2.0.so:devel/glib20 \
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
		libgstreamer-1.0.so:multimedia/gstreamer1 \
		libgstapp-1.0.so:multimedia/gstreamer1-plugins \
		libgcr-ui-3.so:security/gcr \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libxml2.so:textproc/libxml2

USES=		gettext desktop-file-utils gnome meson ninja pkgconfig \
		python:3.4+,build shebangfix sqlite tar:xz xorg
USE_GNOME=	cairo dconf gtk30 gnomedocutils
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11

SHEBANG_FILES=	build-aux/meson/postinstall.py
python_OLD_CMD=	"/usr/bin/env python3"
python_CMD=	${SETENV} ${PYTHON_VERSION}

MESON_ARGS=	-Dudev=false -Dextra-plugins=true -Dinstall-apport-hook=false \
		-Dpublishers=facebook,flickr,gallery3,picasa,piwigo,rajce,tumblr,yandex,youtube
INSTALLS_ICONS=	yes
PORTSCOUT=	limitw:1,even
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	FACED OPENMP
OPTIONS_SUB=	yes

FACED_DESC=	Face Detection
OPENMP_DESC=	libraw uses OpenMP (implies GCC)

FACED_CONFIGURE_ON=	-Dface-detection=true
FACED_CONFIGURE_OFF=	-Dface-detection=false
FACED_LIB_DEPENDS=	libopencv_core.so:graphics/opencv-core \
			libopencv_photo.so:graphics/opencv
OPENMP_USES=		compiler:openmp
OPENMP_USES_OFF=	compiler:c++11-lib

PLIST_SUB=	DISTVERSION=${DISTVERSION}

GLIB_SCHEMAS=	org.yorba.shotwell.gschema.xml org.yorba.shotwell-extras.gschema.xml

.include <bsd.port.mk>
