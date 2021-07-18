# Created by: Ade Lovett <ade@FreeBSD.org>

PORTNAME=	pioneers
PORTVERSION=	15.6
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	SF/pio/Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet playable version of the Settlers of Catan

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libcanberra.so:audio/libcanberra \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	yelp:x11/yelp

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	cairo gnomeprefix gtk30 intltool librsvg2
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
