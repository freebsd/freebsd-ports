# Created by: Adam Weinberger
# $FreeBSD$

PORTNAME=	cmus
PORTVERSION=	2.6.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Console-based music player with really cool features

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes

USES=		gmake pkgconfig iconv ncurses
HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	HOSTCC=${CC}
CONFIGURE_ARGS+=prefix=${PREFIX} mandir=${MANPREFIX}/man \
		exampledir=${EXAMPLESDIR} \
		CONFIG_ALSA=n CONFIG_ARTS=n CONFIG_ROAR=n

OPTIONS_DEFINE=	AAC AO CDDB CDIO CUE DISCID FFMPEG FLAC JACK MAD MIKMOD \
		MODPLUG MP4 MUSEPACK OPUS PULSEAUDIO SAMPLERATE TREMOR \
		VORBIS WAVPACK
OPTIONS_DEFAULT=AAC FFMPEG FLAC MAD MP4 VORBIS

DISCID_DESC=	DISCID support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	libFLAC.so:audio/flac
CONFIGURE_ARGS+=CONFIG_FLAC=y
PLIST_SUB+=	FLAC=""
.else
CONFIGURE_ARGS+=CONFIG_FLAC=n
PLIST_SUB+=	FLAC="@comment "
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	libmad.so:audio/libmad
CONFIGURE_ARGS+=CONFIG_MAD=y
PLIST_SUB+=	MAD=""
.else
CONFIGURE_ARGS+=CONFIG_MAD=n
PLIST_SUB+=	MAD="@comment "
.endif

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	libmodplug.so:audio/libmodplug
CONFIGURE_ARGS+=CONFIG_MODPLUG=y
PLIST_SUB+=	MODPLUG=""
.else
CONFIGURE_ARGS+=CONFIG_MODPLUG=n
PLIST_SUB+=	MODPLUG="@comment "
.endif

.if ${PORT_OPTIONS:MMIKMOD}
LIB_DEPENDS+=	libmikmod.so:audio/libmikmod
CONFIGURE_ARGS+=CONFIG_MIKMOD=y
PLIST_SUB+=	MIKMOD=""
.else
PLIST_SUB+=	MIKMOD="@comment "
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
LIB_DEPENDS+=	libmpcdec.so:audio/musepack
CONFIGURE_ARGS+=CONFIG_MPC=y
PLIST_SUB+=	MPC=""
.else
CONFIGURE_ARGS+=CONFIG_MPC=n
PLIST_SUB+=	MPC="@comment "
.endif

.if ${PORT_OPTIONS:MOPUS}
LIB_DEPENDS+=	libopusfile.so:audio/opusfile
CONFIGURE_ARGS+=CONFIG_OPUS=y
PLIST_SUB+=	OPUS=""
.else
CONFIGURE_ARGS+=CONFIG_OPUS=n
PLIST_SUB+=	OPUS="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS} || ${PORT_OPTIONS:MTREMOR}
LIB_DEPENDS+=	libvorbisfile.so:audio/libvorbis
CONFIGURE_ARGS+=CONFIG_VORBIS=y
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=CONFIG_VORBIS=n
PLIST_SUB+=	VORBIS="@comment "
.endif

.if ${PORT_OPTIONS:MTREMOR}
LIB_DEPENDS+=	libvorbisidec.so:audio/libtremor
CONFIGURE_ARGS+=CONFIG_TREMOR=y
.endif

.if ${PORT_OPTIONS:MMP4}
LIB_DEPENDS+=	libfaad.so:audio/faad
LIB_DEPENDS+=	libmp4v2.so:multimedia/mp4v2
CONFIGURE_ARGS+=CONFIG_MP4=y
PLIST_SUB+=	MP4=""
.else
CONFIGURE_ARGS+=CONFIG_MP4=n
PLIST_SUB+=	MP4="@comment "
.endif

.if ${PORT_OPTIONS:MAAC}
LIB_DEPENDS+=	libfaad.so:audio/faad
CONFIGURE_ARGS+=CONFIG_AAC=y
PLIST_SUB+=	AAC=""
.else
CONFIGURE_ARGS+=CONFIG_AAC=n
PLIST_SUB+=	AAC="@comment "
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	libwavpack.so:audio/wavpack
CONFIGURE_ARGS+=CONFIG_WAVPACK=y
PLIST_SUB+=	WAVPACK=""
.else
CONFIGURE_ARGS+=CONFIG_WAVPACK=n
PLIST_SUB+=	WAVPACK="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
BUILD_DEPENDS+=	ffmpeg>=2:multimedia/ffmpeg
RUN_DEPENDS+=	ffmpeg>=2:multimedia/ffmpeg
CONFIGURE_ARGS+=CONFIG_FFMPEG=y
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=CONFIG_FFMPEG=n
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MAO}
LIB_DEPENDS+=	libao.so:audio/libao
CONFIGURE_ARGS+=CONFIG_AO=y
PLIST_SUB+=	AO=""
.else
CONFIGURE_ARGS+=CONFIG_AO=n
PLIST_SUB+=	AO="@comment "
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:audio/pulseaudio
CONFIGURE_ARGS+=CONFIG_PULSE=y
PLIST_SUB+=	PULSEAUDIO=""
.else
CONFIGURE_ARGS+=CONFIG_PULSE=n
PLIST_SUB+=	PULSEAUDIO="@comment "
.endif

.if ${PORT_OPTIONS:MCDDB} && ${PORT_OPTIONS:MCDIO}
LIB_DEPENDS+=	libcddb.so:audio/libcddb
CONFIGURE_ARGS+=CONFIG_CDDB=y
.else
CONFIGURE_ARGS+=CONFIG_CDDB=n
.endif

.if ${PORT_OPTIONS:MCDIO}
LIB_DEPENDS+=	libcdio_cdda.so:sysutils/libcdio-paranoia
CONFIGURE_ARGS+=CONFIG_CDIO=y
PLIST_SUB+=	CDIO=""
.else
CONFIGURE_ARGS+=CONFIG_CDIO=n
PLIST_SUB+=	CDIO="@comment "
.endif

.if ${PORT_OPTIONS:MCUE}
LIB_DEPENDS+=	libcue.so:textproc/libcue
CONFIGURE_ARGS+=CONFIG_CUE=y
PLIST_SUB+=	CUE=""
.else
CONFIGURE_ARGS+=CONFIG_CUE=n
PLIST_SUB+=	CUE="@comment "
.endif

.if ${PORT_OPTIONS:MDISCID}
LIB_DEPENDS+=	libdiscid.so:audio/libdiscid
CONFIGURE_ARGS+=CONFIG_DISCID=y
.else
CONFIGURE_ARGS+=CONFIG_DISCID=n
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:audio/jack
CONFIGURE_ARGS+=CONFIG_JACK=y
PLIST_SUB+=	JACK=""
.else
CONFIGURE_ARGS+=CONFIG_JACK=n
PLIST_SUB+=	JACK="@comment "
.endif

.if ${PORT_OPTIONS:MSAMPLERATE} && ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libsamplerate.so:audio/libsamplerate
CONFIGURE_ARGS+=CONFIG_SAMPLERATE=y
.else
CONFIGURE_ARGS+=CONFIG_SAMPLERATE=n
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,doc/cmus/examples,examples/cmus,g' \
		${WRKSRC}/Doc/cmus.txt
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},g' ${WRKSRC}/Doc/cmus.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cmus*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/cmus/[io]p/*.so

.include <bsd.port.mk>
