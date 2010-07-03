# New ports collection makefile for:	gnocotan
# Date created:				22nd July 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pioneers
PORTVERSION=	0.12.3
#PORTREVISION=	0
CATEGORIES=	games gnome
MASTER_SITES=	SF/pio/Source/

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	An Internet playable version of the Settlers of Catan for GNOME/GTK+

RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 libgnome
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN6=		pioneers.6 pioneers-server-gtk.6 pioneers-server-console.6 \
		pioneersai.6 pioneers-meta-server.6 pioneers-editor.6

.include <bsd.port.mk>
