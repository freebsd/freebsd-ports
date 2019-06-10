# $FreeBSD$

PORTNAME=	rtaudio
DISTVERSION=	5.1.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ classes that provide a common API for realtime audio input/output

LICENSE=	MIT

USES=		autoreconf compiler:c++11-lang libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	thestk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
