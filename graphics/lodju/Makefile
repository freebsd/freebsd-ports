# New ports collection makefile for:	lodju
# Date created:		Fri Feb 08 10:50:01 PST 2002
# Whom:			jylitalo@iki.fi
#
# $FreeBSD$
#

PORTNAME=	lodju
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://liw.iki.fi/liw/lodju/tarballs/

MAINTAINER?=	jylitalo@iki.fi
COMMENT?=	An image management tool for the X Window System

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		gtk12-config:${PORTSDIR}/x11-toolkits/gtk12 \
		${LOCALBASE}/include/libintl.h:${PORTSDIR}/devel/gettext-old
LIB_DEPENDS=	glade-gnome:${PORTSDIR}/x11-toolkits/rep-gtk \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

MAN1=		lodju-create.1 lodju-gallery.1 lodju.1
MANCOMPRESSED=	yes

AUTOCONF=       autoconf
GNU_AUTOCONF=   yes
HAS_CONFIGURE=  yes

.include <bsd.port.mk>
