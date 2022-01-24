# Created by: Maxim Sobolev <sobomax@FreeBSD.org>

PORTNAME=	gtranslator
PORTVERSION=	40.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	7ac572cc8c8c.patch:-p1 # https://gitlab.gnome.org/GNOME/gtranslator/-/merge_requests/90

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for creating GNU gettext translation files

LICENSE=	GPLv3

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool
LIB_DEPENDS=	libdazzle-1.0.so:x11-toolkits/libdazzle \
		libgdl-3.so:x11-toolkits/gdl \
		libgspell-1.so:textproc/gspell \
		libhandy-1.so:x11-toolkits/libhandy \
		libjson-glib-1.0.so:devel/json-glib \
		libpeas-1.0.so:devel/libpeas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		iso-codes>=0:misc/iso-codes

USE_GNOME=	gtk30 gtksourceview4 libgda5 libxml2 introspection:build
USES=		cpe desktop-file-utils gettext gnome localbase:ldflags meson \
		pkgconfig python tar:xz
CPE_VENDOR=	gtranslate
CPE_PRODUCT=	google_language_translator
USE_PYTHON=	py3kplist
USE_LDCONFIG=	yes
MESON_ARGS=	-Dgtk_doc=false
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Gtranslator.gschema.xml \
		org.gnome.gtranslator.plugins.translation-memory.gschema.xml

.include <bsd.port.mk>
