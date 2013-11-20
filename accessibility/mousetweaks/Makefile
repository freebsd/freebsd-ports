# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/mousetweaks3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	mousetweaks
PORTVERSION=	3.6.0
CATEGORIES=	accessibility
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mouse accessibility enhancements for the GNOME desktop

BUILD_DEPENDS=	gsettings-desktop-schemas>=0.1.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0.1.0:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XZ=		yes
USE_XORG=	x11 xfixes xcursor xtst
USE_GNOME=	gnomeprefix intlhack gtk30
USES=		gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.mousetweaks.enums.xml \
		org.gnome.mousetweaks.gschema.xml

.include <bsd.port.mk>
