PORTNAME=	gnome-mines
PORTVERSION=	48.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clear hidden mines from a minefield
WWW=		https://gitlab.gnome.org/GNOME/gnome-mines

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgnome-games-support-2.so:games/libgnome-games-support2

USES=		desktop-file-utils gettext gnome localbase meson pkgconfig \
		tar:xz vala:build
USE_GNOME=	glib20 gtk40 libadwaita

GLIB_SCHEMAS=	org.gnome.Mines.gschema.xml

.include <bsd.port.mk>
