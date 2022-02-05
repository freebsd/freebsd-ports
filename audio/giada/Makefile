PORTNAME=	giada
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.1
PORTREVISION=	2
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

USES=		autoreconf compiler:c++14-lang gmake localbase pkgconfig xorg
GH_TUPLE=	nlohmann:json:db78ac1d7716f56fc9f1b030b715f872f93964e4:json/src/deps/json \
		monocasual:rtaudio:5386a90:rtaudio/src/deps/rtaudio

USE_GITHUB=	yes
GH_ACCOUNT=	monocasual

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${OPSYS:tl}
USE_XORG=	x11 xcursor xext xfixes xft xinerama xpm xrender

CXXFLAGS+=	`pkg-config --cflags rtmidi`
LDFLAGS+=	-lfltk

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
