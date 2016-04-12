# Created by: markand
# $FreeBSD$

PORTNAME=	squeeze
PORTVERSION=	0.2.3
PORTREVISION=	10
CATEGORIES=	archivers xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Squeeze is a modern and advanced archive manager

LICENSE=	GPLv2

LIB_DEPENDS=	libthunar-vfs-1.so:x11-fm/thunar-vfs

SSP_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		tar:bzip2 pkgconfig gmake gettext pathfix desktop-file-utils \
	libtool xfce
USE_XFCE=	thunar
USE_XORG=	x11
USE_GNOME=	gtk20 glib20 intltool intlhack
USE_LDCONFIG=	yes
MAKE_JOB_SAFE=	yes

CONFIGURE_ARGS=--disable-static --without-html-dir

.include <bsd.port.mk>
