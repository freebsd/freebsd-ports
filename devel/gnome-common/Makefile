# New ports collection makefile for:	gnomecommon
# Date created:				04 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomecommon
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-common/2.4
DISTNAME=	gnome-common-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for GNOME and GNOME 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnometarget
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
