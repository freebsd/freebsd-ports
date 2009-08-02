# New ports collection makefile for:	libnotifymm
# Date created:		2008-03-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libnotifymm
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrappers for libnotify

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	pkgconfig gnomehack gnomeprefix ltverhack
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/libnotify `pkg-config --cflags glibmm-2.4 libnotify gtkmm-2.4`"
USE_LDCONFIG=	yes

.include <bsd.port.mk>
