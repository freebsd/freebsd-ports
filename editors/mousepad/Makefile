# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mousepad
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	editors xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple text editor for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus

USES=		desktop-file-utils gettext-tools gmake gnome libtool perl5 \
		pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 glib20 intlhack intltool

GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.xfce.mousepad.gschema.xml

OPTIONS_DEFINE=		GTK3 NLS
OPTIONS_DEFAULT=	GTK3
OPTIONS_SUB=		yes

GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE=		gnome=gtk30,gtksourceview3,dconf
GTK3_USE_OFF=		gnome=gtk20,gtksourceview2

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
