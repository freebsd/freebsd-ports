# New ports collection makefile for:	eog
# Version required:	0.2
# Date created:		5th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

DISTNAME=	eog-0.2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/eog

MAINTAINER=	ade@lovett.com

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs \
		gdk_pixbuf.1:${PORTSDIR}/graphics/gdk-pixbuf

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
