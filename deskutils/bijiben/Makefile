# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	bijiben
PORTVERSION=	3.18.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Note editor designed to remain simple to use

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libtracker-control-1.0.so:sysutils/tracker \
		libgoa-1.0.so:net/gnome-online-accounts \
		libwebkitgtk-3.0.so:www/webkit-gtk3 \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libtool \
		pathfix pkgconfig shared-mime-info tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	evolutiondataserver3 gnomedesktop3 gtk30 intlhack \
		introspection:build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.bijiben.gschema.xml

# needed for webkit
USES+=		compiler:c++11-lib

.include <bsd.port.mk>
