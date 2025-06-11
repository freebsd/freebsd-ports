PORTNAME=	swell-foop
PORTVERSION=	48.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME swell-foop
WWW=		https://gitlab.gnome.org/GNOME/swell-foop

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgnome-games-support-2.so:games/libgnome-games-support2
RUN_DEPENDS=	dbus>0:devel/dbus

USES=		gettext gnome localbase meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 gtk40 librsvg2 pango libadwaita
GLIB_SCHEMAS=	org.gnome.SwellFoop.gschema.xml

.include <bsd.port.mk>
