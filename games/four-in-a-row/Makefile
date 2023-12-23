PORTNAME=	four-in-a-row
PORTVERSION=	3.38.1
PORTREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Make lines of the same color
WWW=		https://wiki.gnome.org/Apps/Four-in-a-row

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstream-util:devel/appstream-glib
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase meson pathfix pkgconfig tar:xz vala:build xorg
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build gsound
USE_XORG=	x11

GLIB_SCHEMAS=	org.gnome.Four-in-a-row.gschema.xml

.include <bsd.port.mk>
