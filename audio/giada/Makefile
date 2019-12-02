# $FreeBSD$

PORTNAME=	giada
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0-7
DISTVERSIONSUFFIX=	-g26ebbce7
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hardcore loop machine

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libjansson.so:devel/jansson \
		libpulse.so:audio/pulseaudio \
		librtmidi.so:audio/rtmidi \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile

USES=		autoreconf compiler:c++14-lang gmake localbase xorg
USE_GITHUB=	yes
GH_ACCOUNT=	monocasual
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${OPSYS:tl}
USE_XORG=	x11 xcursor xext xfixes xft xinerama xpm xrender
LDFLAGS+=	-lfltk

PLIST_FILES=	bin/giada

.include <bsd.port.mk>
