# $FreeBSD$

PORTNAME=	musicpd
PORTVERSION=	0.21.21
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/mpd/${PORTVERSION:R}/
DISTNAME=	mpd-${PORTVERSION}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Remote-controllable music daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libicudata.so:devel/icu

USES=		compiler:c++14-lang gnome meson pkgconfig tar:xz

USE_GNOME=	glib20

USE_RC_SUBR=	${PORTNAME}
MESON_ARGS=	-Dauto_features=disabled \
		-Dbzip2=enabled \
		-Dhttpd=true \
		-Dicu=enabled \
		-Doss=enabled \
		-Dpipe=true \
		-Dsyslog=enabled \
		-Dzlib=enabled
CFLAGS+=	-I${PREFIX}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS README.md NEWS

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS ID3TAG IPV6 ISO9660 SQLITE3 \
		PROXYDB LAME VORBISENC ZZIP

OPTIONS_RADIO=	RESAMPLER ZEROCONF

OPTIONS_RADIO_ZEROCONF=	AVAHI MDNSRESPONDER

OPTIONS_RADIO_RESAMPLER=	SAMPLERATE SOXR

OPTIONS_MULTI=	FILE_FORMAT
OPTIONS_MULTI_FILE_FORMAT=	\
			ADPLUG AUDIOFILE FAAD FFMPEG FLAC FLUIDSYNTH \
			GME MAD MIKMOD MODPLUG MPG123 MUSEPACK \
			OPUS SIDPLAY2 SNDFILE TWOLAME \
			VORBIS WAVPACK WILDMIDI

OPTIONS_GROUP=	ACCESS PLAYBACK

OPTIONS_GROUP_ACCESS=	CDPARANOIA CURL MMS NFS PLAYLISTS QOBUZ \
			SMB SOUNDCLOUD TIDAL YAJL

OPTIONS_GROUP_PLAYBACK=	AO JACK OPENAL PULSEAUDIO \
			SHOUTCAST SNDIO

ADPLUG_DESC=	AdPlug support
FAAD_DESC=	AAC/MP4 decoding via libfaad
GME_DESC=	GME support (video game music files)
ISO9660_DESC=	Direct support for ISO 9660 images
PROXYDB_DESC=	Proxy database support via libmpdclient
LAME_DESC=	Support for MP3 Icecast Streams
PLAYLISTS_DESC=	Enable extra playlist support (wma, RSS)
QOBUZ_DESC=	Streaming service support: Qobuz
SIDPLAY2_DESC=	Sidplay support (C64 mono and stereo files)
SOUNDCLOUD_DESC=Streaming service support: SoundCloud
TIDAL_DESC=	Streaming service support: TIDAL (currently defunct)
TWOLAME_DESC=	TwoLAME support (mp2)
VORBISENC_DESC=	Ogg Vorbis encoder
WILDMIDI_DESC=	WildMIDI support (MIDI files)
YAJL_DESC=	JSON support via libyajl
ZZIP_DESC=	Support for zzip archives

OPTIONS_DEFAULT=CURL FFMPEG FLAC ID3TAG \
		PLAYLISTS SNDFILE VORBIS VORBISENC

# Decoder plugins
ADPLUG_MESON_ENABLED=	adplug
ADPLUG_LIB_DEPENDS=	libadplug.so:audio/libadplug
AUDIOFILE_MESON_ENABLED=audiofile
AUDIOFILE_LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile
FAAD_MESON_ENABLED=	faad
FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FFMPEG_MESON_ENABLED=	ffmpeg
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavformat.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
FLAC_MESON_ENABLED=	flac
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLUIDSYNTH_MESON_ENABLED=	fluidsynth
FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
GME_MESON_ENABLED=	gme
GME_LIB_DEPENDS=	libgme.so:audio/libgme
MAD_MESON_ENABLED=	mad
MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MIKMOD_MESON_ENABLED=	mikmod
MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod
MODPLUG_MESON_ENABLED=	modplug
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MPG123_MESON_ENABLED=	mpg123
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MUSEPACK_MESON_ENABLED=	mpcdec
MUSEPACK_LIB_DEPENDS=	libmpcdec.so:audio/musepack
NFS_MESON_ENABLED=	nfs
NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
OPUS_MESON_ENABLED=	opus
OPUS_LIB_DEPENDS=	libopus.so:audio/opus \
			libogg.so:audio/libogg
PLAYLISTS_MESON_ENABLED=expat
PLAYLISTS_LIB_DEPENDS=	libexpat.so:textproc/expat2
SIDPLAY2_MESON_ENABLED=	sidplay
SIDPLAY2_LIB_DEPENDS=	libsidplay2.so:audio/libsidplay2
SIDPLAY2_LDFLAGS=	-L${LOCALBASE}/lib/sidplay/builders
SNDFILE_MESON_ENABLED=	sndfile
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
VORBIS_MESON_ENABLED=	vorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
WAVPACK_MESON_ENABLED=	wavpack
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WILDMIDI_MESON_ENABLED=	wildmidi
WILDMIDI_LIB_DEPENDS=	libWildMidi.so:audio/wildmidi

# Encoder plugins
VORBISENC_IMPLIES=	VORBIS
VORBISENC_MESON_ENABLED=	vorbisenc
VORBISENC_LIB_DEPENDS=	libvorbisenc.so:audio/libvorbis
LAME_MESON_ENABLED=	lame
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
TWOLAME_MESON_ENABLED=	twolame
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame

# Filter plugins
SAMPLERATE_MESON_ENABLED=	libsamplerate
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SOXR_MESON_ENABLED=	soxr
SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr

# Output plugins
AO_MESON_ENABLED=	ao
AO_LIB_DEPENDS=		libao.so:audio/libao
JACK_MESON_ENABLED=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack
OPENAL_MESON_ENABLED=	openal
OPENAL_USES=		openal
PULSEAUDIO_MESON_ENABLED=	pulse
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
SHOUTCAST_MESON_ENABLED=shout
SHOUTCAST_LIB_DEPENDS=	libshout.so:audio/libshout
SHOUTCAST_IMPLIES=	VORBIS
SNDIO_MESON_ENABLED=	sndio
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

# Input plugins
CDPARANOIA_MESON_ENABLED=	cdio_paranoia
CDPARANOIA_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia
CURL_MESON_ENABLED=	curl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
MMS_MESON_ENABLED=	mms
MMS_LIB_DEPENDS=	libmms.so:net/libmms
SMB_MESON_ENABLED=	smbclient
SMB_USES=		samba:lib

# Archive plugins
ZZIP_MESON_ENABLED=	zzip
ZZIP_LIB_DEPENDS=	libzzip.so:devel/zziplib
ISO9660_MESON_ENABLED=	iso9660
ISO9660_LIB_DEPENDS=	libiso9660.so:sysutils/libcdio

# Database plugins
SQLITE3_MESON_ENABLED=	sqlite
SQLITE3_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
PROXYDB_MESON_ENABLED=	libmpdclient
PROXYDB_LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

# Tag plugins
ID3TAG_MESON_ENABLED=	id3tag
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

# Network support
IPV6_MESON_ENABLED=	ipv6

# Commercial service support
QOBUZ_MESON_ENABLED=	qobuz
QOBUZ_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
QOBUZ_IMPLIES=		CURL YAJL
SOUNDCLOUD_MESON_ENABLED=	soundcloud
SOUNDCLOUD_IMPLIES=	CURL YAJL
TIDAL_MESON_ENABLED=	tidal
TIDAL_IMPLIES=		CURL YAJL

# Misc library suppore
AVAHI_MESON_ON=		-Dzeroconf=avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
MDNSRESPONDER_MESON_ON=		-Dzeroconf=bonjour
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
YAJL_MESON_ENABLED=	yajl
YAJL_LIB_DEPENDS=	libyajl.so:devel/yajl

MPDUSER?=	mpd
MPDGROUP?=	mpd

USERS=	${MPDUSER}
GROUPS=	${MPDGROUP}

.include <bsd.port.pre.mk>

# Note that since the build system switch to meson, mpd fails to link with
# GNU ld 2.17 in base. Also, meson does not allow to set the linker via
# environment variables yet.
# For gcc-based platforms, gcc and ld from ports are used due to the c++14
# requirement. For clang, we set the linker explicitly in meson.build.
.if ${ARCH} == armv6
#lld may use movt/movw, doesn't work on armv6
BUILD_DEPENDS+=	${LOCALBASE}/bin/ld:devel/binutils
MPD_CLANG_LD=	${LOCALBASE}/bin/ld
.else
MPD_CLANG_LD=	lld
.endif

post-patch:
# Insert selected linker for clang
	@${REINPLACE_CMD} -e 's|%%MPD_CLANG_LD%%|${MPD_CLANG_LD}|' \
		${WRKSRC}/meson.build
# Replace ~/ with /var/mpd/ and make musicpd run as mpd by default
	@${REINPLACE_CMD} -e 's,^#\([^"]*"\)~/,\1/var/mpd/,g' \
		-e 's,^#\(user[^"]*"\)nobody,\1${MPDUSER},g' \
		${WRKSRC}/doc/mpdconf.example
# Uncomment OSS audio output part from mpd.conf; dragons!
	start=$$(expr $$(${SED} -n '/^#	type	*"oss"/=' \
		${WRKSRC}/doc/mpdconf.example) - 1); \
	 finish=$$(for n in $$(${JOT} 10 $$start); do \
		     [ "$$(${SED} -n $${n}p ${WRKSRC}/doc/mpdconf.example)" = \
				"#}" ] && ${ECHO_CMD} $$n || true; done); \
	 ${REINPLACE_CMD} -e "$${start},$${finish}s,^#,," \
		${WRKSRC}/doc/mpdconf.example
# Fix man pages for executable names
	@${REINPLACE_CMD} -e 's/^\(\.B m\)pd/\1usicpd/' \
		-e 's#^\(\.BI \)/etc/mpd.conf#\1${PREFIX}/etc/${PORTNAME}.conf#' \
		-e 's#^mpd.conf#${PORTNAME}.conf#' \
		-e 's#^mpd(1)#musicpd(1)#' \
		${WRKSRC}/doc/mpd.1 ${WRKSRC}/doc/mpd.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/mpd \
		${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/doc/mpd.1 \
		${STAGEDIR}/${PREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_MAN} ${WRKSRC}/doc/mpd.conf.5 \
		${STAGEDIR}/${PREFIX}/man/man5/${PORTNAME}.conf.5
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/mpdconf.example \
		${STAGEDIR}/${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.post.mk>
