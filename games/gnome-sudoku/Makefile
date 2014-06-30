# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom: ports/trunk/games/gnome-sudoku/Makefile 19760 2014-06-30 06:50:36Z gusi $

PORTNAME=	gnome-sudoku
PORTVERSION=	3.12.3
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sudoku game for gnome

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USES=		gettext gmake pathfix pkgconfig shebangfix tar:xz
USE_GNOME=	gtk30 intlhack libxml2:build py3gobject3
USE_PYTHON=	3
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	src/gnome-sudoku

GLIB_SCHEMAS=	org.gnome.gnome-sudoku.gschema.xml

.include <bsd.port.mk>
