# New ports collection makefile for:	gnomechess
# Date created:				29 January 2000
# Whom:					Jeremy Lea <reg@shale.csir.co.za>
#
# $FreeBSD$
#

PORTNAME=	gnomechess
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-chess/0.3
DISTNAME=	gnome-chess-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI chess front-end to crafy, for the GNOME Desktop Environment

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomecanvas gnomehack gnomeprefix libglade
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
