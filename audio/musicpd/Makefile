# $FreeBSD$

PORTNAME=	musicpd
PORTVERSION=	0.19.10
CATEGORIES=	audio ipv6
MASTER_SITES=	http://www.musicpd.org/download/mpd/${PORTVERSION:R}/
DISTNAME=	mpd-${PORTVERSION}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Remote-controllable music daemon

LICENSE=	GPLv2

USES=		gmake pkgconfig compiler:c++11-lib tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libicudata.so:devel/icu

USE_RC_SUBR=	${PORTNAME}
CONFIGURE_ARGS+=--disable-alsa --disable-systemd-daemon --disable-roar
CFLAGS+=	-I${PREFIX}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/sidplay/builders

BROKEN_powerpc64=	Does not build on powerpc64

PORTDOCS=	AUTHORS README COPYING NEWS

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	ID3TAG IPV6 ARCHIVE SAMPLERATE SQLITE3 \
		CDPARANOIA LAME MMS VORBISENC DOCS

OPTIONS_RADIO=	ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNSRESPONDER

OPTIONS_MULTI=	FILE_FORMAT
OPTIONS_MULTI_FILE_FORMAT=	AAC ADPLUG FFMPEG FLAC FLUIDSYNTH \
	   GME MAD MIKMOD MODPLUG MPG123 MUSEPACK \
	   OPUS SIDPLAY2 SNDFILE TREMOR TWOLAME \
	   VORBIS WAV WAVPACK WILDMIDI

OPTIONS_GROUP=	PLAYBACK
OPTIONS_GROUP_PLAYBACK=	AO CURL HTTPD JACK OPENAL OSS PIPE PULSEAUDIO SHOUTCAST

ADPLUG_DESC=	AdPlug support
GME_DESC=	GME support (video game music files)
LAME_DESC=	Support for MP3 Icecast Streams
PIPE_DESC=	Support for writing PCM audio to a pipe
SIDPLAY2_DESC=	Sidplay support (C64 mono and stereo files)
TREMOR_DESC=	Tremor decoder (not with SHOUTCAST; use VORBIS)
TWOLAME_DESC=	TwoLAME support (mp2)
VORBISENC_DESC=	Ogg Vorbis encoder
WILDMIDI_DESC=	WildMIDI support (MIDI files)

OPTIONS_DEFAULT=ID3TAG MAD OSS FLAC VORBIS WAV FFMPEG SNDFILE CURL

AAC_CONFIGURE_ENABLE=aac
AAC_LIB_DEPENDS=libfaad.so:audio/faad
ADPLUG_CONFIGURE_ENABLE=adplug
ADPLUG_LIB_DEPENDS=libadplug.so:audio/libadplug
AO_CONFIGURE_ENABLE=ao
AO_LIB_DEPENDS=libao.so:audio/libao
CDPARANOIA_CONFIGURE_ENABLE=cdio-paranoia
CDPARANOIA_LIB_DEPENDS=libcdda_paranoia.so:audio/cdparanoia
CURL_CONFIGURE_ENABLE=curl
CURL_LIB_DEPENDS=libcurl.so:ftp/curl
FFMPEG_CONFIGURE_ENABLE=ffmpeg
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavformat.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
FLAC_CONFIGURE_ENABLE=flac
FLAC_LIB_DEPENDS=libFLAC.so:audio/flac
FLUIDSYNTH_CONFIGURE_ENABLE=fluidsynth
FLUIDSYNTH_LIB_DEPENDS=libfluidsynth.so:audio/fluidsynth
GME_CONFIGURE_ENABLE=gme
GME_LIB_DEPENDS=libgme.so:audio/libgme
HTTPD_CONFIGURE_ENABLE=httpd-output
ID3TAG_CONFIGURE_ENABLE=id3
ID3TAG_LIB_DEPENDS=libid3tag.so:audio/libid3tag
IPV6_CONFIGURE_ENABLE=ipv6
JACK_CONFIGURE_ENABLE=jack
JACK_LIB_DEPENDS=libjack.so:audio/jack
LAME_CONFIGURE_ENABLE=lame-encoder
LAME_LIB_DEPENDS=libmp3lame.so:audio/lame
MAD_CONFIGURE_ENABLE=mad
MAD_LIB_DEPENDS=libmad.so:audio/libmad
MIKMOD_CONFIGURE_ENABLE=mikmod
MIKMOD_LIB_DEPENDS=libmikmod.so:audio/libmikmod
MMS_CONFIGURE_ENABLE=mms
MMS_LIB_DEPENDS=libmms.so:net/libmms
MODPLUG_CONFIGURE_ENABLE=modplug
MODPLUG_LIB_DEPENDS=libmodplug.so:audio/libmodplug
MPG123_CONFIGURE_ENABLE=mpg123
MPG123_LIB_DEPENDS=libmpg123.so:audio/mpg123
MUSEPACK_CONFIGURE_ENABLE=mpc
MUSEPACK_LIB_DEPENDS=libmpcdec.so:audio/musepack
OPENAL_CONFIGURE_ENABLE=openal
OPENAL_LIB_DEPENDS=libopenal.so:audio/openal
OPUS_CONFIGURE_ENABLE=opus
OPUS_LIB_DEPENDS=libopus.so:audio/opus
OSS_CONFIGURE_ENABLE=oss
PIPE_CONFIGURE_ENABLE=pipe-output
PULSEAUDIO_CONFIGURE_ENABLE=pulse
PULSEAUDIO_LIB_DEPENDS=libpulse.so:audio/pulseaudio
SAMPLERATE_CONFIGURE_ENABLE=lsr
SAMPLERATE_LIB_DEPENDS=libsamplerate.so:audio/libsamplerate
SIDPLAY2_CONFIGURE_ENABLE=sidplay
SIDPLAY2_LIB_DEPENDS=libsidplay2.so:audio/libsidplay2
SNDFILE_CONFIGURE_ENABLE=sndfile
SNDFILE_LIB_DEPENDS=libsndfile.so:audio/libsndfile
SQLITE3_CONFIGURE_ENABLE=sqlite
SQLITE3_LIB_DEPENDS=libsqlite3.so:databases/sqlite3
TREMOR_CONFIGURE_WITH=tremor
TREMOR_LIB_DEPENDS=libvorbisidec.so:audio/libtremor
TWOLAME_CONFIGURE_ENABLE=twolame-encoder
TWOLAME_LIB_DEPENDS=libtwolame.so:audio/twolame
VORBISENC_CONFIGURE_ENABLE=vorbis-encoder
VORBISENC_LIB_DEPENDS=libvorbisenc.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=vorbis
VORBIS_LIB_DEPENDS=libvorbis.so:audio/libvorbis
WAV_CONFIGURE_ENABLE=audiofile
WAV_LIB_DEPENDS=libaudiofile.so:audio/libaudiofile
WAVPACK_CONFIGURE_ENABLE=wavpack
WAVPACK_LIB_DEPENDS=libwavpack.so:audio/wavpack
WILDMIDI_CONFIGURE_ENABLE=wildmidi
WILDMIDI_LIB_DEPENDS=libWildMidi.so:audio/wildmidi

MPDUSER?=	mpd
MPDGROUP?=	mpd

USERS=	${MPDUSER}
GROUPS=	${MPDGROUP}

.include <bsd.port.options.mk>

.ifdef MPDCONF
IGNORE=Please remove the MPDCONF line from make.conf, then rename ${PREFIX}/etc/${MPDCONF} to musicpd.conf, if it exists
.endif

.if exists(${PREFIX}/etc/mpd.conf)
MSG=does not expect ${PREFIX}/etc/mpd.conf to exist.
.if !exists(${PREFIX}/etc/musicpd.conf)
IGNORE=${MSG}  Move it to ${PREFIX}/etc/musicpd.conf.
.else
IGNORE=${MSG}  You also have musicpd.conf-- check carefully to see which one you want, and remove mpd.conf.
.endif
.endif

.if ${PORT_OPTIONS:MARCHIVE}
CONFIGURE_ARGS+=--enable-bzip2 \
		--enable-zzip \
		--enable-iso9660
LIB_DEPENDS+=	libzzip.so:devel/zziplib \
		libcdio_paranoia.so:sysutils/libcdio-paranoia
.else
CONFIGURE_ARGS+=--disable-bzip2 \
		--disable-zzip \
		--disable-iso9660
.endif

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=--with-zeroconf=avahi
LIB_DEPENDS+=	libavahi-client.so:net/avahi-app
.else
CONFIGURE_ARGS+=--with-zeroconf=no
.endif

.if ${PORT_OPTIONS:MMDNSRESPONDER}
CONFIGURE_ARGS+=--with-zeroconf=bonjour
LIB_DEPENDS+=	libdns_sd.so:net/mDNSResponder
.else
CONFIGURE_ARGS+=--with-zeroconf=no
.endif

# libshout streaming support will be disabled by configure script when built
# also with tremor since the latter does not support vorbis encoding
.if ${PORT_OPTIONS:MSHOUTCAST}
.  if ${PORT_OPTIONS:MTREMOR}
IGNORE=		shoutcast and tremor do not coexist; use vorbis instead
.  endif
LIB_DEPENDS+=	libshout.so:audio/libshout
CONFIGURE_ARGS+=--enable-vorbis-encoder \
		--enable-shout
.else
CONFIGURE_ARGS+=--disable-shout
.endif

post-patch:
# Replace ~/ with /var/mpd and make musicpd run as mpd by default
	@${REINPLACE_CMD} -e 's,^#\([^"]*"\)~/,\1/var/mpd,g' \
		-e 's,^#\(user[^"]*"\)nobody,\1${MPDUSER},g' \
		${WRKSRC}/doc/mpdconf.example
# Uncomment OSS audio output part from MPDCONF; dragons!
	start=$$(expr $$(${SED} -n '/^#	type	*"oss"/=' \
		${WRKSRC}/doc/mpdconf.example) - 1); \
	 finish=$$(for n in $$(${JOT} 10 $$start); do \
		     [ "$$(${SED} -n $${n}p ${WRKSRC}/doc/mpdconf.example)" = \
				"#}" ] && echo $$n || true; done); \
	 ${REINPLACE_CMD} -e "$${start},$${finish}s,^#,," \
		${WRKSRC}/doc/mpdconf.example
# Fix man pages for executable names
	@${REINPLACE_CMD} -e 's/^\(\.B m\)pd/\1usicpd/' \
		-e 's#^\(\.BI \)/etc/mpd.conf#\1${PREFIX}/etc/${PORTNAME}.conf#' \
		-e 's#^mpd.conf#${PORTNAME}.conf#' \
		-e 's#^mpd(1)#musicpd(1)#' \
		${WRKSRC}/doc/mpd.1 ${WRKSRC}/doc/mpd.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpd \
		${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/doc/mpd.1 \
		${STAGEDIR}/${PREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_MAN} ${WRKSRC}/doc/mpd.conf.5 \
		${STAGEDIR}/${PREFIX}/man/man5/${PORTNAME}.conf.5
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}/${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/mpdconf.example \
		${STAGEDIR}/${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
