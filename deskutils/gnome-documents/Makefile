# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/deskutils/gnome-documents/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	gnome-documents
PORTVERSION=	3.12.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Document manager application designed to work with GNOME 3

LICENSE=	GPLv2

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libclutter-1.0.so:${PORTSDIR}/graphics/clutter \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libevview3.so:${PORTSDIR}/graphics/evince \
		libgdata.so:${PORTSDIR}/devel/libgdata \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgjs.so:${PORTSDIR}/lang/gjs \
		libtracker-sparql-1.0.so:${PORTSDIR}/sysutils/tracker \
		libzapojit-0.0.so:${PORTSDIR}/net/libzapojit
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		unoconv:${PORTSDIR}/textproc/unoconv

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack \
		introspection:build libxml2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Documents.enums.xml \
		org.gnome.documents.gschema.xml

.include <bsd.port.mk>
