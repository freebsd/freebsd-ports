# New ports collection makefile for:	gnocotan
# Date created:				22nd July 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pioneers
PORTVERSION=	0.9.19
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	pio

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	An Internet playable version of the Settlers of Catan for GNOME/GTK

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 libgnome
USE_LIBTOOL_VER=13
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN6=		pioneers.6 pioneers-server-gtk.6 pioneers-server-console.6 \
		pioneersai.6 pioneers-meta-server.6

.include <bsd.port.mk>
