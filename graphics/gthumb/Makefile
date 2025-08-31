PORTNAME=	gthumb
PORTVERSION=	3.12.7
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Image viewer and browser for the GNOME environment
WWW=		https://gitlab.gnome.org/GNOME/gthumb

LICENSE=	GPLv2+

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool \
		appstreamcli:devel/appstream
LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libgstreamer-1.0.so:multimedia/gstreamer1 \
		libjson-glib-1.0.so:devel/json-glib \
		liblcms2.so:graphics/lcms2 \
		liboauth.so:net/liboauth \
		libpng.so:graphics/png \
		libsoup-2.4.so:devel/libsoup \
		libtiff.so:graphics/tiff \
		libcolord.so:graphics/colord
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		bison compiler:c++11-lib cpe desktop-file-utils gettext gl \
		gnome jpeg localbase:ldflags meson pkgconfig \
		python:build shebangfix tar:xz xorg
USE_GL=		egl
USE_GNOME=	cairo gtk30 intltool librsvg2
USE_XORG=	x11 xcomposite xdamage xext xfixes xrandr xi
MESON_ARGS=	-Dlibrsvg=true \
		-Dlibchamplain=false
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_CMD}
SHEBANG_FILES=	*.py data/gschemas/*.py gthumb/*.py po/*.py

PLIST_SUB=	GTHUMB_VER="3.10"

GLIB_SCHEMAS=	org.gnome.gthumb.change-date.gschema.xml \
		org.gnome.gthumb.comments.gschema.xml \
		org.gnome.gthumb.contact-sheet.gschema.xml \
		org.gnome.gthumb.convert-format.gschema.xml \
		org.gnome.gthumb.crop.gschema.xml \
		org.gnome.gthumb.enums.xml \
		org.gnome.gthumb.facebook.gschema.xml \
		org.gnome.gthumb.file-manager.gschema.xml \
		org.gnome.gthumb.flickr.gschema.xml \
		org.gnome.gthumb.gschema.xml \
		org.gnome.gthumb.gstreamer-tools.gschema.xml \
		org.gnome.gthumb.image-print.gschema.xml \
		org.gnome.gthumb.image-viewer.gschema.xml \
		org.gnome.gthumb.importer.gschema.xml \
		org.gnome.gthumb.photo-importer.gschema.xml \
		org.gnome.gthumb.picasaweb.gschema.xml \
		org.gnome.gthumb.pixbuf-savers.gschema.xml \
		org.gnome.gthumb.rename-series.gschema.xml \
		org.gnome.gthumb.resize-images.gschema.xml \
		org.gnome.gthumb.resize.gschema.xml \
		org.gnome.gthumb.rotate.gschema.xml \
		org.gnome.gthumb.slideshow.gschema.xml \
		org.gnome.gthumb.webalbums.gschema.xml \
		org.gnome.gthumb.catalogs.gschema.xml \
		org.gnome.gthumb.terminal.gschema.xml

OPTIONS_DEFINE=		BRASERO CLUTTER EXIV2 GSTREAMER HEIF JXL RAW SECRET \
			WEBP WEBSERVICES YELP
OPTIONS_DEFAULT=	BRASERO CLUTTER EXIV2 GSTREAMER HEIF JXL RAW SECRET \
			WEBP WEBSERVICES YELP
OPTIONS_SUB=		yes

BRASERO_DESC=		Write galleries to CD/DVD (large dependency)
BRASERO_LIB_DEPENDS=	libbrasero-media3.so:sysutils/brasero
BRASERO_MESON_TRUE=	libbrasero
CLUTTER_DESC=		Fancy slideshows
CLUTTER_LIB_DEPENDS=	libclutter-gtk-1.0.so:graphics/clutter-gtk3
CLUTTER_MESON_TRUE=	clutter
EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_MESON_TRUE=	exiv2
GSTREAMER_USES=		gstreamer
GSTREAMER_MESON_TRUE=	gstreamer
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_MESON_TRUE=	libheif
JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_MESON_TRUE=		libjxl
RAW_DESC=		Raw image support via libraw
RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_MESON_TRUE=		libraw
SECRET_DESC=		Libsecret support for storing passwords
SECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
SECRET_MESON_TRUE=	libsecret
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MESON_TRUE=	libwebp
WEBSERVICES_DESC=	Web services
WEBSERVICES_LIB_DEPENDS=\
			libjson-glib-1.0.so:devel/json-glib \
			libwebkit2gtk-4.0.so:www/webkit2-gtk@40
WEBSERVICES_MESON_TRUE=	webservices
YELP_DESC=		Viewer for built-in help system
YELP_RUN_DEPENDS=	yelp:x11/yelp

.include <bsd.port.mk>
