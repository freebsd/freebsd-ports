# New ports collection makefile for:	ja-libtomoe-gtk
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtomoe-gtk
PORTVERSION=	0.1.0
#PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=tomoe/17171

MAINTAINER=	ume@FreeBSD.org
COMMENT=	TOMOE GTK+ library

LIB_DEPENDS=	tomoe.1:${PORTSDIR}/japanese/tomoe

USE_X_PREFIX=	yes
USE_GNOME=	lthack gnomehack gtk20
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

PLIST_DIRS=	include/tomoe
PLIST_FILES=	include/tomoe/tomoe_candidates_view.h \
		include/tomoe/tomoe_canvas.h include/tomoe/tomoe-gtk.h \
		include/tomoe/tomoe_window.h \
		lib/libtomoe-gtk.a lib/libtomoe-gtk.la \
		lib/libtomoe-gtk.so lib/libtomoe-gtk.so.0 \
		libdata/pkgconfig/libtomoe-gtk.pc

.include <bsd.port.mk>
