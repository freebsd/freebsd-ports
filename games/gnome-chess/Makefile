# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	gnome-chess
PORTVERSION=	3.18.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome chess

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome pkgconfig tar:xz
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
GNUCHESS_RUN_DEPENDS=	gnuchess:games/gnuchess

.include <bsd.port.mk>
