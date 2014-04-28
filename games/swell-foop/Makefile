# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom: ports/trunk/games/swell-foop/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	swell-foop
PORTVERSION=	3.12.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome swell-foop

BUILD_DEPENDS=	vala:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 intlhack libxml2:build
INSTALLS_ICONS=	yes
USE_GL=		gl
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.swell-foop.gschema.xml

.include <bsd.port.mk>
