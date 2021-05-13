PORTNAME=	rtaudio
DISTVERSION=	5.1.0
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ classes that provide a common API for realtime audio input/output

LICENSE=	MIT

USES=		autoreconf compiler:c++11-lang libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thestk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			PULSEAUDIO
OPTIONS_DEFAULT=		PULSEAUDIO

PULSEAUDIO_CONFIGURE_WITH=	pulse
PULSEAUDIO_USES=		localbase:ldflags
PULSEAUDIO_LDFLAGS=		-lpulse # see https://github.com/thestk/rtaudio/issues/293
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

.include <bsd.port.mk>
