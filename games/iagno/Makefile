PORTNAME=	iagno
PORTVERSION=	3.38.1
PORTREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

# Incomplete upstream vala fixes
#PATCH_SITES=	https://gitlab.gnome.org/GNOME/iagno/-/commit/
#PATCHFILES=	e8a0aeec350ea80349582142c0e8e3cd3f1bce38.diff:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Iagno
WWW=		https://wiki.gnome.org/Iagno

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	BROKEN for more than a year and no upstream activity for the last 2 years
EXPIRATION_DATE=	2023-11-30
BROKEN=		Does not build against current vala

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstream-util:devel/appstream-glib

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

USES=		gettext gmake gnome localbase meson \
		pathfix pkgconfig tar:xz vala:build xorg
USE_GNOME=	cairo gsound gtk30 intlhack librsvg2 libxml2:build
GLIB_SCHEMAS=	org.gnome.Reversi.gschema.xml
USE_XORG=	x11

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
