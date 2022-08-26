PORTNAME=	iagno
PORTVERSION=	3.38.1
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

# Incomplete upstream vala fixes
#PATCH_SITES=	https://gitlab.gnome.org/GNOME/iagno/-/commit/
#PATCHFILES=	e8a0aeec350ea80349582142c0e8e3cd3f1bce38.diff:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Iagno

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstream-util:devel/appstream-glib

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase meson \
		pathfix pkgconfig tar:xz vala:build xorg
USE_GNOME=	cairo gsound gtk30 intlhack librsvg2 libxml2:build
USE_XORG=	x11

GLIB_SCHEMAS=	org.gnome.Reversi.gschema.xml

BROKEN=		Does not build against current vala

.include <bsd.port.mk>
