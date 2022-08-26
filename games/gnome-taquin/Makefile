PORTNAME=	gnome-taquin
PORTVERSION=	3.38.1
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

# Incomplete upstream vala fix
# PATCH_SITES=	https://gitlab.gnome.org/GNOME/gnome-taquin/-/commit/
# PATCHFILES=	66be44dc20d114e449fc33156e3939fd05dfbb16.diff:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Move tiles so that they reach their places

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase meson pathfix pkgconfig tar:xz vala:build xorg
USE_GNOME=	cairo gsound gtk30 intlhack librsvg2 libxml2:build
USE_XORG=	x11

GLIB_SCHEMAS=	org.gnome.Taquin.gschema.xml

BROKEN=		Does not build with current vala

.include <bsd.port.mk>
