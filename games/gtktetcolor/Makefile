# New ports collection makefile for:	gtktetcolor
# Date created:				17 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtktetcolor
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://canopus.iacp.dvo.ru/pub/Games/gtktetcolor/
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game for GNOME that resembles well-known tetris and columns

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
