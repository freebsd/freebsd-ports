# New ports collection makefile for:	gnomechess
# Date created:				29 January 2000
# Whom:					Jeremy Lea <reg@shale.csir.co.za>
#
# $FreeBSD$
#

PORTNAME=	gnomechess
PORTVERSION=	0.2.4
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-chess
DISTNAME=	gnome-chess-${PORTVERSION}

MAINTAINER=	reg@FreeBSD.org

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
