# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom: ports/trunk/games/gnome-chess/Makefile 20056 2014-11-10 20:49:39Z gusi $

PORTNAME=	gnome-chess
PORTVERSION=	3.14.2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome chess

BUILD_DEPENDS=	vala:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool

USES=		desktop-file-utils gettext gmake pkgconfig tar:xz
USE_GNOME=	gtk30 intlhack librsvg2 libxml2:build
INSTALLS_ICONS=	yes
USE_XORG=	x11
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.chess.gschema.xml

OPTIONS_DEFINE=	GNUCHESS
OPTIONS_DEFAULT=GNUCHESS
GNUCHESS_DESC=	Use gnuchess engine for computer player
GNUCHESS_RUN_DEPENDS=	gnuchess:${PORTSDIR}/games/gnuchess

.include <bsd.port.mk>
