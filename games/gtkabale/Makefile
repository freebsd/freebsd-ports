# New ports collection makefile for:   gtkabale
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkabale
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.seindal.dk/pub/rene/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lazy version of solitaire game

USE_X_PREFIX=	yes
USE_GNOME=	imlib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
