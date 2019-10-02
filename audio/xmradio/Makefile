# Created by: Thomas Runge <runge@rostock.zgdv.de>
# $FreeBSD$

PORTNAME=	xmradio
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://BSDforge.com/projects/source/audio/xmradio/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Motif based FM tuner (for use with bktr(4) driver)

LICENSE=	BSD2CLAUSE

BROKEN=		/usr/bin/ld: cannot find -lXp
ONLY_FOR_ARCHS=	i386 amd64

USES=		imake motif
USE_XORG=	xpm

PLIST_FILES=	bin/xmradio lib/X11/app-defaults/XMradio

.include <bsd.port.mk>
