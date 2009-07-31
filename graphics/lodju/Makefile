# New ports collection makefile for:	lodju
# Date created:		Fri Feb 08 10:50:01 PST 2002
# Whom:			jylitalo@iki.fi
#
# $FreeBSD$
#

PORTNAME=	lodju
PORTVERSION=	1.1
PORTREVISION=	8
CATEGORIES+=	graphics
MASTER_SITES=	http://liw.iki.fi/liw/lodju/tarballs/

MAINTAINER?=	jylitalo@iki.fi
COMMENT?=	An image management tool for the X Window System

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	glade-gnome:${PORTSDIR}/x11-toolkits/rep-gtk

MAN1=		lodju-create.1 lodju-gallery.1 lodju.1
MANCOMPRESSED=	yes

USE_AUTOTOOLS=	autoconf:262:env
HAS_CONFIGURE=  yes
USE_GETTEXT=	yes
USE_GNOME=	gtk12 gdkpixbuf

.include <bsd.port.mk>
