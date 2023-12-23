PORTNAME=	gnome-klotski
PORTVERSION=	3.38.2
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome klotski
WWW=		https://wiki.gnome.org/Apps/Klotski

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgnome-games-support-1.so:games/libgnome-games-support \
		libgee-0.8.so:devel/libgee

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase meson pathfix \
		pkgconfig tar:xz vala:build
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build

GLIB_SCHEMAS=	org.gnome.Klotski.gschema.xml

.include <bsd.port.mk>
