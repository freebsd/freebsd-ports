# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mousepad
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	editors xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple text editor for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USES=	desktop-file-utils gettext gmake libtool pkgconfig perl5 tar:bzip2
USE_GNOME=	glib20 intltool intlhack

OPTIONS_DEFINE=	GTK3
GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE=	gnome=gtk30,gtksourceview3
GTK3_USES=	xfce:gtk3
GTK3_USE_OFF=	gnome=gtk20,gtksourceview2
GTK3_USES_OFF=	xfce

GLIB_SCHEMAS=	org.xfce.mousepad.gschema.xml

.include <bsd.port.mk>
