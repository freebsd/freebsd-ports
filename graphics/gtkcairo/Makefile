# New ports collection makefile for:	gtkcairo
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkcairo
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ bindings to cairo

LIB_DEPENDS=	cairo.1:${PORTSDIR}/graphics/cairo

USE_BZIP2=	yes
USE_GNOME=	gtk20 gnometarget gnomehack
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_FILES=	include/gtkcairo.h \
		lib/libgtkcairo.a \
		lib/libgtkcairo.so \
		lib/libgtkcairo.so.2 \
		libdata/pkgconfig/gtkcairo.pc

.include <bsd.port.mk>
