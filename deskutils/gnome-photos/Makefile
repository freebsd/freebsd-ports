# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-photos
PORTVERSION=	3.18.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photo application for GNOME 3

BUILD_DEPENDS=	geoclue>=0:net/geoclue \
		itstool:textproc/itstool
LIB_DEPENDS=	libexempi.so:textproc/exempi \
		libgfbgraph-0.2.so:net/gfbgraph \
		libgegl-0.3.so:graphics/gegl3 \
		libgrilo-0.2.so:net/grilo \
		libexif.so:graphics/libexif \
		libtracker-control-1.0.so:sysutils/tracker \
		libgjs.so:lang/gjs \
		libbabl-0.1.so:x11/babl \
		libgdata.so:devel/libgdata
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gmake gnome libtool \
		pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
CFLAGS=		-I${LOCALBASE}/include -Wno-error=format-nonliteral
LIBS+=		-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.photos.gschema.xml

.include <bsd.port.mk>
