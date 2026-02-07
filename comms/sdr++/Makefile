PORTNAME=	sdr++
DISTVERSION=	20250105 # rolling (nightly) release is the current release model (see README)
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform SDR software
WWW=		https://github.com/AlexandreRouma/SDRPlusPlus

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libglfw.so:graphics/glfw \
		libvolk.so:devel/volk \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gl pkgconfig xorg
USE_GL=		gl glew glu opengl
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	AlexandreRouma
GH_PROJECT=	SDRPlusPlus
GH_TAGNAME=	ea3675d

PORTSCOUT=	ignore:1 # rolling release

OPTIONS_GROUP=			MODULES AUDIO_SOURCE AUDIO_SINK AUDIO_DECODER # the list is defined in CMakeLists.txt, also see https://github.com/AlexandreRouma/SDRPlusPlus?tab=readme-ov-file#module-list
OPTIONS_GROUP_AUDIO_SOURCE=	AIRSPY AIRSPYHF BADGESDR_SOURCE BLADERF FOBOS HACKRF LIMESDR PLUTOSDR RTAUDIO_SOURCE RTL_SDR
OPTIONS_GROUP_AUDIO_SINK=	NETWORK_SINK PORTAUDIO_SINK RTAUDIO_SINK # portaudio sinks are intended for MacOS only
OPTIONS_GROUP_AUDIO_DECODER=	ATV_DECODER DAB_DECODER M17_DECODER METEOR_DECODER RADIO WEATHER_SAT_DECODER
OPTIONS_SUB=			yes

AUDIO_SOURCE_DESC=		Audio Sources
AUDIO_SINK_DESC=		Audio Sinks
AUDIO_DECODER_DESC=		Audio Decoders

## Sources

AIRSPY_DESC=			Airspy Source Module
AIRSPY_CMAKE_BOOL=		OPT_BUILD_AIRSPY_SOURCE
AIRSPY_LIB_DEPENDS=		libairspy.so:comms/airspy

AIRSPYHF_DESC=			Airspy HF+ Source Module
AIRSPYHF_CMAKE_BOOL=		OPT_BUILD_AIRSPYHF_SOURCE
AIRSPYHF_LIB_DEPENDS=		libairspyhf.so:comms/airspyhf

BADGESDR_SOURCE_DESC=		BadgeSDR Source Module
BADGESDR_SOURCE_CMAKE_BOOL=	OPT_BUILD_BADGESDR_SOURCE

BLADERF_DESC=			BladeRF Source Module
BLADERF_CMAKE_BOOL=		OPT_BUILD_BLADERF_SOURCE
BLADERF_LIB_DEPENDS=		libbladeRF.so:comms/bladerf

FOBOS_DESC=			FobosSDR Source Module
FOBOS_CMAKE_BOOL=		OPT_BUILD_FOBOSSDR_SOURCE
FOBOS_LIB_DEPENDS=		libfobos.so:comms/libfobos
FOBOS_BROKEN=			https://github.com/AlexandreRouma/SDRPlusPlus/issues/1572

PLUTOSDR_DESC=			PlutoSDR Source Module
PLUTOSDR_CMAKE_BOOL=		OPT_BUILD_PLUTOSDR_SOURCE
PLUTOSDR_LIB_DEPENDS=		libad9361.so:misc/libad9361-iio \
				libiio.so:misc/libiio

LIMESDR_DESC=			LimeSDR Source Module
LIMESDR_CMAKE_BOOL=		OPT_BUILD_LIMESDR_SOURCE
LIMESDR_LIB_DEPENDS=		libLimeSuite.so:comms/limesuite

HACKRF_DESC=			HackRF Source Module
HACKRF_CMAKE_BOOL=		OPT_BUILD_HACKRF_SOURCE
HACKRF_LIB_DEPENDS=		libhackrf.so:comms/hackrf

RTAUDIO_SOURCE_DESC=		RtAudio Source Module
RTAUDIO_SOURCE_CMAKE_BOOL=	OPT_BUILD_AUDIO_SOURCE
RTAUDIO_SOURCE_LIB_DEPENDS=	librtaudio.so:audio/rtaudio

RTL_SDR_DESC=			RTL-SDR Source Module
RTL_SDR_CMAKE_BOOL=		OPT_BUILD_RTL_SDR_SOURCE
RTL_SDR_LIB_DEPENDS=		librtlsdr.so:comms/rtl-sdr

## Sinks

NETWORK_SINK_DESC=		Network Audio Sink Module
NETWORK_SINK_CMAKE_BOOL=	OPT_BUILD_NETWORK_SINK

PORTAUDIO_SINK_DESC=		PortAudio Sink Module
PORTAUDIO_SINK_CMAKE_BOOL=	OPT_BUILD_PORTAUDIO_SINK OPT_BUILD_NEW_PORTAUDIO_SINK
PORTAUDIO_SINK_LIB_DEPENDS=	libportaudio.so:audio/portaudio

RTAUDIO_SINK_DESC=		RtAudio Sink Module
RTAUDIO_SINK_CMAKE_BOOL=	OPT_BUILD_AUDIO_SINK
RTAUDIO_SINK_LIB_DEPENDS=	librtaudio.so:audio/rtaudio
RTAUDIO_SINK_BROKEN=		fails at run-time: Illegal Instruction

## Decoders

ATV_DECODER_DESC=		ATV decoder
ATV_DECODER_CMAKE_BOOL=		OPT_BUILD_ATV_DECODER

DAB_DECODER_DESC=		DAB/DAB+ decoder
DAB_DECODER_CMAKE_BOOL=		OPT_BUILD_DAB_DECODER
DAB_DECODER_BROKEN=		unfinished as per https://github.com/AlexandreRouma/SDRPlusPlus?tab=readme-ov-file#decoders

M17_DECODER_DESC=		M17 decoder module
M17_DECODER_CMAKE_BOOL=		OPT_BUILD_M17_DECODER
M17_DECODER_LIB_DEPENDS=	libcodec2.so:audio/codec2

METEOR_DECODER_DESC=		METEOR demodulator module
METEOR_DECODER_CMAKE_BOOL=	OPT_BUILD_METEOR_DEMODULATOR

RADIO_DESC=			Main audio modulation decoder (AM, FM, SSB, etc...)
RADIO_CMAKE_BOOL=		OPT_BUILD_RADIO

WEATHER_SAT_DECODER_DESC=	HRPT decoder module
WEATHER_SAT_DECODER_CMAKE_BOOL=	OPT_BUILD_WEATHER_SAT_DECODER
WEATHER_SAT_DECODER_BROKEN=	unfinished as per https://github.com/AlexandreRouma/SDRPlusPlus?tab=readme-ov-file#decoders

.for o in ${OPTIONS_GROUP_AUDIO_SOURCE} ${OPTIONS_GROUP_AUDIO_SINK} ${OPTIONS_GROUP_AUDIO_DECODER}
.  if "${${o}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${o}
.  endif
.endfor

.include <bsd.port.mk>
