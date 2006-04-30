# New ports collection makefile for:	gnomegames2-extra-data
# Date created:				16 August 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnomegames2-extra-data/Makefile,v 1.8 2006/04/22 18:07:24 marcus Exp $
#

PORTNAME=	gnomegames2-extra-data
PORTVERSION=	2.14.0
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-games-extra-data/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-games-extra-data-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Themes and artwork for the gnomegames2 package

RUN_DEPENDS=	${X11BASE}/bin/sol:${PORTSDIR}/games/gnomegames2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
