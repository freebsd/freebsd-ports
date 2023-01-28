PORTNAME=	grig
PORTVERSION=	0.9.0
PORTREVISION=	1
#DISTNAME=	Grig
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio control front-end
WWW=		http://groundstation.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	fillods
GH_PROJECT=	grig
#GH_TAGNAME=	77ab785
GH_TAGNAME=	9d79adb

LIB_DEPENDS=	libhamlib.so:comms/hamlib \
			libharfbuzz.so:print/harfbuzz \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2

USE_GNOME=	cairo gdkpixbuf2 gtk20 intltool
GNU_CONFIGURE=	yes
USES=		autoreconf gettext gmake gnome libtool pkgconfig

LIBS+=		-lm

.include <bsd.port.mk>
