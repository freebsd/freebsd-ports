PORTNAME=	libvgm
DISTVERSION=	g20240103
CATEGORIES=	audio

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	More modular rewrite of most components from VGMPlay
WWW=		https://github.com/ValleyBell/libvgm

USES=		cmake iconv pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	ValleyBell
GH_TAGNAME=	223b6f9d629feda1982dc4bbeebd19fa63b987fb

CMAKE_ON=	AUDIODRV_OSS

OPTIONS_DEFINE=		ALSA AO PULSEAUDIO
OPTIONS_DEFAULT=	# none

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	AUDIODRV_ALSA

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CMAKE_BOOL=		AUDIODRV_LIBAO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_USES=	localbase:ldflags
PULSEAUDIO_CMAKE_BOOL=	AUDIODRV_PULSE

.include <bsd.port.mk>
