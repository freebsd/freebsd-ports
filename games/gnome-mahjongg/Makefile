PORTNAME=	gnome-mahjongg
DISTVERSION=	47.2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Mahjongg
WWW=		https://gitlab.gnome.org/GNOME/gnome-mahjongg

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	itstool:textproc/itstool
RUN_DEPENDS=	dbus>0:devel/dbus

USES=		desktop-file-utils gettext gmake gnome localbase meson \
		pkgconfig tar:xz vala:build
USE_GNOME=	cairo glib20 gtk40 libadwaita librsvg2
GLIB_SCHEMAS=	org.gnome.Mahjongg.gschema.xml

.include <bsd.port.mk>
