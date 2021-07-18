# Created by: FreeBSD GNOME Team <gnome@freebsd.org>

PORTNAME=	gnome-sudoku
PORTVERSION=	40.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sudoku game for gnome

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstream-util:devel/appstream-glib \
		vala:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libqqwing.so:games/qqwing \
		libjson-glib-1.0.so:devel/json-glib

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang gettext gmake gnome meson \
		python:3.7+ pkgconfig tar:xz
USE_GNOME=	cairo gtk30
INSTALLS_ICONS=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

GLIB_SCHEMAS=	org.gnome.Sudoku.gschema.xml

.include <bsd.port.mk>
