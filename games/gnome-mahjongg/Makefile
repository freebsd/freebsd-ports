# Created by: FreeBSD GNOME Team <gnome@freebsd.org>

PORTNAME=	gnome-mahjongg
DISTVERSION=	3.38.3
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome mahjongg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase meson pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build

GLIB_SCHEMAS=	org.gnome.Mahjongg.gschema.xml

.include <bsd.port.mk>
