# New ports collection makefile for:	gnomemedia
# Date created:				20 January 1999
# Whom:					Jeremy Lea <reg@shale.csir.co.za>
#
# $FreeBSD$
#

PORTNAME=	gnomemedia
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-media/1.2
DISTNAME=	gnome-media-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the GNOME desktop

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomelibs
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--without-ncurses
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
