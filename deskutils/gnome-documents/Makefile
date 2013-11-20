# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/deskutils/gnome-documents/Makefile 18905 2013-11-19 10:31:31Z gusi $

PORTNAME=	gnome-documents
PORTVERSION=	3.6.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Document manager application designed to work with GNOME 3

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libclutter-1.0.so:${PORTSDIR}/graphics/clutter \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libevview3.so:${PORTSDIR}/graphics/evince \
		libgdata.so.13:${PORTSDIR}/devel/libgdata \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgjs.so:${PORTSDIR}/lang/gjs \
		libtracker-sparql-0.14.so:${PORTSDIR}/sysutils/tracker \
		libzapojit-0.0.so:${PORTSDIR}/net/libzapojit
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

GLIB_SCHEMAS=	org.gnome.Documents.enums.xml \
		org.gnome.documents.gschema.xml

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack libxml2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnome-documents/*.so

.include <bsd.port.mk>
