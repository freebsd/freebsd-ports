# $FreeBSD$
#   $MCom: ports/trunk/games/gnome-sudoku/Makefile 18839 2013-10-30 23:48:38Z kwm $

PORTNAME=	gnome-sudoku
PORTVERSION=	3.8.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sudoku game for gnome

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
# might work with python3, not tested, so restrict for now
USE_PYTHON=	-2.7
INSTALLS_ICONS=	yes
USE_GNOME=	gtk30 intlhack pygobject3 libxml2:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-sudoku.gschema.xml

.include <bsd.port.mk>
