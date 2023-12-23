PORTNAME=	gnome-mines
PORTVERSION=	40.1
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome minesweeper
WWW=		https://wiki.gnome.org/Apps/Mines

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgnome-games-support-1.so:games/libgnome-games-support \
		libgee-0.8.so:devel/libgee

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python:build tar:xz vala:build
USE_GNOME=	gtk30 librsvg2

BINARY_ALIAS=	python3=${PYTHON_VERSION}
GLIB_SCHEMAS=	org.gnome.Mines.gschema.xml

.include <bsd.port.mk>
