# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtranslator
PORTVERSION=	3.38.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for creating GNU gettext translation files

LICENSE=	GPLv3

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libgdl-3.so:x11-toolkits/gdl \
		libjson-glib-1.0.so:devel/json-glib \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libgspell-1.so:textproc/gspell
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USE_GNOME=	gtk30 libgda5 gtksourceview4 libxml2 \
		introspection:build
USES=		desktop-file-utils gettext localbase:ldflags gnome meson \
		pkgconfig python tar:xz
USE_PYTHON=	py3kplist
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MESON_ARGS=	-Dgtk_doc=false
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Gtranslator.gschema.xml \
		org.gnome.gtranslator.plugins.translation-memory.gschema.xml

.include <bsd.port.mk>
