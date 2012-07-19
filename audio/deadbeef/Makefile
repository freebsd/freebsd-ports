# New ports collection makefile for:	deadbeef
# Date created:		2010-01-17
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	deadbeef
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Ultimate music player for Unix-like systems

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate \
		mad:${PORTSDIR}/audio/libmad \
		execinfo:${PORTSDIR}/devel/libexecinfo

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_ICONV=	yes
CONFIGURE_ARGS=	--disable-alsa --disable-nullout \
		CPPFLAGS="-I../dumb/dumb-kode54/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-lexecinfo -lintl"
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes
SH=		${LOCALBASE}/bin/bash # Hack for detecting depends

OPTIONS=	PULSE "PulseAudio output plugin (unsupported)" off\
		GUI "standard GTK2 user interface plugin" on\
		VFS "HTTP streaming vfs plugin" on\
		LASTFM "last.fm/libre.fm scrobbler plugin" on\
		ART "album art loader plugin" on\
		EQ "SuperEQ DSP plugin" on\
		SID "SID music player plugin" on\
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
		GME "Game Music Emu plugin" on\
		DUMB "D.U.M.B. plugin for MOD, S3M and other" on\
		NOTIFY "support for OSD notifications into GTKUI plugin" on\
		MUSEPACK "musepack plugin" on\
		WILD "wildmidi plugin" on\
		TTA "tta plugin" on\
		DCA "dca (DTS audio) plugin" on\
		AAC "AAC decoder based on FAAD2" on\
		MMS "MMS streaming vfs plugin" on\
		SHN "shorten plugin" on\
		AO "audio overload plugin" on\
		SHELLEXEC "shell commands plugin" on\
		NLS "Native Language Support" on\
		M3U "m3u plugin" on\
		PSF "AOSDK-based PSF(,QSF,SSF,DSF) plugin" on\
		DSP "libsamplerate (SRC) plugin" on\
		MONO2STEREO "mono2stereo DSP plugin" on\
		CONVERTER "Build converter" on\
		VFS_ZIP "ZIP support" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_PULSE)
CONFIGURE_ARGS+=	--disable-pulse
PLIST_SUB+=	PULSE="@comment "
.else
PLIST_SUB+=	PULSE=""
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
.endif

.if defined(WITHOUT_GUI)
CONFIGURE_ARGS+=	--disable-gtkui
CONFIGURE_ARGS+=	--disable-gtk3
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
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.endif

.if defined(WITHOUT_LASTFM)
CONFIGURE_ARGS+=	--disable-lfm
PLIST_SUB+=	LASTFM="@comment "
.else
PLIST_SUB+=	LASTFM=""
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.endif

.if defined(WITHOUT_ART)
CONFIGURE_ARGS+=	--disable-artwork
PLIST_SUB+=	ART="@comment "
.else
.if !defined(WITHOUT_VFS)
CONFIGURE_ARTS+=	--disable-artwork-imlib2
PLIST_SUB+=	ART=""
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl \
		jpeg:${PORTSDIR}/graphics/jpeg
.else
BROKEN=		VFS plugin required for album art loader, please rerun 'make config' and either disable ART or enable VFS
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
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
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
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	OGG=""
.endif

.if defined(WITHOUT_FFMPEG)
CONFIGURE_ARGS+=	--disable-ffmpeg
PLIST_SUB+=	FFMPEG="@comment "
.else
PLIST_SUB+=	FFMPEG=""
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg \
		avformat:${PORTSDIR}/multimedia/ffmpeg \
		avutil:${PORTSDIR}/multimedia/ffmpeg
.endif

.if defined(WITHOUT_FLAC)
CONFIGURE_ARGS+=	--disable-flac
PLIST_SUB+=	FLAC="@comment "
.else
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.endif

.if defined(WITHOUT_SNDFILE)
CONFIGURE_ARGS+=	--disable-sndfile
PLIST_SUB+=	SNDFILE="@comment "
.else
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
PLIST_SUB+=	SNDFILE=""
.endif

.if defined(WITHOUT_WAV)
CONFIGURE_ARGS+=	--disable-wavpack
PLIST_SUB+=	WAV="@comment "
.else
LIB_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WAV=""
.endif

.if defined(WITHOUT_CDDA)
CONFIGURE_ARGS+=	--disable-cdda
PLIST_SUB+=	CDDA="@comment "
.else
PLIST_SUB+=	CDDA=""
LIB_DEPENDS+=	cdio:${PORTSDIR}/sysutils/libcdio \
		cddb:${PORTSDIR}/audio/libcddb
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
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
.endif

.if defined(WITHOUT_MUSEPACK)
CONFIGURE_ARGS+=	--disable-musepack
PLIST_SUB+=	MUSEPACK="@comment "
.else
PLIST_SUB+=	MUSEPACK=""
.endif

.if defined(WITHOUT_WILD)
CONFIGURE_ARGS+=	--disable-wildmidi
PLIST_SUB+=	WILD="@comment "
.else
RUN_DEPENDS+=	${LOCALBASE}/share/freepats/crude.cfg:${PORTSDIR}/audio/freepats
PLIST_SUB+=	WILD=""
.endif

.if defined(WITHOUT_TTA)
CONFIGURE_ARGS+=	--disable-tta
PLIST_SUB+=	TTA="@comment "
.else
PLIST_SUB+=	TTA=""
.endif

.if defined(WITHOUT_DCA)
CONFIGURE_ARGS+=	--disable-dca
PLIST_SUB+=	DCA="@comment "
.else
PLIST_SUB+=	DCA=""
.endif

.if defined(WITHOUT_AAC)
CONFIGURE_ARGS+=	--disable-aac
PLIST_SUB+=	AAC="@comment "
.else
PLIST_SUB+=	AAC=""
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad
.endif

.if defined(WITHOUT_MMS)
CONFIGURE_ARGS+=	--disable-mms
PLIST_SUB+=	MMS="@comment "
.else
PLIST_SUB+=	MMS=""
.endif

.if defined(WITHOUT_SHN)
CONFIGURE_ARGS+=	--disable-shn
PLIST_SUB+=	SHN="@comment "
.else
PLIST_SUB+=	SHN=""
.endif

.if defined(WITHOUT_AO)
CONFIGURE_ARGS+=	--disable-ao
PLIST_SUB+=	AO="@comment "
.else
PLIST_SUB+=	AO=""
.endif

.if defined(WITHOUT_SHELLEXEC)
CONFIGURE_ARGS+=	--disable-shellexec
PLIST_SUB+=	SHELLEXEC="@comment "
.else
PLIST_SUB+=	SHELLEXEC=""
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.if defined(WITHOUT_CONVERTER)
CONFIGURE_ARGS+=	--disable-converter
PLIST_SUB+=	CONVERTER="@comment "
.else
.if !defined(WITHOUT_GUI)
PLIST_SUB+=	CONVERTER=""
USE_GNOME=	gtk20 glib20
.else
BROKEN=		CONVERTER plugin required for gui, please rerun 'make config' and either disable CONVERTER or enable GUI
.endif
.endif

.if defined(WITHOUT_M3U)
CONFIGURE_ARGS+=	--disable-m3u
PLIST_SUB+=	M3U="@comment "
.else
PLIST_SUB+=	M3U=""
.endif

.if defined(WITHOUT_PSF)
CONFIGURE_ARGS+=	--disable-psf
PLIST_SUB+=	PSF="@comment "
.else
PLIST_SUB+=	PSF=""
.endif

.if defined(WITHOUT_DSP)
CONFIGURE_ARGS+=	--disable-src
PLIST_SUB+=	DSP="@comment "
.else
PLIST_SUB+=	DSP=""
LIB_DEPENDS+=	samplerate:${PORTSDIR}/audio/libsamplerate
.endif

.if defined(WITHOUT_MONO2STEREO)
CONFIGURE_ARGS+=	--disable-mono2stereo
PLIST_SUB+=	MONO2STEREO="@comment "
.else
PLIST_SUB+=	MONO2STEREO=""
.endif

.if defined(WITHOUT_VFS_ZIP)
CONFIGURE_ARGS+=	--disable-vfs-zip
PLIST_SUB+=	VFS_ZIP="@comment "
.else
PLIST_SUB+=	VFS_ZIP=""
LIB_DEPENDS+=	zip:${PORTSDIR}/archivers/libzip
.endif

post-patch:
# Do not link to libsupc++ which may be PIC-unsafe (breaks 64-bit arches)
	@${REINPLACE_CMD} -e 's, -lsupc++,,' \
		${WRKSRC}/plugins/adplug/Makefile.in \
		${WRKSRC}/plugins/gme/Makefile.in \
		${WRKSRC}/plugins/sid/Makefile.in \
		${WRKSRC}/plugins/supereq/Makefile.in
	@${REINPLACE_CMD} -e 's,/bin/bash,${LOCALBASE}/bin/bash,' \
		${WRKSRC}/yasmwrapper.sh
	@${REINPLACE_CMD} -e 's,/etc/timidity++/timidity-freepats.cfg:/etc/timidity/freepats.cfg:/etc/timidity/,${LOCALBASE}/share/,' \
		${WRKSRC}/plugins/wildmidi/wildmidiplug.c

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not build on powerpc-9: fails to compile
.endif

.include <bsd.port.post.mk>
