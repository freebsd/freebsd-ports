# New ports collection makefile for:    json-glib
# Date created:         		25 December 2008
# Whom:                 		Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	json-glib
PORTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	http://folks.o-hand.com/~ebassi/sources/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JSON (RFC 4627) interface for Glib

USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gnomeprefix ltverhack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
