PORTNAME=	libvgm
DISTVERSION=	g20250714
CATEGORIES=	audio

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	More modular rewrite of most components from VGMPlay
WWW=		https://github.com/ValleyBell/libvgm

USES=		cmake compiler:c++14-lang iconv
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ValleyBell
GH_TAGNAME=	7cad783

CMAKE_ON=	AUDIODRV_OSS
CMAKE_OFF=	CMAKE_CXX_EXTENSIONS
CMAKE_ARGS=	-DLIBRARY_TYPE=SHARED

OPTIONS_DEFINE=		PLAYER VGM2WAV
OPTIONS_DEFAULT=	PLAYER VGM2WAV
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA AO PULSEAUDIO
OPTIONS_SUB=		yes

PLAYER_DESC=		Build and install libvgm-player command
VGM2WAV_DESC=		Build and install vgm2wav command
AUDIO_DESC=		Additional audio backends support

PLAYER_CMAKE_BOOL=	BUILD_PLAYER

VGM2WAV_CMAKE_BOOL=	BUILD_VGM2WAV

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	AUDIODRV_ALSA

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CMAKE_BOOL=		AUDIODRV_LIBAO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_USES=	localbase:ldflags
PULSEAUDIO_CMAKE_BOOL=	AUDIODRV_PULSE

post-install-PLAYER-on:
	${MV} ${STAGEDIR}${PREFIX}/bin/player \
		${STAGEDIR}${PREFIX}/bin/libvgm-player

.include <bsd.port.mk>
