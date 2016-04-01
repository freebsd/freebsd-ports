# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-tetravex
PORTVERSION=	3.18.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome tetravex

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 intlhack librsvg2 libxml2:build
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.tetravex.gschema.xml

.include <bsd.port.mk>
