PORTNAME=	portmidi
PORTVERSION=	236
CATEGORIES=	audio

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Library for real time MIDI input and output

LICENSE=	PL
LICENSE_NAME=	PortMidi license
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cmake dos2unix localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	mixxxdj

.include <bsd.port.mk>
