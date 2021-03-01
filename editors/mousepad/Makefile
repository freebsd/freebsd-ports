# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mousepad
PORTVERSION=	0.5.3
CATEGORIES=	editors xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple text editor for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils gettext-tools gmake gnome libtool perl5 \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo dconf gdkpixbuf2 glib20 gtk30 gtksourceview3 intlhack \
		intltool
USE_XFCE=	xfconf

GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.xfce.mousepad.gschema.xml

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
