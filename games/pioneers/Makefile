# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pioneers
PORTVERSION=	14.1
#PORTREVISION=	0
CATEGORIES=	games gnome
MASTER_SITES=	SF/pio/Source/

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	An Internet playable version of the Settlers of Catan for GNOME/GTK+

RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp

USE_GMAKE=	yes
USES=		gettext
USE_GNOME=	gnomehack gnomeprefix gtk20 libgnome
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN6=		pioneers.6 pioneers-server-gtk.6 pioneers-server-console.6 \
		pioneersai.6 pioneers-meta-server.6 pioneers-editor.6

NO_STAGE=	yes
.include <bsd.port.mk>
