# New ports collection makefile for:	gnomecommon
# Date created:				04 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/gnome-common/Makefile,v 1.7 2007/09/17 18:37:36 ahze Exp $
#

PORTNAME=	gnome-common
PORTVERSION=	2.20.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for GNOME and GNOME 2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnometarget
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
