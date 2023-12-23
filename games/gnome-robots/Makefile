PORTNAME=	gnome-robots
PORTVERSION=	40.0
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome robots
WWW=		https://wiki.gnome.org/Apps/Robots

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		itstool:textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libgee-0.8.so:devel/libgee \
		libgnome-games-support-1.so:games/libgnome-games-support

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase meson pathfix pkgconfig tar:xz \
		vala:build xorg
USE_GNOME=	cairo gsound gtk30 intlhack librsvg2 libxml2:build
USE_XORG=	x11

GLIB_SCHEMAS=	org.gnome.Robots.gschema.xml

.include <bsd.port.mk>
