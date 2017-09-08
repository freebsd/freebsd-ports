# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	rtmidi
DISTVERSION=	2.1.1-38
DISTVERSIONSUFFIX=	-g907a94c
CATEGORIES=	audio

MAINTAINER=	yuri@rawbw.com
COMMENT=	Set of C++ classes that provide a common API for realtime MIDI I/O

LICENSE=	MIT

LIB_DEPENDS=	libjack.so:audio/jack

USES=		autoreconf localbase libtool
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	thestk
CONFIGURE_ARGS=	--with-jack
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
