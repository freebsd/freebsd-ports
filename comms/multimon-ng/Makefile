PORTNAME=	multimon-ng
PORTVERSION=	1.1.0
CATEGORIES=	comms hamradio

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Digital transmission decoder

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	EliasOenal

USES=		cmake:insource

OPTIONS_DEFINE=	PULSEAUDIO X11

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	PULSE_AUDIO_SUPPORT

X11_USES=	xorg
X11_USE=	XORG=ice,sm,x11,xext
X11_CMAKE_BOOL=	X11_SUPPORT

PLIST_FILES=	bin/multimon-ng

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multimon-ng ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
