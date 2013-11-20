# $FreeBSD$
#   $MCom: ports/trunk/games/lightsoff/Makefile 18839 2013-10-30 23:48:38Z kwm $

PORTNAME=	lightsoff
PORTVERSION=	3.8.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome ligthsoff

BUILD_DEPENDS=	vala:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_ICONS=	yes
USE_XORG=	x11
USE_GL=		gl
USE_GNOME=	gtk30 intlhack librsvg2 libxml2:build
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.lightsoff.gschema.xml

.include <bsd.port.mk>
