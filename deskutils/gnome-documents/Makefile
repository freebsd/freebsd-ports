# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-documents
PORTVERSION=	3.28.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Document manager application designed to work with GNOME 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libevview3.so:graphics/evince \
		libgdata.so:devel/libgdata \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgjs.so:lang/gjs \
		libtracker-sparql-2.0.so:sysutils/tracker \
		libgepub-0.6.so:textproc/libgepub \
		libzapojit-0.0.so:net/libzapojit
RUN_DEPENDS=	gnome-online-miners>=0:net/gnome-online-miners \
		tracker-miners>=0:sysutils/tracker-miners

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib desktop-file-utils gettext gnome localbase \
		meson pkgconfig python:3.6+,build tar:xz
USE_GNOME=	cairo gnomedesktop3 introspection libxslt:build
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Documents.enums.xml \
		org.gnome.books.gschema.xml \
		org.gnome.documents.gschema.xml

.include <bsd.port.mk>
