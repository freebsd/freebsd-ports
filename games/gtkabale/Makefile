# New ports collection makefile for:   gtkabale
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkabale
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.seindal.dk/pub/rene/

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
