# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/accessibility/gok/Makefile,v 1.112 2010/09/29 07:37:57 kwm Exp $

PORTNAME=	gok
PORTVERSION=	2.30.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	accessibility sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME On-Screen Keyboard (GOK)

LIB_DEPENDS=	libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra \
    		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USES=		gmake gettext pkgconfig
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui atspi libwnck \
		gnomespeech libxml2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gok.schemas

.include <bsd.port.mk>
