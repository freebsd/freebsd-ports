# New ports collection makefile for:	gnocotan
# Date created:				22nd July 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnocatan
PORTVERSION=	0.8.1.30
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	An Internet playable version of the Settlers of Catan for GNOME/GTK

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 libgnomeui
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN6=		gnocatan.6 gnocatan-server-gtk.6 gnocatan-server-console.6 \
		gnocatanai.6 gnocatan-meta-server.6

.include <bsd.port.mk>
