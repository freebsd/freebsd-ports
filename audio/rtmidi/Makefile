PORTNAME=	rtmidi
DISTVERSION=	6.0.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of C++ classes that provide a common API for realtime MIDI I/O
WWW=		https://github.com/thestk/rtmidi

LICENSE=	MIT

LIB_DEPENDS=	libjack.so:audio/jack

USES=		autoreconf compiler:c11 libtool localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thestk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jack --disable-static

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/rtmidi/RtMidi.h \
		include/rtmidi/rtmidi_c.h \
		lib/librtmidi.so \
		lib/librtmidi.so.7 \
		lib/librtmidi.so.7.0.0 \
		libdata/pkgconfig/rtmidi.pc

.include <bsd.port.mk>
