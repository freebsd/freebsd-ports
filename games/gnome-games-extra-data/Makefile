# New ports collection makefile for:	gnomegames2-extra-data
# Date created:				16 August 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnome-games-extra-data/Makefile,v 1.13 2007/02/16 18:14:25 mezz Exp $
#

PORTNAME=	gnome-games-extra-data
PORTVERSION=	2.17.90
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-games-extra-data/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Themes and artwork for the gnome-games package

RUN_DEPENDS=	${LOCALBASE}/bin/sol:${PORTSDIR}/games/gnome-games

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
