PORTNAME=	gnome-nibbles
PORTVERSION=	4.4.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Guide a worm around a maze
WWW=		https://gitlab.gnome.org/GNOME/gnome-nibbles

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstreamcli:devel/appstream
LIB_DEPENDS=	libgee-0.8.so:devel/libgee
RUN_DEPENDS=	dbus>0:devel/dbus

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig tar:xz \
		vala:build
USE_GNOME=	gsound glib20 gtk40 libadwaita pango

GLIB_SCHEMAS=	org.gnome.Nibbles.gschema.xml

.include <bsd.port.mk>
