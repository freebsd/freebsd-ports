# New ports collection makefile for:	gok
# Date created:			12 April 2003
# Whom:				Adam Weinberger <adamw@freebsd.org>
#
# $FreeBSD$
#    $MCom: ports/accessibility/gok/Makefile,v 1.110 2010/04/02 16:53:04 kwm Exp $
#

PORTNAME=	gok
PORTVERSION=	2.30.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	accessibility sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME On-Screen Keyboard (GOK)

LIB_DEPENDS=	canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
    		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui atspi libwnck \
		gnomespeech libxml2
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gok.schemas

.include <bsd.port.mk>
