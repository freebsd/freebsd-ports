# Created by: Revis Zinkov <rzinkov@gmail.com>
# $FreeBSD$

PORTNAME=	moc
PORTVERSION=	2.5.0
CATEGORIES=	audio
MASTER_SITES=	http://ftp.daper.net/pub/soft/moc/stable/

MAINTAINER=	rzinkov@gmail.com
COMMENT=	Console audio player designed to be powerful and easy to use

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:${PORTSDIR}/devel/libltdl

USES=		gmake libtool ncurses pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_BDB=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}

OPTIONS_DEFINE=	AAC CURL DEBUG FFMPEG FLAC JACK MODPLUG MP3 MUSEPACK RCC \
		SAMPLERATE SIDPLAY2 SNDFILE SPEEX VORBIS WAVPACK
OPTIONS_DEFAULT=	MP3 VORBIS FLAC CURL
CURL_DESC=	curl support (Internet streams)
RCC_DESC=	RCC support
SIDPLAY2_DESC=	libsidplay2 support

AAC_LIB_DEPENDS=	libfaad.so:${PORTSDIR}/audio/faad
AAC_PLIST_FILES=	lib/moc/decoder_plugins/libaac_decoder.so
AAC_CONFIGURE_OFF=	--without-aac

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_OFF=	--without-curl

DEBUG_CONFIGURE_OFF=	--enable-debug=no

FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_PLIST_FILES=	lib/moc/decoder_plugins/libffmpeg_decoder.so
FFMPEG_CONFIGURE_OFF=	--without-ffmpeg

FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_PLIST_FILES=	lib/moc/decoder_plugins/libflac_decoder.so
FLAC_CONFIGURE_OFF=	--without-flac

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_OFF=	--without-jack

MODPLUG_LIB_DEPENDS=	libmodplug.so:${PORTSDIR}/audio/libmodplug
MODPLUG_PLIST_FILES=	lib/moc/decoder_plugins/libmodplug_decoder.so
MODPLUG_CONFIGURE_OFF=	--without-modplug

MP3_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad \
			libid3tag.so:${PORTSDIR}/audio/libid3tag
MP3_PLIST_FILES=	lib/moc/decoder_plugins/libmp3_decoder.so
MP3_CONFIGURE_OFF=	--without-mp3

MUSEPACK_LIB_DEPENDS=	libmpcdec.so:${PORTSDIR}/audio/musepack \
			libtag_c.so:${PORTSDIR}/audio/taglib
MUSEPACK_PLIST_FILES=	lib/moc/decoder_plugins/libmusepack_decoder.so
MUSEPACK_CONFIGURE_OFF=	--without-musepack

RCC_LIB_DEPENDS=	librcc.so:${PORTSDIR}/devel/librcc \
			librcd.so:${PORTSDIR}/devel/librcd
RCC_CONFIGURE_OFF=	--without-rcc

SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
SAMPLERATE_CONFIGURE_OFF=	--without-samplerate

SIDPLAY2_LIB_DEPENDS=	libsidplay2.so:${PORTSDIR}/audio/libsidplay2
SIDPLAY2_PLIST_FILES=	lib/moc/decoder_plugins/libsidplay2_decoder.so
SIDPLAY2_CONFIGURE_OFF=	--without-sidplay2

SNDFILE_LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile
SNDFILE_PLIST_FILES=	lib/moc/decoder_plugins/libsndfile_decoder.so
SNDFILE_CONFIGURE_OFF=	--without-sndfile

SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_PLIST_FILES=	lib/moc/decoder_plugins/libspeex_decoder.so
SPEEX_CONFIGURE_OFF=	--without-speex

VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_PLIST_FILES=	lib/moc/decoder_plugins/libvorbis_decoder.so
VORBIS_CONFIGURE_OFF=	--without-ogg

WAVPACK_LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack
WAVPACK_PLIST_FILES=	lib/moc/decoder_plugins/libwavpack_decoder.so
WAVPACK_CONFIGURE_OFF=	--without-wavpack

post-patch:
	@${REINPLACE_CMD} -e '/PKG_CONFIG/ s|alsa|no-&|g' ${WRKSRC}/configure

.include <bsd.port.mk>
