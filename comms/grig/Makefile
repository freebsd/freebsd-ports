PORTNAME=	grig
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio control front-end
WWW=		https://groundstation.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhamlib.so:comms/hamlib \
			libharfbuzz.so:print/harfbuzz \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2

USES=		autoreconf gettext gmake gnome libtool pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fillods
GH_PROJECT=	grig
GH_TAGNAME=	9d79adb

USE_GNOME=	cairo gdkpixbuf gtk20 intltool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

LIBS+=		-lm

.include <bsd.port.mk>
