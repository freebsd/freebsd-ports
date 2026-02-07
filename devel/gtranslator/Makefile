PORTNAME=	gtranslator
DISTVERSION=	47.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for creating GNU gettext translation files
WWW=		https://gitlab.gnome.org/GNOME/gtranslator

LICENSE=	GPLv3+

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libjson-glib-1.0.so:devel/json-glib \
		libgettextpo.so:devel/gettext-tools \
		libspelling-1.so:x11-toolkits/libspelling
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		cpe desktop-file-utils gettext gnome localbase:ldflags \
		meson pkgconfig tar:xz
CPE_VENDOR=	gtranslate
CPE_PRODUCT=	google_language_translator
USE_GNOME=	cairo glib20 gtk40 gtksourceview5 libadwaita libgda6 libxml2
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.Gtranslator.gschema.xml \
		org.gnome.gtranslator.plugins.translation-memory.gschema.xml

.include <bsd.port.mk>
