# Created by: FreeBSD GNOME Team <gnome@freebsd.org>

PORTNAME=	gnome-mines
PORTVERSION=	40.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome minesweeper

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libgnome-games-support-1.so:games/libgnome-games-support \
		libgee-0.8.so:devel/libgee

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python:3.6+,build tar:xz
USE_GNOME=	gtk30 librsvg2
INSTALLS_ICONS=	yes

BINARY_ALIAS=	python3=${PYTHON_VERSION}
GLIB_SCHEMAS=	org.gnome.Mines.gschema.xml

.include <bsd.port.mk>
