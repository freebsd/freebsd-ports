PORTNAME=	moc
DISTVERSION=	2.5.2
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://ftp.daper.net/pub/soft/moc/stable/

MAINTAINER=	rzinkov@gmail.com
COMMENT=	Console audio player designed to be powerful and easy to use
WWW=		https://moc.daper.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		gmake iconv libtool localbase:ldflags ncurses pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-cache --without-ffmpeg --without-sidplay2

OPTIONS_DEFINE=	AAC CURL DEBUG FLAC JACK MODPLUG MP3 MUSEPACK RCC \
		SAMPLERATE SNDFILE SPEEX VORBIS WAVPACK
OPTIONS_DEFAULT=MP3 VORBIS FLAC CURL WAVPACK
CURL_DESC=	curl support (Internet streams)
RCC_DESC=	RCC support

AAC_LIB_DEPENDS=	libfaad.so:audio/faad
AAC_PLIST_FILES=	lib/moc/decoder_plugins/libaac_decoder.so
AAC_CONFIGURE_OFF=	--without-aac

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=	--without-curl

DEBUG_CONFIGURE_OFF=	--enable-debug=no

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_PLIST_FILES=	lib/moc/decoder_plugins/libflac_decoder.so
FLAC_CONFIGURE_OFF=	--without-flac

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--without-jack

MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_PLIST_FILES=	lib/moc/decoder_plugins/libmodplug_decoder.so
MODPLUG_CONFIGURE_OFF=	--without-modplug

MP3_LIB_DEPENDS=	libmad.so:audio/libmad \
			libid3tag.so:audio/libid3tag
MP3_PLIST_FILES=	lib/moc/decoder_plugins/libmp3_decoder.so
MP3_CONFIGURE_OFF=	--without-mp3

MUSEPACK_LIB_DEPENDS=	libmpcdec.so:audio/musepack \
			libtag_c.so:audio/taglib
MUSEPACK_PLIST_FILES=	lib/moc/decoder_plugins/libmusepack_decoder.so
MUSEPACK_CONFIGURE_OFF=	--without-musepack

RCC_LIB_DEPENDS=	librcc.so:devel/librcc \
			librcd.so:devel/librcd
RCC_CONFIGURE_OFF=	--without-rcc

SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_OFF=	--without-samplerate

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_PLIST_FILES=	lib/moc/decoder_plugins/libsndfile_decoder.so
SNDFILE_CONFIGURE_OFF=	--without-sndfile

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_PLIST_FILES=	lib/moc/decoder_plugins/libspeex_decoder.so
SPEEX_CONFIGURE_OFF=	--without-speex

VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
VORBIS_PLIST_FILES=	lib/moc/decoder_plugins/libvorbis_decoder.so
VORBIS_CONFIGURE_OFF=	--without-ogg

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_PLIST_FILES=	lib/moc/decoder_plugins/libwavpack_decoder.so
WAVPACK_CONFIGURE_OFF=	--without-wavpack

post-patch:
	@${REINPLACE_CMD} -e '/PKG_CONFIG/ s|alsa|no-&|g' ${WRKSRC}/configure

.include <bsd.port.mk>
