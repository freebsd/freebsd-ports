PORTNAME=	pioneers
PORTVERSION=	15.6
PORTREVISION=	6
CATEGORIES=	games gnome
MASTER_SITES=	SF/pio/Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet playable version of the Settlers of Catan
WWW=		https://pio.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libcanberra.so:audio/libcanberra \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	yelp:x11/yelp

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	cairo gnomeprefix gtk30 intltool librsvg2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
