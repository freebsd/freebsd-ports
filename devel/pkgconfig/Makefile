# New ports collection makefile for:	pkgconfig
# Date created:				30 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/pkgconfig/Makefile,v 1.6 2005/10/14 20:39:57 adamw Exp $
#

PORTNAME=	pkgconfig
PORTVERSION=	0.19
CATEGORIES=	devel
MASTER_SITES=	http://pkgconfig.freedesktop.org/releases/
DISTNAME=	pkg-config-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A utility to retrieve information about installed libraries

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnometarget
LIBTOOLFILES=	glib-1.2.8/configure
LIBTOOLFLAGS=	--disable-ltlibs \
		--disable-shared

MAN1=		pkg-config.1

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--disable-threads \
		--with-pc-path="${PREFIX}/libdata/pkgconfig:${LOCALBASE}/libdata/pkgconfig:${X11BASE}/libdata/pkgconfig"

.include <bsd.port.post.mk>
