# New ports collection makefile for:	gnomebreakout
# Date created:				01 Sep 2000
# Whom:					Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomebreakout
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	http://users.senet.com.au/~alcaron/
DISTNAME=	gnome-breakout-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME version of the classic breakout game

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
