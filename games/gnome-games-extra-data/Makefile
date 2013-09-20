# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/games/gnome-games-extra-data/Makefile,v 1.31 2010/04/02 18:32:52 kwm Exp $

PORTNAME=	gnome-games-extra-data
PORTVERSION=	2.30.0
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Themes and artwork for the gnome-games package

RUN_DEPENDS=	${LOCALBASE}/bin/lightsoff:${PORTSDIR}/games/gnome-games

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

NO_STAGE=	yes
.include <bsd.port.mk>
