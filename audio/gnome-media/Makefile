# New ports collection makefile for:	gnomemedia
# Date created:				20 January 1999
# Whom:					Jeremy Lea <reg@shale.csir.co.za>
#
# $FreeBSD$
#

PORTNAME=	gnomemedia
PORTVERSION=	1.2.0
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-media
DISTNAME=	gnome-media-${PORTVERSION}

MAINTAINER=	reg@FreeBSD.org

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		sox:${PORTSDIR}/audio/sox

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--without-ncurses \
		--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
