PORTNAME=	rtmidi
DISTVERSION=	5.0.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of C++ classes that provide a common API for realtime MIDI I/O

LICENSE=	MIT

LIB_DEPENDS=	libjack.so:audio/jack

USES=		autoreconf compiler:c11 libtool localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thestk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jack --disable-static

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
