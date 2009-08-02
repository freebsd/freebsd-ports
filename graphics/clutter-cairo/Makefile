# New ports collection makefile for:	clutter-cairo
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clutter-cairo
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/${PORTNAME}/0.8/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter Cairo integrarion library

LIB_DEPENDS=	clutter-glx-0.8:${PORTSDIR}/graphics/clutter \
		cairo.2:${PORTSDIR}/graphics/cairo

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack ltverhack
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
