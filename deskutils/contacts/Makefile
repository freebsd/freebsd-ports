# New ports collection makefile for:	contacts
# Date created:				2005-12-15
# Whom:					Piotr SMyrak, smyru@heron.pl
#
# $FreeBSD$
#

PORTNAME=	contacts
PORTVERSION=	0.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://projects.o-hand.com/sources/contacts/ \
		http://smyru.petronet.pl/freebsd/
DIST_SUBDIR=	gnome2

MAINTAINER=	smyru@heron.pl
COMMENT=	Simple yet powerful address book based on Evolution data server

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehier evolutiondataserver
USE_AUTOTOOLS=	libtool:15
GCONF_SCHEMAS=	contacts.schemas
# CFLAGS+=	-g

.include <bsd.port.mk>
