# New ports collection makefile for:	deadbeef
# Date created:		2010-01-17
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	deadbeef
PORTVERSION=	0.4.0
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/
#DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	DeaDBeeF is an audio player

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		mad.2:${PORTSDIR}/audio/libmad

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_ICONV=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-alsa --disable-nullout
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAGE=	yes

OPTIONS=	PULSE "PulseAudio output plugin (unsupported)" off\
		GUI "standard GTK2 user interface plugin" on\
		VFS "HTTP streaming vfs plugin" on\
		LASTFM "last.fm/libre.fm scrobbler plugin" on\
		ART "album art loader plugin" on\
		EQ "SuperEQ DSP plugin" on\
		SID "commodore64 SID music player plugin" on\
		FFAP "Monkey's Audio plugin" on\
		VTX "libayemy VTX ZX-Spectrum music player plugin" on\
		ADP "adplug plugin" on\
		HOTKEYS "global hotkeys plugin" on\
		OGG "Ogg Vorbis player plugin" on\
		FFMPEG "FFMPEG plugin for WMA, MPC, TTA, etc" on\
		FLAC "FLAC player plugin" on\
		SNDFILE "libsndfile plugin for PCM wave files" on\
		WAV "wavpack plugin" on\
		CDDA "CD-Audio plugin" on\
		GME "Game Music Emu plugin for NSF, AY, etc" on\
		DUMB "D.U.M.B. plugin for MOD, S3M and other" on\
		NOTIFY "support for OSD notifications into GTKUI plugin" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_PULSE)
CONFIGURE_ARGS+=	--disable-pulse
PLIST_SUB+=	PULSE="@comment "
.else
PLIST_SUB+=	PULSE=""
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.endif

.if defined(WITHOUT_GUI)
CONFIGURE_ARGS+=	--disable-gtkui
PLIST_SUB+=	GUI="@comment "
.else
PLIST_SUB+=	GUI=""
USE_GNOME=	gtk20 glib20
.endif

.if defined(WITHOUT_VFS)
CONFIGURE_ARGS+=	--disable-vfs-curl
PLIST_SUB+=	VFS="@comment "
.else
PLIST_SUB+=	VFS=""
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.endif

.if defined(WITHOUT_LASTFM)
CONFIGURE_ARGS+=	--disable-lfm
PLIST_SUB+=	LASTFM="@comment "
.else
PLIST_SUB+=	LASTFM=""
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.endif

.if defined(WITHOUT_ART)
CONFIGURE_ARGS+=	--disable-artwork
PLIST_SUB+=	ART="@comment "
.else
.if !defined(WITHOUT_VFS)
PLIST_SUB+=	ART=""
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.else
BROKEN=		Please enable VFS plugin
.endif
.endif

.if defined(WITHOUT_EQ)
CONFIGURE_ARGS+=	--disable-supereq
PLIST_SUB+=	EQ="@comment "
.else
PLIST_SUB+=	EQ=""
.endif

.if defined(WITHOUT_SID)
CONFIGURE_ARGS+=	--disable-sid
PLIST_SUB+=	SID="@comment "
.else
PLIST_SUB+=	SID=""
.endif

.if defined(WITHOUT_FFAP)
CONFIGURE_ARGS+=	--disable-ffap
PLIST_SUB+=	FFAP="@comment "
.else
PLIST_SUB+=	FFAP=""
.endif

.if defined(WITHOUT_VTX)
CONFIGURE_ARGS+=	--disable-vtx
PLIST_SUB+=	VTX="@comment "
.else
PLIST_SUB+=	VTX=""
.endif

.if defined(WITHOUT_ADP)
CONFIGURE_ARGS+=	--disable-adplug
PLIST_SUB+=	ADP="@comment "
.else
PLIST_SUB+=	ADP=""
.endif

.if defined(WITHOUT_HOTKEYS)
CONFIGURE_ARGS+=	--disable-hotkeys
PLIST_SUB+=	HOTKEYS="@comment "
.else
PLIST_SUB+=	HOTKEYS=""
.endif

.if defined(WITHOUT_OGG)
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	OGG="@comment "
.else
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	OGG=""
.endif

.if defined(WITHOUT_FFMPEG)
CONFIGURE_ARGS+=	--disable-ffmpeg
PLIST_SUB+=	FFMPEG="@comment "
.else
PLIST_SUB+=	FFMPEG=""
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		avformat:${PORTSDIR}/multimedia/ffmpeg \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg
.endif

.if defined(WITHOUT_FLAC)
CONFIGURE_ARGS+=	--disable-flac
PLIST_SUB+=	FLAC="@comment "
.else
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.endif

.if defined(WITHOUT_SNDFILE)
CONFIGURE_ARGS+=	--disable-sndfile
PLIST_SUB+=	SNDFILE="@comment "
.else
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
PLIST_SUB+=	SNDFILE=""
.endif

.if defined(WITHOUT_WAV)
CONFIGURE_ARGS+=	--disable-wavpack
PLIST_SUB+=	WAV="@comment "
.else
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WAV=""
.endif

.if defined(WITHOUT_CDDA)
CONFIGURE_ARGS+=	--disable-cdda
PLIST_SUB+=	CDDA="@comment "
.else
PLIST_SUB+=	CDDA=""
LIB_DEPENDS+=	cdio.12:${PORTSDIR}/sysutils/libcdio \
		cddb.4:${PORTSDIR}/audio/libcddb
.endif

.if defined(WITHOUT_GME)
CONFIGURE_ARGS+=	--disable-gme
PLIST_SUB+=	GME="@comment "
.else
PLIST_SUB+=	GME=""
.endif

.if defined(WITHOUT_DUMB)
CONFIGURE_ARGS+=	--disable-dumb
PLIST_SUB+=	DUMB="@comment "
.else
PLIST_SUB+=	DUMB=""
.endif

.if defined(WITHOUT_NOTIFY)
CONFIGURE_ARGS+=	--disable-notify
PLIST_SUB+=	NOTIFY="@comment "
.else
PLIST_SUB+=	NOTIFY=""
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.endif

.include <bsd.port.mk>
