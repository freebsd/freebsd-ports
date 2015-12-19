# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-documents
PORTVERSION=	3.16.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Document manager application designed to work with GNOME 3

LICENSE=	GPLv2

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libwebkit2gtk-4.0.so:${PORTSDIR}/www/webkit2-gtk3 \
		libclutter-1.0.so:${PORTSDIR}/graphics/clutter \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libevview3.so:${PORTSDIR}/graphics/evince \
		libgdata.so:${PORTSDIR}/devel/libgdata \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgjs.so:${PORTSDIR}/lang/gjs \
		libtracker-sparql-1.0.so:${PORTSDIR}/sysutils/tracker \
		libzapojit-0.0.so:${PORTSDIR}/net/libzapojit
RUN_DEPENDS=	py2?-dbus>0:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		unoconv:${PORTSDIR}/textproc/unoconv

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake libtool pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gtk30 intltool \
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
