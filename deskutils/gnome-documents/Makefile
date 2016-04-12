# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-documents
PORTVERSION=	3.18.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Document manager application designed to work with GNOME 3

LICENSE=	GPLv2

BUILD_DEPENDS=	itstool:textproc/itstool \
		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libevview3.so:graphics/evince \
		libgdata.so:devel/libgdata \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgjs.so:lang/gjs \
		libtracker-sparql-1.0.so:sysutils/tracker \
		libzapojit-0.0.so:net/libzapojit
RUN_DEPENDS=	py2?-dbus>0:devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		unoconv:textproc/unoconv

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome libtool pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gtk30 intlhack \
		introspection:build librsvg2 libxml2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Documents.enums.xml \
		org.gnome.books.gschema.xml \
		org.gnome.documents.gschema.xml

.include <bsd.port.mk>
