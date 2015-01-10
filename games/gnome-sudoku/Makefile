# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom: ports/trunk/games/gnome-sudoku/Makefile 20056 2014-11-10 20:49:39Z gusi $

PORTNAME=	gnome-sudoku
PORTVERSION=	3.14.2
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sudoku game for gnome

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libqqwing.so:${PORTSDIR}/games/qqwing \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib 	

USES=		gettext gmake pathfix pkgconfig python:3 shebangfix tar:xz
USE_GNOME=	gtk30 intlhack libxml2:build py3gobject3
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.sudoku.gschema.xml

.include <bsd.port.mk>
