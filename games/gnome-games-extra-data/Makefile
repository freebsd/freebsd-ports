# New ports collection makefile for:	gnomegames2-extra-data
# Date created:				16 August 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnome-games-extra-data/Makefile,v 1.26 2009/03/16 07:43:04 kwm Exp $
#

PORTNAME=	gnome-games-extra-data
PORTVERSION=	2.26.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Themes and artwork for the gnome-games package

RUN_DEPENDS=	${LOCALBASE}/bin/sol:${PORTSDIR}/games/gnome-games

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
