# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ristretto
PORTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=	graphics xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Image viewer with Xfce integration

LIB_DEPENDS=	exif:${PORTSDIR}/graphics/libexif \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		cairo:${PORTSDIR}/graphics/cairo

USES=		pkgconfig gettext pathfix desktop-file-utils
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_XFCE=	configenv libmenu libutil xfconf
USE_XORG=	x11

NO_STAGE=	yes
.include <bsd.port.mk>
