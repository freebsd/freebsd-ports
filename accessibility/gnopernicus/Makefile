# New ports collection makefile for:	gnopernicus
# Date created:				11 May 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnopernicus
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	accessibility x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.7
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of accessibility apps for GNOME 2

LIB_DEPENDS=	gnome-mag.1:${PORTSDIR}/accessibility/gnomemag \
		gnomespeech.6:${PORTSDIR}/accessibility/gnomespeech

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libgnomeui atspi
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
