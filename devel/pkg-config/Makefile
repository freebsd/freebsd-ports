# New ports collection makefile for:	pkgconfig
# Date created:				30 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkgconfig
PORTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.15
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A utility used to retrieve information about installed libraries

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
LIBTOOLFILES=	glib-1.2.8/configure
LIBTOOLFLAGS=	--disable-ltlibs \
		--disable-shared
CONFIGURE_ARGS=	--disable-threads
MAKE_ENV=	PKGCONF_BUILD=yes

MAN1=		pkg-config.1

post-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
