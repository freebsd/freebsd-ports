PORTNAME=	noson
DISTVERSION=	2.12.10
CATEGORIES=	audio net

MAINTAINER=	arved@FreeBSD.org
COMMENT=	C++ library for accessing SONOS devices
WWW=		https://github.com/janbar/noson/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libFLAC.so:audio/flac

USES=		cmake compiler:c++11-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	janbar
CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	PULSEAUDIO
OPTIONS_SUB=	yes
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Pulse \
				CMAKE_DISABLE_FIND_PACKAGE_Pulse-simple

.include <bsd.port.mk>
