# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/accessibility/mousetweaks/Makefile 19291 2014-03-24 20:41:35Z gusi $

PORTNAME=	mousetweaks
PORTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	accessibility
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mouse accessibility enhancements for the GNOME desktop

BUILD_DEPENDS=	gsettings-desktop-schemas>=0.1.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0.1.0:devel/gsettings-desktop-schemas

USE_XORG=	x11 xfixes xcursor xtst
USE_GNOME=	gnomeprefix gtk30 intlhack
USES=		gettext gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.mousetweaks.enums.xml \
		org.gnome.mousetweaks.gschema.xml

.include <bsd.port.mk>
