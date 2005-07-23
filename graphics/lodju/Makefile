# New ports collection makefile for:	lodju
# Date created:		Fri Feb 08 10:50:01 PST 2002
# Whom:			jylitalo@iki.fi
#
# $FreeBSD$
#

PORTNAME=	lodju
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES+=	graphics
MASTER_SITES=	http://liw.iki.fi/liw/lodju/tarballs/

MAINTAINER?=	jylitalo@iki.fi
COMMENT?=	An image management tool for the X Window System

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
BUILD_DEPENDS=	gtk12-config:${PORTSDIR}/x11-toolkits/gtk12
LIB_DEPENDS=	glade-gnome:${PORTSDIR}/x11-toolkits/rep-gtk \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

MAN1=		lodju-create.1 lodju-gallery.1 lodju.1
MANCOMPRESSED=	yes

WANT_AUTOCONF_VER=253
HAS_CONFIGURE=  yes
USE_GETTEXT=	yes

.include <bsd.port.mk>
