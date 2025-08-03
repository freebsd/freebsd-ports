PORTNAME=	musicpd
PORTVERSION=	0.24.5
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/mpd/${PORTVERSION:R}/
DISTNAME=	mpd-${PORTVERSION}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Remote-controllable music daemon
WWW=		https://www.musicpd.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libicudata.so:devel/icu

USES=		compiler:c++20-lang localbase:ldflags meson pkgconfig \
		python:build tar:xz

USE_RC_SUBR=	${PORTNAME}
MESON_ARGS=	--auto-features=disabled \
		-Dbzip2=enabled \
		-Dchromaprint=disabled \
		-Dhttpd=true \
		-Dicu=enabled \
		-Dmpcdec=disabled \
		-Doss=enabled \
		-Dpipe=true \
		-Dshine=disabled \
		-Dsyslog=enabled \
		-Dzlib=enabled

PORTDOCS=	AUTHORS README.md NEWS

SUB_FILES=	pkg-message

OPTIONS_SUB=	yes

OPTIONS_DEFINE=	DOCS ID3TAG IPV6 ISO9660 MANPAGES SQLITE3 \
		PROXYDB VORBISENC ZZIP

OPTIONS_RADIO=	RESAMPLER ZEROCONF

OPTIONS_RADIO_ZEROCONF=	AVAHI MDNSRESPONDER

OPTIONS_RADIO_RESAMPLER=	SAMPLERATE SOXR

OPTIONS_MULTI=	DOCUMENTATION FILE_FORMAT
OPTIONS_MULTI_FILE_FORMAT=	\
			ADPLUG AUDIOFILE FAAD FFMPEG FLAC FLUIDSYNTH \
			GME MAD MIKMOD MODPLUG MPG123 \
			OPUS SIDPLAY SNDFILE TWOLAME \
			VORBIS WAVPACK WILDMIDI

OPTIONS_GROUP=	ACCESS PLAYBACK

OPTIONS_GROUP_ACCESS=	CDPARANOIA CURL LAME NFS PLAYLISTS QOBUZ \
			SMB UPNP

OPTIONS_GROUP_PLAYBACK=	AO JACK OPENAL OPENMPT PIPEWIRE PULSEAUDIO \
			SHOUTCAST SNDIO

ADPLUG_DESC=	AdPlug support
FAAD_DESC=	AAC/MP4 decoding via libfaad
GME_DESC=	GME support (video game music files)
ISO9660_DESC=	Direct support for ISO 9660 images
PROXYDB_DESC=	Proxy database support via libmpdclient
LAME_DESC=	Support for MP3 Icecast Streams
OPENMPT_DESC=	Support for OpenMPT playback
PLAYLISTS_DESC=	Enable extra playlist support (wma, RSS)
QOBUZ_DESC=	Streaming service support: Qobuz
SIDPLAY_DESC=	Sidplay support (C64 mono and stereo files)
SMB_DESC=	SMB network support (currently strongly discouraged)
TWOLAME_DESC=	TwoLAME support (mp2)
VORBISENC_DESC=	Ogg Vorbis encoder
WILDMIDI_DESC=	WildMIDI support (MIDI files)
ZZIP_DESC=	Support for zzip archives

OPTIONS_DEFAULT=CURL FFMPEG FLAC ID3TAG LAME MANPAGES OPUS \
		PLAYLISTS PROXYDB SNDFILE VORBIS VORBISENC \
		WAVPACK

MANPAGES_MESON_ENABLED=	documentation
MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/bin/sphinx-build:textproc/py-sphinx@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

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
NFS_MESON_ENABLED=	nfs
NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
OPENMPT_MESON_ENABLED=	openmpt
OPENMPT_LIB_DEPENDS=	libopenmpt.so:audio/libopenmpt
OPUS_MESON_ENABLED=	opus
OPUS_LIB_DEPENDS=	libopus.so:audio/opus \
			libogg.so:audio/libogg
PLAYLISTS_MESON_ENABLED=expat
PLAYLISTS_LIB_DEPENDS=	libexpat.so:textproc/expat2
SIDPLAY_MESON_ENABLED=	sidplay
SIDPLAY_LIB_DEPENDS=	libsidplayfp.so:audio/libsidplayfp
SIDPLAY_CXXFLAGS=	-D_LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR
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
JACK_CXXFLAGS=		-Wno-register
OPENAL_MESON_ENABLED=	openal
OPENAL_USES=		openal
PIPEWIRE_MESON_ENABLED=	pipewire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
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
CURL_MESON_ENABLED=	curl webdav
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_IMPLIES=		PLAYLISTS
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
QOBUZ_MESON_ON=		-Dqobuz=enabled -Dnlohmann_json=enabled
QOBUZ_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
QOBUZ_BUILD_DEPENDS=	${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json
QOBUZ_IMPLIES=		CURL

# Misc library support
AVAHI_MESON_ON=		-Dzeroconf=avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
MDNSRESPONDER_MESON_ON=		-Dzeroconf=bonjour
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
UPNP_MESON_ON=		-Dupnp=npupnp
UPNP_LIB_DEPENDS=	libnpupnp.so:net/libnpupnp

MPDUSER?=	mpd
MPDGROUP?=	mpd

USERS=	${MPDUSER}
GROUPS=	${MPDGROUP}

post-patch:
# Make musicpd run as ${MPDUSER} by default
	@${REINPLACE_CMD} -e 's|%%MPDUSER%%|${MPDUSER}|' \
		${WRKSRC}/doc/mpdconf.example
# Fix man pages for executable names
	@${REINPLACE_CMD} \
		-e 's#^``mpd#``${PORTNAME}#' \
		-e 's#:: mpd#:: ${PORTNAME}#' \
		-e 's#mpd(1)#${PORTNAME}(1)#' \
		-e 's#mpd.conf(5)#${PORTNAME}.conf(5)#' \
		${WRKSRC}/doc/mpd.1.rst ${WRKSRC}/doc/mpd.conf.5.rst
	@${REINPLACE_CMD} \
		-e "s#'mpd'#'${PORTNAME}'#" \
		-e "s#'mpd.conf'#'${PORTNAME}.conf'#" \
		-e "s#'mpd.conf doc#'${PORTNAME}.conf doc#" \
		${WRKSRC}/doc/conf.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/mpd \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/mpdconf.example \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/_build/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/_build/doc/${PORTNAME}.conf.5 \
		${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
