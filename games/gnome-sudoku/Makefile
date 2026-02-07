PORTNAME=	gnome-sudoku
PORTVERSION=	47.3
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sudoku game for GNOME
WWW=		https://gitlab.gnome.org/GNOME/gnome-sudoku

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libqqwing.so:games/qqwing \
		libjson-glib-1.0.so:devel/json-glib \
		libgraphene-1.0.so:graphics/graphene
RUN_DEPENDS=	dbus>0:devel/dbus

USES=		compiler:c++11-lang desktop-file-utils gettext gnome meson \
		pkgconfig tar:xz vala:build
USE_GNOME=	cairo glib20 gtk40 libadwaita

PORTSCOUT=	limit:^47\.

GLIB_SCHEMAS=	org.gnome.Sudoku.gschema.xml

.include <bsd.port.mk>
