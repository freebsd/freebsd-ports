# New ports collection makefile for:   gob2
# Date created:        09 November 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gob2
PORTVERSION=	2.0.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A preprocessor for making GObjects with inline C

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gob2.1

.include <bsd.port.mk>
