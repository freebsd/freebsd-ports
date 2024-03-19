PORTNAME=	qmidinet
DISTVERSION=	0.9.12
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI network gateway application
WWW=		https://qmidinet.sourceforge.io

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjack.so:audio/jack

USES=		cmake compiler:c++17-lang gl pkgconfig qt:6
USE_QT=		base svg tools:build
USE_GL=		gl opengl

CMAKE_OFF=	CONFIG_ALSA_MIDI # libalsa doesn't have MIDI functionality on FreeBSD

BINARY_ALIAS=	git=false

.include <bsd.port.mk>
