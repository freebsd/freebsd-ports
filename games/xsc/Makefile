# New ports collection makefile for:	xsc
# Date created:			Apr 16, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	xsc
PORTVERSION=	1.3
CATEGORIES=	games
MASTER_SITES=	http://www.panix.com/~mbh/xsc/

MAINTAINER=	mark@kyne.com.au

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include" LDFLAGS="${LDFLAGS} -L${X11BASE}/lib"

.include <bsd.port.mk>
