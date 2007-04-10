# New ports collection makefile for:	gnomecommon
# Date created:				04 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/gnomecommon/Makefile,v 1.5 2005/09/20 09:39:51 ahze Exp $
#

PORTNAME=	gnome-common
PORTVERSION=	2.18.0
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
