# New ports collection makefile for:	gnomemag
# Date created:			12 April 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomemag
PORTVERSION=	0.10.5
PORTREVISION=	1
CATEGORIES=	accessibility x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-mag/0.10
DISTNAME=	gnome-mag-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen magnifier

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix atspi libbonobo
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
