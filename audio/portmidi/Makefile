PORTNAME=	portmidi
DISTVERSION=	2.0.6
DISTVERSIONPREFIX=v
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Library for real time MIDI input and output
WWW=		https://github.com/PortMidi

LICENSE=	PL
LICENSE_NAME=	PortMidi license
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cmake dos2unix localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	PortMidi

.include <bsd.port.mk>
