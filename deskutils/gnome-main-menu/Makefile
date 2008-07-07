# New ports collection makefile for:	gnome-main-menu
# Date created:				06 July 2008
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-main-menu
PORTVERSION=	0.9.10
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides easy access to sets of GNOME applications

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnomepanel intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	application-browser.schemas slab.schemas

.include <bsd.port.mk>
