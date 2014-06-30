# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom: ports/trunk/games/gnome-chess/Makefile 19759 2014-06-27 06:24:59Z gusi $

PORTNAME=	gnome-chess
PORTVERSION=	3.12.3
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome chess

BUILD_DEPENDS=	vala:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool

USES=		desktop-file-utils gettext gmake pathfix \
		pkgconfig tar:xz
USE_GNOME=	gtk30 intlhack librsvg2 libxml2:build
INSTALLS_ICONS=	yes
USE_XORG=	x11
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-chess.gschema.xml

OPTIONS_DEFINE=	GNUCHESS
OPTIONS_DEFAULT=GNUCHESS
GNUCHESS_DESC=	Use gnuchess engine for computer player
GNUCHESS_RUN_DEPENDS=	gnuchess:${PORTSDIR}/games/gnuchess

.include <bsd.port.mk>
