# New ports collection makefile for:	gengameng
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	gengameng
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	http://sites.netscape.net/sarrazip/

MAINTAINER=	mark@kyne.com.au

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include" LDFLAGS="${LDFLAGS} -L${X11BASE}/lib"

.include <bsd.port.mk>
