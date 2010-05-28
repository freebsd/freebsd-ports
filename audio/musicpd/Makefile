# New ports collection makefile for:	Music Player Daemon
# Date created:				Thu Oct 02 2003
# Whom:					Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	musicpd
PORTVERSION=	0.15.8
PORTREVISION=	2
CATEGORIES=	audio ipv6
MASTER_SITES=	SF/${PORTNAME}/mpd/${PORTVERSION}
DISTNAME=	mpd-${PORTVERSION}

MAINTAINER=	jo.lindqvist@gmail.com
COMMENT=	A remote-controllable music daemon

LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad \
		curl.6:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

USE_RC_SUBR=	${PORTNAME}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CFLAGS+=	-I${PREFIX}/include

MAN1=		mpd.1
MAN5=		mpd.conf.5

DOCSDIR=	${PREFIX}/share/doc/mpd
PORTDOCS=	mpdconf.example AUTHORS README COPYING NEWS UPGRADING

SUB_FILES=	pkg-message

OPTIONS=	ID3TAG          "Support ID3 v1/v2 tags"                on \
		IPV6            "Support IPv6 protocol"                 on \
		FLAC            "Support FLAC audio format"             on \
		VORBIS          "Support OGG Vorbis audio format"       on \
		WAV             "Support WAV audio format"              on \
		FFMPEG          "Support FFMPEG (wma aiff ac3 ape...)"  on \
		TREMOR		"Support Tremor (integer-only Vorbis)"	off \
		AAC		"Support MP4/AAC audio format"		off \
		MUSEPACK	"Support MPC audio format"		off \
		MIKMOD		"Support MOD audio format"		off \
		MODPLUG		"Support MODPLUG decoder"		off \
		ARCHIVE		"Support bzip2/zip/iso9660 archive"	off \
		MMS             "Support MMS stream input"              off \
		LASTFM		"Support Last.FM stream input (experimental)"	off \
		AO		"Support libao audio library"		off \
		PULSEAUDIO	"Support PulseAudio sound server"	off \
		JACK		"Support JACK audio server"		off \
		SHOUTCAST	"Support for OGG Icecast and Shoutcast"	off \
		LAME		"Support for MP3 Icecast Streams"	off \
		HTTPD		"Support for httpd output streaming"	off \
		SAMPLERATE	"Support sample rate conversion"	off

MPDDIR=	var/mpd
MPDUSER=	mpd
MPDGROUP=	mpd

USERS=	${MPDUSER}
GROUPS=	${MPDGROUP}

MPDUID=	137
MPDGID=	137

PLIST_SUB=	MPDUSER=${MPDUSER} \
		MPDGROUP=${MPDGROUP}

SUB_LIST+=	MPDUSER=${MPDUSER} \
		MPDGROUP=${MPDGROUP} \
		MPDDIR=${PREFIX}/${MPDDIR} \
		MPDUID=${MPDUID} \
		MPDGID=${MPDGID}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_FLAC)
CONFIGURE_ARGS+=--disable-flac \
		--disable-oggflac
.else
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-vorbis
.else
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_TREMOR)
CONFIGURE_ARGS+=--with-tremor
LIB_DEPENDS+=	vorbisidec.1:${PORTSDIR}/audio/libtremor
.endif

.if defined(WITH_AAC)
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=--disable-aac
.endif

.if defined(WITH_LAME)
CONFIGURE_ARGS+=--enable-lame-encoder
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=--disable-lame-encoder
.endif

.if defined(WITH_HTTPD)
CONFIGURE_ARGS+=--enable-httpd-output
.else
CONFIGURE_ARGS+=--disable-httpd-output
.endif

.if defined(WITHOUT_WAV)
CONFIGURE_ARGS+=--disable-audiofile
.else
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
.endif

.if defined(WITH_MUSEPACK)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
.else
CONFIGURE_ARGS+=--disable-mpc
.endif

.if defined(WITH_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
CONFIGURE_ARGS+=--enable-mikmod
.else
CONFIGURE_ARGS+=--disable-mikmod
.endif

.if defined(WITH_MODPLUG)
LIB_DEPENDS+=	modplug.1:${PORTSDIR}/audio/libmodplug
CONFIGURE_ARGS+=--enable-modplug
.else
CONFIGURE_ARGS+=--disable-modplug
.endif

.if defined(WITH_ARCHIVE)
CONFIGURE_ARGS+=--enable-bzip2 \
		--enable-zip \
		--enable-iso9660
LIB_DEPENDS+=	zzip.13:${PORTSDIR}/devel/zziplib \
		iso9660.7:${PORTSDIR}/sysutils/libcdio
.endif

.if defined(WITHOUT_FFMPEG)
CONFIGURE_ARGS+=--disable-ffmpeg
.else
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		avformat:${PORTSDIR}/multimedia/ffmpeg \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg
.endif

.if defined(WITH_LASTFM)
CONFIGURE_ARGS+=--enable-lastfm
.else
CONFIGURE_ARGS+=--disable-lastfm
.endif

.if defined(WITH_MMS)
CONFIGURE_ARGS+=--enable-mms
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
.else
CONFIGURE_ARGS+=--disable-mms
.endif

.if defined(WITHOUT_ID3TAG)
CONFIGURE_ARGS+=--disable-id3
.else
LIB_DEPENDS+=	id3tag.0:${PORTSDIR}/audio/libid3tag
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if defined(WITH_AO)
CONFIGURE_ARGS+=--enable-ao
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
.else
CONFIGURE_ARGS+=--disable-ao
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=--disable-pulse
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=--disable-jack
.endif

# libshout streaming support will be disabled by configure script when built
# also with tremor since the latter does not support vorbis encoding
.if defined(WITH_SHOUTCAST) && !defined(WITH_TREMOR)
LIB_DEPENDS+=	shout.5:${PORTSDIR}/audio/libshout2
CONFIGURE_ARGS+=--enable-vorbis-encoder \
		--enable-shout
.else
CONFIGURE_ARGS+=--disable-shout
.endif

.if defined(WITHOUT_SAMPLERATE)
CONFIGURE_ARGS+=--disable-lsr
.else
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-lsr
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/%%MPDDIR%%/${PREFIX:C/\//\\\//g}\/${MPDDIR:C/\//\\\//g}/g" -e "s/%%MPDUSER%%/${MPDUSER}/g" \
		${WRKSRC}/doc/mpdconf.example
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|install-docDATA ||' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${MKDIR} ${PREFIX}/${MPDDIR}
	@${CHOWN} -R ${MPDUSER}:${MPDGROUP} ${PREFIX}/${MPDDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
