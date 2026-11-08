PORTNAME=	rtmidi
DISTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of C++ classes that provide a common API for realtime MIDI I/O
WWW=		https://github.com/thestk/rtmidi

LICENSE=	MIT

USES=		autoreconf compiler:c11 libtool localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thestk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	ALSA JACK
OPTIONS_DEFAULT=	ALSA JACK

BACKEND_DESC=		MIDI backend(s) to build

ALSA_CONFIGURE_WITH=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

JACK_CONFIGURE_WITH=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/rtmidi/RtMidi.h \
		include/rtmidi/rtmidi_c.h \
		lib/librtmidi.so \
		lib/librtmidi.so.7 \
		lib/librtmidi.so.7.0.0 \
		libdata/pkgconfig/rtmidi.pc

.include <bsd.port.mk>
