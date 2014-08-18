# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom: ports/trunk/games/gnome-sudoku/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	gnome-sudoku
PORTVERSION=	3.12.3
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sudoku game for gnome

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USES=		gettext gmake pathfix pkgconfig python:3 shebangfix tar:xz
USE_GNOME=	gtk30 intlhack libxml2:build py3gobject3
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	src/gnome-sudoku

GLIB_SCHEMAS=	org.gnome.gnome-sudoku.gschema.xml

.include <bsd.port.mk>
