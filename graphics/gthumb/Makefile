PORTNAME=	gthumb
PORTVERSION=	3.12.8
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
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libcolord.so:graphics/colord \
		libexiv2.so:graphics/exiv2
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		bison compiler:c++11-lib cpe desktop-file-utils gettext \
		gnome jpeg localbase:ldflags meson pkgconfig \
		python:build shebangfix tar:xz xorg
USE_GNOME=	cairo glib20 gtk30 librsvg2
USE_XORG=	x11
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_CMD}
SHEBANG_FILES=	*.py data/gschemas/*.py gthumb/*.py po/*.py

GLIB_SCHEMAS=	org.gnome.gthumb.change-date.gschema.xml \
		org.gnome.gthumb.comments.gschema.xml \
		org.gnome.gthumb.contact-sheet.gschema.xml \
		org.gnome.gthumb.convert-format.gschema.xml \
		org.gnome.gthumb.crop.gschema.xml \
		org.gnome.gthumb.enums.xml \
		org.gnome.gthumb.file-manager.gschema.xml \
		org.gnome.gthumb.gschema.xml \
		org.gnome.gthumb.gstreamer-tools.gschema.xml \
		org.gnome.gthumb.image-print.gschema.xml \
		org.gnome.gthumb.image-viewer.gschema.xml \
		org.gnome.gthumb.importer.gschema.xml \
		org.gnome.gthumb.photo-importer.gschema.xml \
		org.gnome.gthumb.pixbuf-savers.gschema.xml \
		org.gnome.gthumb.rename-series.gschema.xml \
		org.gnome.gthumb.resize-images.gschema.xml \
		org.gnome.gthumb.resize.gschema.xml \
		org.gnome.gthumb.rotate.gschema.xml \
		org.gnome.gthumb.slideshow.gschema.xml \
		org.gnome.gthumb.webalbums.gschema.xml \
		org.gnome.gthumb.catalogs.gschema.xml \
		org.gnome.gthumb.terminal.gschema.xml

OPTIONS_DEFINE=		BRASERO CLUTTER GSTREAMER HEIF JXL RAW WEBP YELP
OPTIONS_DEFAULT=	CLUTTER GSTREAMER HEIF JXL RAW WEBP YELP
OPTIONS_SUB=		yes

BRASERO_DESC=		Write galleries to CD/DVD (large dependency)
BRASERO_LIB_DEPENDS=	libbrasero-media3.so:sysutils/brasero
BRASERO_MESON_TRUE=	libbrasero
CLUTTER_DESC=		Fancy slideshows
CLUTTER_LIB_DEPENDS=	libcogl.so:graphics/cogl \
			libclutter-1.0.so:graphics/clutter \
			libclutter-gtk-1.0.so:graphics/clutter-gtk3
CLUTTER_MESON_TRUE=	clutter
GSTREAMER_USES=		gstreamer
GSTREAMER_MESON_TRUE=	gstreamer
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_MESON_TRUE=	libheif
JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_MESON_TRUE=		libjxl
RAW_DESC=		Raw image support via libraw
RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_MESON_TRUE=		libraw
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MESON_TRUE=	libwebp
YELP_DESC=		Viewer for built-in help system
YELP_RUN_DEPENDS=	yelp:x11/yelp

.include <bsd.port.mk>
