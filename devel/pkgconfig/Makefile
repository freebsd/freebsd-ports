# New ports collection makefile for:	pkgconfig
# Date created:				30 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkgconfig
PORTVERSION=	0.8.0
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	glib-1.2.8/configure
LIBTOOLFLAGS=	--disable-ltlibs \
		--disable-shared
MAKE_ENV=	PKGCONF_BUILD=yes

PLIST_SUB=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

MAN1=		pkg-config.1

post-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
