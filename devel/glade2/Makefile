# New ports collection makefile for:	glade2
# Date created:		02 June 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glade2
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.0
DISTNAME=	glade-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomedb libgnomeui
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
