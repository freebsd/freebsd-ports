# New ports collection makefile for:	Music Player Daemon
# Date created:				Thu Oct 02 2003
# Whom:					Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	musicpd
PORTVERSION=	0.14.2
PORTREVISION=	1
CATEGORIES=	audio ipv6
MASTER_SITES=	SF
DISTNAME=	mpd-${PORTVERSION}

MAINTAINER=	jo.lindqvist@gmail.com
COMMENT=	A remote-controllable music daemon

LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad

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

SUB_FILES=	pkg-message

OPTIONS=	FLAC		"Support FLAC audio format"		on \
		VORBIS		"Support OGG Vorbis audio format"	on \
		TREMOR		"Support Tremor (integer-only Vorbis)"	off \
		WAV		"Support WAV audio format"		on \
		AAC		"Support MP4/AAC audio format"		off \
		MUSEPACK	"Support MPC audio format"		off \
		MOD		"Support MOD audio format"		off \
		FFMPEG		"Support FFMPEG (wma aiff ac3 ape...)"	on \
	        ID3TAG		"Support ID3 v1/v2 tags"		on \
		IPV6		"Support IPv6 protocol"			on \
		AO		"Support libao audio library"		off \
		PULSEAUDIO	"Support PulseAudio sound server"	off \
		JACK		"Support JACK audio server"		off \
		SHOUTCAST	"Support for OGG Icecast and Shoutcast"	off \
		LAME		"Support for MP3 Icecast Streams"	off \
		SAMPLERATE	"Support sample rate conversion"	off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_FLAC)
CONFIGURE_ARGS+=--disable-flac \
		--disable-oggflac
.else
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-oggvorbis
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
CONFIGURE_ARGS+=--enable-shout-mp3
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=--disable-shout-mp3
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

.if defined(WITH_MOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=--disable-mod
.endif

.if defined(WITHOUT_FFMPEG)
CONFIGURE_ARGS+=--disable-ffmpeg
.else
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		avformat:${PORTSDIR}/multimedia/ffmpeg \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg
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
.else
CONFIGURE_ARGS+=--disable-shout-ogg
.endif

.if defined(WITHOUT_SAMPLERATE)
CONFIGURE_ARGS+=--disable-lsr
.else
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
.endif

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-docDATA||' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
