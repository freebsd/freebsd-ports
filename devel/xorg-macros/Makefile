# New ports collection makefile for:	xorg-macros
# Date Created:				24 Mar 2007
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-macros
PORTVERSION=	1.6.0
CATEGORIES=	devel x11
DISTNAME=	util-macros-$(PORTVERSION)

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org development aclocal macros

XORG_CAT=	util

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

PLIST_FILES=	share/aclocal/xorg-macros.m4 \
		libdata/pkgconfig/xorg-macros.pc \
		share/util-macros/INSTALL

PLIST_DIRS=	share/util-macros

.include <bsd.port.mk>
