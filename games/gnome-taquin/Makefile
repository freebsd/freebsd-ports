PORTNAME=	gnome-taquin
PORTVERSION=	3.38.1
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

# Incomplete upstream vala fix
# PATCH_SITES=	https://gitlab.gnome.org/GNOME/gnome-taquin/-/commit/
# PATCHFILES=	66be44dc20d114e449fc33156e3939fd05dfbb16.diff:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Move tiles so that they reach their places
WWW=		https://wiki.gnome.org/Apps/Taquin/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	BROKEN for more than a year and no upstream activity for more than 2 years
EXPIRATION_DATE=	2023-11-30
BROKEN=		Does not build with current vala

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

USES=		gettext gmake gnome localbase meson pathfix pkgconfig tar:xz vala:build xorg
USE_GNOME=	cairo gsound gtk30 intlhack librsvg2 libxml2:build
GLIB_SCHEMAS=	org.gnome.Taquin.gschema.xml
USE_XORG=	x11

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
