# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	rtmidi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of C++ classes that provide a common API for realtime MIDI I/O

LICENSE=	MIT

LIB_DEPENDS=	libjack.so:audio/jack

USES=		autoreconf compiler:c11 libtool localbase
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	thestk
CONFIGURE_ARGS=	--with-jack --disable-static
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
