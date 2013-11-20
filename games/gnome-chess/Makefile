# $FreeBSD$
#   $MCom: ports/trunk/games/gnome-chess/Makefile 18839 2013-10-30 23:48:38Z kwm $

PORTNAME=	gnome-chess
PORTVERSION=	3.10.1.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome chess

BUILD_DEPENDS=	vala:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool

USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig
INSTALLS_ICONS=	yes
USE_XORG=	x11
USE_GL=		gl glu
USE_GNOME=	gtk30 intlhack librsvg2 libxml2:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-chess.gschema.xml

OPTIONS_DEFINE=	GNUCHESS
OPTIONS_DEFAULT=GNUCHESS
GNUCHESS_DESC=	Use gnuchess engine for computer player

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUCHESS}
RUN_DEPENDS=	gnuchess:${PORTSDIR}/games/gnuchess
.endif

.include <bsd.port.mk>
