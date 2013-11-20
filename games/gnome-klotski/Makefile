# $FreeBSD$
#   $MCom: ports/trunk/games/gnome-klotski/Makefile 18839 2013-10-30 23:48:38Z kwm $

PORTNAME=	gnome-klotski
PORTVERSION=	3.10.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome klotski

BUILD_DEPENDS=	vala:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_ICONS=	yes
USE_GNOME=	gtk30 intlhack librsvg2 libxml2:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.klotski.gschema.xml

.include <bsd.port.mk>
