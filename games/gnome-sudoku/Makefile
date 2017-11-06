# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	gnome-sudoku
PORTVERSION=	3.24.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

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

USES=		gettext gmake gnome localbase pathfix \
		pkgconfig python:3.3+ shebangfix tar:xz
USE_GNOME=	cairo gtk30 intlhack libxml2:build py3gobject3
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.sudoku.gschema.xml

.include <bsd.port.mk>
