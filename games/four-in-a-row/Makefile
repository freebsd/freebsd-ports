# $FreeBSD$
#   $MCom: ports/trunk/games/four-in-a-row/Makefile 18839 2013-10-30 23:48:38Z kwm $

PORTNAME=	four-in-a-row
PORTVERSION=	3.10.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Make lines of the same color

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_ICONS=	yes
USE_GNOME=	gtk30 intlhack librsvg2 libxml2:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lz"

GLIB_SCHEMAS=	org.gnome.four-in-a-row.gschema.xml

.include <bsd.port.mk>
