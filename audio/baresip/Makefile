PORTNAME=	baresip
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.0
CATEGORIES=	audio

MAINTAINER=	herbert@gojira.at
COMMENT=	Small SIP client
WWW=		https://github.com/baresip

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	re>=${DISTVERSION:R}:audio/re
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cmake pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	baresip
PORTDOCS=	ChangeLog CONTRIBUTING.md THANKS

OPTIONS_DEFINE=		ALSA AV1 AVCODEC AVFILTER AVFORMAT CTRL_DBUS DOCS \
			EXAMPLES G711 G722 G726 GST GTK3 MQTT OPUS OPUS_MS PLC \
			PORTAUDIO PULSEAUDIO SDL SNAPSHOT SNDFILE SWSCALE V4L2 \
			VPX X11
OPTIONS_SUB=		yes

ALSA_DESC=	ALSA audio driver
AV1_DESC=	AV1 Video Codec
AVCODEC_DESC=	Video codecs using libavcodec
AVFILTER_DESC=	Video filter using libavfilter
AVFORMAT_DESC=	libavformat media-source
CTRL_DBUS_DESC=	[broken] DBUS interface for baresip
G711_DESC=	G.711 audio codec
G722_DESC=	G.722 audio codec
G726_DESC=	G.726 audio codec
GST_DESC=	Gstreamer audio module
MQTT_DESC=	Message Queue Telemetry Transport (MQTT) client
OPUS_MS_DESC=	Opus Multistream audio codec
PLC_DESC=	Packet Loss Concealment
SDL_DESC=	libSDL2 video output
SNAPSHOT_DESC=	Snapshot video module
SNDFILE_DESC=	sndfile wav dumper
SWSCALE_DESC=	Video filter for scaling and pixel conversion
V4L2_DESC=	Video4Linux2 module
VPX_DESC=	VP8/VP9 video codecs
X11_DESC=	X11 video output

_MODULES_LIST=	account aubridge auconv aufile auresamp ausine cons contact \
		ctrl_tcp debug_cmd dtls_srtp echo fakevideo httpd \
		httpreq ice l16 menu mixausrc mixminus mwi natpmp netroam pcp \
		presence rtcpsummary selfview serreg srtp stdio stun syslog \
		turn uuid vidbridge vidinfo vumeter

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
G711_LIB_DEPENDS=	libspandsp.so:comms/spandsp
G711_VARS=		_MODULES_LIST+=g711
G722_LIB_DEPENDS=	libspandsp.so:comms/spandsp
G722_VARS=		_MODULES_LIST+=g722
G726_LIB_DEPENDS=	libspandsp.so:comms/spandsp
G726_VARS=		_MODULES_LIST+=g726
GST_USES=		gnome gstreamer:1
GST_VARS=		USE_GNOME+=glib20
GTK3_USES=		gnome
GTK3_VARS=		USE_GNOME+=gtk30 _MODULES_LIST+=gtk
MQTT_LIB_DEPENDS=	libmosquitto.so:net/mosquitto
MQTT_VARS=		_MODULES_LIST+=mqtt
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_VARS=		_MODULES_LIST+=opus
OPUS_MS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_MS_VARS=		_MODULES_LIST+=opus_multistream
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
SWSCALE_LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg
SWSCALE_VARS=		_MODULES_LIST+=swscale
V4L2_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L2_LIB_DEPENDS=	libv4l1.so:multimedia/libv4l
V4L2_VARS=		_MODULES_LIST+=v4l2
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_VARS=		_MODULES_LIST+="vp8 vp9"
X11_USES=		xorg
X11_VARS=		_MODULES_LIST+=x11 \
			USE_XORG="x11 ice sm xext"

.include <bsd.port.options.mk>

CMAKE_ARGS+=	-DMODULES="$(_MODULES_LIST:ts;)" \
		-DRE_INCLUDE_DIR:STRING="${LOCALBASE}/include/re" \
		-DREM_INCLUDE_DIR:STRING="${LOCALBASE}/include/rem"

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
