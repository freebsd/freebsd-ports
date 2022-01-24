# Created by: FreeBSD GNOME Team <gnome@freebsd.org>

PORTNAME=	gnome-mahjongg
DISTVERSION=	3.38.3
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	7604f8c8311f.patch:-p1 # https://gitlab.gnome.org/GNOME/gnome-mahjongg/-/merge_requests/26

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome mahjongg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool

USES=		gettext gmake gnome localbase meson pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build
GLIB_SCHEMAS=	org.gnome.Mahjongg.gschema.xml

MESON_ARGS=	-Dcompile-schemas=disabled -Dupdate-icon-cache=disabled

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
