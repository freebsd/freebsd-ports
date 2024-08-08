PORTNAME=	baresip
DISTVERSIONPREFIX=	v
DISTVERSION=	3.14.0
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small SIP client
WWW=		https://github.com/baresip

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	re>=${PORTVERSION:R}:audio/re
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cmake pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	baresip

# FIXME values of the next 3 variables taken from source code Makefile
ABI_MAJOR=	16
ABI_AGE=	14
ABI_REV=	0
PLIST_SUB=	ABI_MAJOR=${ABI_MAJOR}
PLIST_SUB+=	ABI_AGE=${ABI_AGE} \
		ABI_REV=${ABI_REV}

OPTIONS_DEFINE=		ALSA AV1 AVCODEC AVFILTER AVFORMAT CTRL_DBUS DOCS \
			EXAMPLES G711 G722 G726 GST MQTT OPUS OPUS_MS PLC \
			PORTAUDIO PULSEAUDIO SDL SNAPSHOT SNDFILE SWSCALE V4L2 \
			VPX X11
OPTIONS_DEFAULT=	DOCS EXAMPLES
OPTIONS_SUB=		yes

ALSA_DESC=		ALSA audio driver
AV1_DESC=		AV1 Video Codec
AVCODEC_DESC=		Video codecs using libavcodec
AVFILTER_DESC=		Video filter using libavfilter
AVFORMAT_DESC=		libavformat media-source
CTRL_DBUS_DESC=		[broken] DBUS interface for baresip
G711_DESC=		G.711 audio codec
G722_DESC=		G.722 audio codec
G726_DESC=		G.726 audio codec
GST_DESC=		Gstreamer audio module
MQTT_DESC=		Message Queue Telemetry Transport (MQTT) client
OPUS_DESC=		Opus audio codec
OPUS_MS_DESC=		Opus Multistream audio codec
PLC_DESC=		Packet Loss Concealment
PORTAUDIO_DESC=		Portaudio audio driver
PULSEAUDIO_DESC=	Pulseaudio audio driver
SDL_DESC=		libSDL2 video output
SNAPSHOT_DESC=		Snapshot video module
SNDFILE_DESC=		sndfile wav dumper
SWSCALE_DESC=		Video filter for scaling and pixel conversion
V4L2_DESC=		Video4Linux2 module
VPX_DESC=		VP8/VP9 video codecs
X11_DESC=		X11 video output

MODULES_LIST:=	account;aubridge;auconv;aufile;auresamp;ausine
MODULES_LIST:=	$(MODULES_LIST);cons;contact;ctrl_tcp
MODULES_LIST:=	$(MODULES_LIST);debug_cmd;dtls_srtp
MODULES_LIST:=	$(MODULES_LIST);ebuacip;echo
MODULES_LIST:=	$(MODULES_LIST);fakevideo;httpd;httpreq;ice;l16
MODULES_LIST:=	$(MODULES_LIST);menu;mixausrc;mixminus;mwi;natpmp;netroam
MODULES_LIST:=	$(MODULES_LIST);pcp;presence;rtcpsummary
MODULES_LIST:=	$(MODULES_LIST);selfview;serreg;srtp;stdio;stun;syslog
MODULES_LIST:=	$(MODULES_LIST);turn;uuid;vidbridge;vidinfo;vumeter

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
ALSA_DEPEND=	${LOCALBASE}/include/alsa/asoundlib.h:audio/alsa-lib
MODULES_LIST:=	$(MODULES_LIST);alsa
.endif

.if ${PORT_OPTIONS:MAV1}
LIB_DEPENDS+=	libaom.so:multimedia/aom
MODULES_LIST:=	$(MODULES_LIST);av1
.endif

.if ${PORT_OPTIONS:MAVCODEC}
AVCODEC_DEPEND=	${LOCALBASE}/include/libavcodec/avcodec.h:multimedia/ffmpeg \
		libdrm>0:graphics/libdrm
MODULES_LIST:=	$(MODULES_LIST);avcodec
.endif

.if ${PORT_OPTIONS:MAVFILTER}
AVFILTER_DEPEND=	${LOCALBASE}/include/libavfilter/avfilter.h:multimedia/ffmpeg
MODULES_LIST:=		$(MODULES_LIST);avfilter
.endif

.if ${PORT_OPTIONS:MAVFORMAT}
AVFORMAT_DEPEND=	${LOCALBASE}/include/libavformat/avformat.h:multimedia/ffmpeg
MODULES_LIST:=		$(MODULES_LIST);avformat
.endif

.if ${PORT_OPTIONS:MG711}
G711_DEPEND=	${LOCALBASE}/include/spandsp/g711.h:comms/spandsp
MODULES_LIST:=	$(MODULES_LIST);g711
.endif

.if ${PORT_OPTIONS:MG722}
G722_DEPEND=	${LOCALBASE}/include/spandsp/g722.h:comms/spandsp
MODULES_LIST:=	$(MODULES_LIST);g722
.endif

.if ${PORT_OPTIONS:MG726}
G726_DEPEND=	${LOCALBASE}/include/spandsp/g726.h:comms/spandsp
MODULES_LIST:=	$(MODULES_LIST);g726
.endif

.if ${PORT_OPTIONS:MGST}
GST_DEPEND=		${LOCALBASE}/include/gstreamer-1.0/gst/gst.h:multimedia/gstreamer1
PORT_OPTIONS+=		GSTREAMER
USES+=			gnome
USE_GNOME+=		glib20
USE_GSTREAMER1+=	yes
.endif

.if ${PORT_OPTIONS:MMQTT}
LIB_DEPENDS+=	libmosquitto.so:net/mosquitto
MODULES_LIST:=	$(MODULES_LIST);mqtt
.endif

.if ${PORT_OPTIONS:MOPUS}
OPUS_DEPEND=	${LOCALBASE}/include/opus/opus.h:audio/opus
MODULES_LIST:=	$(MODULES_LIST);opus
.endif

.if ${PORT_OPTIONS:MOPUS_MS}
OPUS_MS_DEPEND=	${LOCALBASE}/include/opus/opus.h:audio/opus
MODULES_LIST:=	$(MODULES_LIST);opus_multistream
.endif

.if ${PORT_OPTIONS:MPLC}
PLC_DEPEND=	${LOCALBASE}/include/spandsp/plc.h:comms/spandsp
MODULES_LIST:=	$(MODULES_LIST);plc
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
PORTAUDIO_DEPEND=	${LOCALBASE}/include/portaudio.h:audio/portaudio
MODULES_LIST:=		$(MODULES_LIST);portaudio
.endif

# Port calls it PULSE, standard OPTION is PULSEAUDIO
.if ${PORT_OPTIONS:MPULSEAUDIO}
PORT_OPTIONS+=		PULSE
PULSEAUDIO_DEPEND=	${LOCALBASE}/include/pulse/pulseaudio.h:audio/pulseaudio
MODULES_LIST:=		$(MODULES_LIST);pulse
.endif

.if ${PORT_OPTIONS:MSDL}
USES+=		sdl
USE_SDL=	sdl2
SDLDEPEND=	mesa-libs>0:graphics/mesa-libs
MODULES_LIST:=	$(MODULES_LIST);sdl
.endif

.if ${PORT_OPTIONS:MSNAPSHOT}
LIB_DEPENDS+=	libpng16.so:graphics/png
MODULES_LIST:=	$(MODULES_LIST);snapshot
.endif

.if ${PORT_OPTIONS:MSNDFILE}
SNDFILE_DEPEND=	${LOCALBASE}/include/sndfile.h:audio/libsndfile
MODULES_LIST:=	$(MODULES_LIST);sndfile
.endif

.if ${PORT_OPTIONS:MSWSCALE}
SWSCALE_DEPEND=	${LOCALBASE}/include/libavformat/avformat.h:multimedia/ffmpeg
MODULES_LIST:=	$(MODULES_LIST);swscale
.endif

.if ${PORT_OPTIONS:MV4L2}
V4L2_DEPEND=	${LOCALBASE}/include/libv4l2.h:multimedia/libv4l \
		v4l_compat>0:multimedia/v4l_compat

MODULES_LIST:=	$(MODULES_LIST);v4l2
.endif

.if ${PORT_OPTIONS:MVPX}
VPX_DEPEND=	${LOCALBASE}/include/vpx/vp8.h:multimedia/libvpx
MODULES_LIST:=	$(MODULES_LIST);vp8;vp9
.endif

.if ${PORT_OPTIONS:MX11}
USES+=		xorg
USE_XORG=	x11
USE_XORG+=	ice sm xext
MODULES_LIST:=	$(MODULES_LIST);x11
.endif

.for o in ${PORT_OPTIONS}
BUILD_DEPENDS+=	${$o_DEPEND}
RUN_DEPENDS+=	${$o_DEPEND}
.endfor

CMAKE_ARGS+=	-DMODULES="$(MODULES_LIST)" \
		-DRE_INCLUDE_DIR:STRING="${LOCALBASE}/include/re" \
		-DREM_INCLUDE_DIR:STRING="${LOCALBASE}/include/rem"

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${MV} ${STAGEDIR}${DOCSDIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${DOCSDIR}/examples

.include <bsd.port.mk>
