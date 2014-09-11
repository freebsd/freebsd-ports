# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pioneers
PORTVERSION=	15.1
#PORTREVISION=	0
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	SF/pio/Source/

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	Internet playable version of the Settlers of Catan

LICENSE=	GPLv2

RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp

USES=		gettext gmake
USE_GNOME=	gnomehack gnomeprefix gtk20 libgnome librsvg2
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
