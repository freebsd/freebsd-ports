# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mousepad
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	editors xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple text editor for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils gettext-tools gmake gnome libtool perl5 \
		pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 glib20 intlhack intltool
USE_XFCE=	xfconf

GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.xfce.mousepad.gschema.xml

OPTIONS_DEFINE=		GTK3 NLS
OPTIONS_DEFAULT=	GTK3
OPTIONS_SUB=		yes

GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE=		gnome=gtk30,gtksourceview3,dconf
GTK3_USE_OFF=		gnome=gtk20,gtksourceview2
GTK3_USES=		xfce
GTK3_USES_OFF=		xfce:gtk2
GTK3_CFLAGS_OFF=	-I${LOCALBASE}/include/gio-unix-2.0

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
