# $FreeBSD$

PORTNAME=	multimon-ng
PORTVERSION=	1.1.0
CATEGORIES=	comms hamradio

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Digital transmission decoder

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	EliasOenal

USES=		cmake

OPTIONS_DEFINE=	PULSEAUDIO X11

X11_CMAKE_BOOL=	X11_SUPPORT

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	PULSE_AUDIO_SUPPORT

PLIST_FILES+=	bin/multimon-ng

.include <bsd.port.pre.mk>
.if ${PORT_OPTIONS:MX11}
USE_XORG+=	sm ice x11 xext
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multimon-ng ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
