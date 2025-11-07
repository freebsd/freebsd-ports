PORTNAME=	baresip
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	zarychtam@plan-b.pwste.edu.pl
COMMENT=	Small SIP client
WWW=		https://github.com/baresip

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libre.so:audio/re

FLAVORS=			default nox11
default_CONFLICTS_INSTALL=	barsip-nox11
nox11_PKGNAMESUFFIX=		-nox11
nox11_CONFLICTS_INSTALL=	baresip

USES=		cmake localbase:ldflags pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	baresip
GH_TUPLE=	baresip:baresip-apps:v4.0.0:e/baresip-apps
PORTDOCS=	CONTRIBUTING.md ChangeLog THANKS

OPTIONS_DEFINE=		AAC ALSA AV1 AVCODEC AVFILTER AVFORMAT CODEC2 DBUS DOCS \
			EVDEV EXAMPLES G711 G722 G726 GSTREAMER GTK3 JACK MQTT \
			OPUS PIPEWIRE PLC PORTAUDIO PULSEAUDIO SDL SNAPSHOT \
			SNDFILE SNDIO SWSCALE V4L VPX WEBRTC_AEC X11
OPTIONS_DEFAULT=	AAC ALSA AV1 AVCODEC AVFILTER AVFORMAT CODEC2 DBUS \
			EVDEV G711 G722 G726 GSTREAMER GTK3 OPUS PLC PORTAUDIO \
			SDL SNAPSHOT SNDFILE SWSCALE V4L VPX WEBRTC_AEC X11
OPTIONS_GROUP=		EXTRAMODULES
.if ${FLAVOR:U} == nox11
COMMENT+=		(without X11 and video calls)
OPTIONS_EXCLUDE=	AAC AV1 AVCODEC AVFILTER AVFORMAT CODEC2 DBUS EVDEV \
			GSTREAMER GTK3 SDL SNAPSHOT SWSCALE V4L VPX WEBRTC_AEC \
			X11
.endif
OPTIONS_SUB=		yes

AAC_DESC=		AAC audio codec
AV1_DESC=		AV1 Video Codec
AVCODEC_DESC=		Video codecs using libavcodec
AVFILTER_DESC=		Video filter using libavfilter
AVFORMAT_DESC=		libavformat media-source
CODEC2_DESC=		Codec2 low-bitrate speech codec
EVDEV_DESC=		evdev input support
G711_DESC=		G.711 audio codec
G722_DESC=		G.722 audio codec
G726_DESC=		G.726 audio codec
MQTT_DESC=		Message Queue Telemetry Transport (MQTT) client
PLC_DESC=		Packet Loss Concealment
SNAPSHOT_DESC=		Snapshot video module
SWSCALE_DESC=		Video filter for scaling and pixel conversion
WEBRTC_AEC_DESC=	WebRTC Acoustic Echo Cancellation

_MODULES_LIST=	account aubridge auconv aufile augain auresamp ausine cons \
		contact ctrl_tcp debug_cmd dtls_srtp echo fakevideo httpd \
		httpreq ice in_band_dtmf l16 menu mixausrc mixminus mwi natpmp \
		netroam pcp presence rtcpsummary selfview serreg srtp stdio \
		stun syslog turn uuid vidbridge vidinfo vumeter

AAC_LIB_DEPENDS=	libfdk-aac.so:audio/fdk-aac
AAC_VARS=		_MODULES_LIST+=aac
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_VARS=		_MODULES_LIST+=alsa
AV1_LIB_DEPENDS+=	libaom.so:multimedia/aom
AV1_VARS=		_MODULES_LIST+=av1
AVCODEC_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libdrm.so:graphics/libdrm
AVCODEC_VARS=		_MODULES_LIST+=avcodec
AVFILTER_LIB_DEPENDS=	libavfilter.so:multimedia/ffmpeg
AVFILTER_VARS=		_MODULES_LIST+=avfilter
AVFORMAT_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
AVFORMAT_VARS=		_MODULES_LIST+=avformat
CODEC2_LIB_DEPENDS=	libcodec2.so:audio/codec2
CODEC2_VARS=		_MODULES_LIST+=codec2
DBUS_USES=		gnome
DBUS_VARS=		_MODULES_LIST+=ctrl_dbus \
			USE_GNOME+=glib20
EVDEV_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
EVDEV_VARS=		_MODULES_LIST+=evdev
G711_LIB_DEPENDS=	libspandsp.so:comms/spandsp
G711_VARS=		_MODULES_LIST+=g711
G722_LIB_DEPENDS=	libspandsp.so:comms/spandsp
G722_VARS=		_MODULES_LIST+=g722
G726_LIB_DEPENDS=	libspandsp.so:comms/spandsp
G726_VARS=		_MODULES_LIST+=g726
GSTREAMER_USES=		gnome gstreamer:1
GSTREAMER_VARS=		_MODULES_LIST+=gst \
			USE_GNOME+=glib20
GTK3_USES=		gnome
GTK3_VARS=		_MODULES_LIST+=gtk \
			USE_GNOME+=gtk30
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_VARS=		_MODULES_LIST+=jack
MQTT_LIB_DEPENDS=	libmosquitto.so:net/mosquitto
MQTT_VARS=		_MODULES_LIST+=mqtt
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_VARS=		_MODULES_LIST+="opus opus_multistream"
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_VARS=		_MODULES_LIST+=pipewire
PLC_LIB_DEPENDS=	libspandsp.so:comms/spandsp
PLC_VARS=		_MODULES_LIST+=plc
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_VARS=		_MODULES_LIST+=portaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	_MODULES_LIST+=pulse
SDL_LIB_DEPENDS=	libglapi.so:graphics/mesa-libs
SDL_USES=		sdl
SDL_VARS=		_MODULES_LIST+=sdl \
			USE_SDL=sdl2
SNAPSHOT_LIB_DEPENDS=	libpng16.so:graphics/png
SNAPSHOT_VARS=		_MODULES_LIST+=snapshot
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_VARS=		_MODULES_LIST+=sndfile
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		_MODULES_LIST+=sndio
SWSCALE_LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg
SWSCALE_VARS=		_MODULES_LIST+=swscale
V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l1.so:multimedia/libv4l
V4L_VARS=		_MODULES_LIST+=v4l2
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_VARS=		_MODULES_LIST+="vp8 vp9"
WEBRTC_AEC_LIB_DEPENDS=	libwebrtc-audio-processing-1.so:audio/webrtc-audio-processing
WEBRTC_AEC_VARS=	_MODULES_LIST+=webrtc_aec
X11_USES=		xorg
X11_VARS=		_MODULES_LIST+=x11 \
			USE_XORG="ice sm x11 xext"

OPTIONS_GROUP_EXTRAMODULES=	AULOOP AUTOTEST EBUACIP INTERCOM KAOPTIONS \
				PARCALL QUALIFY REDIRECT VIDLOOP

AULOOP_DESC=	Application module for testing audio drivers
AUTOTEST_DESC=	Autotest module
EBUACIP_DESC=	EBU Audio Contribution over IP Profile
INTERCOM_DESC=	Intercom module
KAOPTIONS_DESC=	Keepalive via SIP OPTIONS module
PARCALL_DESC=	Parallel call module
QUALIFY_DESC=	Qualify peer module
REDIRECT_DESC=	Redirect incoming calls module
VIDLOOP_DESC=	Video-loop module for testing

AULOOP_VARS=	_EXTRAMOD_LIST+=auloop
AUTOTEST_VARS=	_EXTRAMOD_LIST+=autotest
EBUACIP_VARS=	_EXTRAMOD_LIST+=ebuacip
INTERCOM_VARS=	_EXTRAMOD_LIST+=intercom
KAOPTIONS_VARS=	_EXTRAMOD_LIST+=kaoptions
PARCALL_VARS=	_EXTRAMOD_LIST+=parcall
QUALIFY_VARS=	_EXTRAMOD_LIST+=qualify
REDIRECT_VARS=	_EXTRAMOD_LIST+=redirect
VIDLOOP_VARS=	_EXTRAMOD_LIST+=vidloop

.include <bsd.port.options.mk>

CMAKE_ARGS+=	-DAPP_MODULES="$(_EXTRAMOD_LIST:ts;)" \
		-DAPP_MODULES_DIR=baresip-apps/modules \
		-DMODULES="$(_MODULES_LIST:ts;)" \
		-DWEBRTC_AEC_INCLUDE_DIRS:STRING="${LOCALBASE}/include/webrtc-audio-processing-1"

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/cmake/FindGST.cmake

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
