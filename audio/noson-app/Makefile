# $FreeBSD$

PORTNAME=	noson-app
DISTVERSION=	3.15.2
CATEGORIES=	audio net

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Fast and smart SONOS controller

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libFLAC.so:audio/flac

USES=		cmake compiler:c++11-lang qt:5 ssl
USE_QT=		core declarative gui network quickcontrols2 \
		svg widgets xml \
		buildtools_build qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	janbar

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Pulse \
				CMAKE_DISABLE_FIND_PACKAGE_Pulse-simple

.include <bsd.port.mk>
