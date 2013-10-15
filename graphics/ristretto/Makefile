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

LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libcairo.so:${PORTSDIR}/graphics/cairo

USES=		pkgconfig gettext pathfix desktop-file-utils gmake
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack
INSTALLS_ICONS=	yes
USE_XFCE=	configenv libmenu libutil xfconf
USE_XORG=	x11

.include <bsd.port.mk>
