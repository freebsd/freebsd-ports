# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtranslator
PORTVERSION=	2.91.7
PORTREVISION=	2
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
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USE_GNOME=	intlhack gnomeprefix gtk30 libgda5 gtksourceview3 libxml2 \
		introspection:build
USES=		desktop-file-utils gettext gmake gnome libtool pathfix \
		pkgconfig python tar:xz
USE_PYTHON=	py3kplist
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-debug \
		--with-gda=5.0 \
		--without-dictionary \
		--enable-compile-warnings=no
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gtranslator.gschema.xml \
		org.gnome.gtranslator.plugins.codeview.gschema.xml \
		org.gnome.gtranslator.plugins.open-tran.gschema.xml \
		org.gnome.gtranslator.plugins.translation-memory.gschema.xml

.include <bsd.port.mk>
