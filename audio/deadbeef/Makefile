# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef
PORTVERSION=	0.5.5
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Ultimate music player for Unix-like systems

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate \
		mad:${PORTSDIR}/audio/libmad \
		execinfo:${PORTSDIR}/devel/libexecinfo

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig gettext iconv shebangfix
USE_LDCONFIG=	yes
USE_BZIP2=	yes
CONFIGURE_ARGS=	--disable-alsa --disable-nullout \
		CPPFLAGS="-I../dumb/dumb-kode54/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-lexecinfo -lintl"
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	CONFIG_SHELL="${LOCALBASE}/bin/bash"
SHEBANG_FILES=	yasmwrapper.sh

OPTIONS_DEFINE=	PULSEAUDIO GUI VFS LASTFM ART EQ SID FFAP VTX HOTKEYS OGG FFMPEG \
		FLAC SNDFILE WAV CDDA GME DUMB NOTIFY MUSEPACK WILD TTA DCA AAC \
		MMS SHN AO SHELLEXEC NLS M3U PSF ADP DSP MONO2STEREO CONVERTER VFS_ZIP
OPTIONS_DEFAULT=	GUI VFS LASTFM ART EQ SID FFAP VTX HOSTKEYS OGG FFMPEG \
			FLAC SNDFILE WAV CDDA GME DUMB NOTIFY MUSEPACK WILD TTA DCA \
			AAC MMS SHN AO SHELLEXEC M3U PSF ADP DSP MONO2STEREO CONVERTER VFS_ZIP \
			HOtKEYS
PULSEAUDIO_DESC=	PulseAudio output plugin (unsupported)
GUI_DESC=		standard GTK2 user interface plugin
VFS_DESC=		HTTP streaming vfs plugin
LASTFM_DESC=		last.fm/libre.fm scrobbler plugin
ART_DESC=		album art loader plugin
EQ_DESC=		SuperEQ DSP plugin
SID_DESC=		SID music player plugin
FFAP_DESC=		Monkey's Audio plugin
VTX_DESC=		libayemy VTX ZX-Spectrum music player plugin
ADP_DESC=		adplug plugin
HOTKEYS_DESC=		global hotkeys plugin
CDDA_DESC=		CD-Audio plugin
GME_DESC=		Game Music Emu plugin
DUMB_DESC=		D.U.M.B. plugin for MOD, S3M and other
NOTIFY_DESC=		support for OSD notifications into GTKUI plugin
WILD_DESC=		wildmidi plugin
TTA_DESC=		tta plugin
SHN_DESC=		shorten plugin
AO_DESC=		audio overload plugin
SHELLEXEC_DESC=		shell commands plugin
M3U_DESC=		m3u plugin
PSF_DESC=		AOSDK-based PSF(,QSF,SSF,DSF) plugin
DSP_DESC=		libsamplerate (SRC) plugin
MONO2STEREO_DESC=	mono2stereo DSP plugin
CONVERTER_DESC=		Build converter
VFS_ZIP_DESC=		ZIP support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
PLIST_SUB+=	PULSE=""
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulse
PLIST_SUB+=	PULSE="@comment "
.endif

.if ${PORT_OPTIONS:MGUI}
PLIST_SUB+=	GUI=""
USE_GNOME=	gtk20 glib20
.else
CONFIGURE_ARGS+=	--disable-gtkui
CONFIGURE_ARGS+=	--disable-gtk3
PLIST_SUB+=	GUI="@comment "
.endif

.if ${PORT_OPTIONS:MVFS}
PLIST_SUB+=	VFS=""
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--disable-vfs-curl
PLIST_SUB+=	VFS="@comment "
.endif

.if ${PORT_OPTIONS:MLASTFM}
PLIST_SUB+=	LASTFM=""
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--disable-lfm
PLIST_SUB+=	LASTFM="@comment "
.endif

.if ${PORT_OPTIONS:MART}
.if ${PORT_OPTIONS:MVFS}
CONFIGURE_ARTS+=	--disable-artwork-imlib2
PLIST_SUB+=	ART=""
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl \
		jpeg:${PORTSDIR}/graphics/jpeg
.else
BROKEN=		VFS plugin required for album art loader, please rerun 'make config' and either disable ART or enable VFS
.endif
.else
CONFIGURE_ARGS+=	--disable-artwork
PLIST_SUB+=	ART="@comment "
.endif

.if ${PORT_OPTIONS:MEQ}
PLIST_SUB+=	EQ=""
.else
CONFIGURE_ARGS+=	--disable-supereq
PLIST_SUB+=	EQ="@comment "
.endif

.if ${PORT_OPTIONS:MSID}
PLIST_SUB+=	SID=""
.else
CONFIGURE_ARGS+=	--disable-sid
PLIST_SUB+=	SID="@comment "
.endif

.if ${PORT_OPTIONS:MFFAP}
PLIST_SUB+=	FFAP=""
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
.else
CONFIGURE_ARGS+=	--disable-ffap
PLIST_SUB+=	FFAP="@comment "
.endif

.if ${PORT_OPTIONS:MVTX}
PLIST_SUB+=	VTX=""
.else
CONFIGURE_ARGS+=	--disable-vtx
PLIST_SUB+=	VTX="@comment "
.endif

.if ${PORT_OPTIONS:MADP}
PLIST_SUB+=	ADP=""
.else
CONFIGURE_ARGS+=	--disable-adplug
PLIST_SUB+=	ADP="@comment "
.endif

.if ${PORT_OPTIONS:MHOTKEYS}
PLIST_SUB+=	HOTKEYS=""
.else
CONFIGURE_ARGS+=	--disable-hotkeys
PLIST_SUB+=	HOTKEYS="@comment "
.endif

.if ${PORT_OPTIONS:MOGG}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	OGG=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	OGG="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
PLIST_SUB+=	FFMPEG=""
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg \
		avformat:${PORTSDIR}/multimedia/ffmpeg \
		avutil:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
CONFIGURE_ARGS+=	--disable-flac
PLIST_SUB+=	FLAC="@comment "
.endif

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
PLIST_SUB+=	SNDFILE=""
.else
CONFIGURE_ARGS+=	--disable-sndfile
PLIST_SUB+=	SNDFILE="@comment "
.endif

.if ${PORT_OPTIONS:MWAV}
LIB_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WAV=""
.else
CONFIGURE_ARGS+=	--disable-wavpack
PLIST_SUB+=	WAV="@comment "
.endif

.if ${PORT_OPTIONS:MCDDA}
PLIST_SUB+=	CDDA=""
LIB_DEPENDS+=	cdio:${PORTSDIR}/sysutils/libcdio \
		cddb:${PORTSDIR}/audio/libcddb
.else
CONFIGURE_ARGS+=	--disable-cdda
PLIST_SUB+=	CDDA="@comment "
.endif

.if ${PORT_OPTIONS:MGME}
PLIST_SUB+=	GME=""
.else
CONFIGURE_ARGS+=	--disable-gme
PLIST_SUB+=	GME="@comment "
.endif

.if ${PORT_OPTIONS:MDUMB}
PLIST_SUB+=	DUMB=""
.else
CONFIGURE_ARGS+=	--disable-dumb
PLIST_SUB+=	DUMB="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
PLIST_SUB+=	NOTIFY=""
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
.else
CONFIGURE_ARGS+=	--disable-notify
PLIST_SUB+=	NOTIFY="@comment "
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
PLIST_SUB+=	MUSEPACK=""
.else
CONFIGURE_ARGS+=	--disable-musepack
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if ${PORT_OPTIONS:MWILD}
RUN_DEPENDS+=	${LOCALBASE}/share/freepats/crude.cfg:${PORTSDIR}/audio/freepats
PLIST_SUB+=	WILD=""
.else
CONFIGURE_ARGS+=	--disable-wildmidi
PLIST_SUB+=	WILD="@comment "
.endif

.if ${PORT_OPTIONS:MTTA}
PLIST_SUB+=	TTA=""
.else
CONFIGURE_ARGS+=	--disable-tta
PLIST_SUB+=	TTA="@comment "
.endif

.if ${PORT_OPTIONS:MDCA}
PLIST_SUB+=	DCA=""
.else
CONFIGURE_ARGS+=	--disable-dca
PLIST_SUB+=	DCA="@comment "
.endif

.if ${PORT_OPTIONS:MAAC}
PLIST_SUB+=	AAC=""
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=	--disable-aac
PLIST_SUB+=	AAC="@comment "
.endif

.if ${PORT_OPTIONS:MMMS}
PLIST_SUB+=	MMS=""
.else
CONFIGURE_ARGS+=	--disable-mms
PLIST_SUB+=	MMS="@comment "
.endif

.if ${PORT_OPTIONS:MSHN}
PLIST_SUB+=	SHN=""
.else
CONFIGURE_ARGS+=	--disable-shn
PLIST_SUB+=	SHN="@comment "
.endif

.if ${PORT_OPTIONS:MAO}
PLIST_SUB+=	AO=""
.else
CONFIGURE_ARGS+=	--disable-ao
PLIST_SUB+=	AO="@comment "
.endif

.if ${PORT_OPTIONS:MSHELLEXEC}
PLIST_SUB+=	SHELLEXEC=""
.else
CONFIGURE_ARGS+=	--disable-shellexec
PLIST_SUB+=	SHELLEXEC="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MCONVERTER}
.if ${PORT_OPTIONS:MGUI}
PLIST_SUB+=	CONVERTER=""
USE_GNOME=	gtk20 glib20
.else
BROKEN=		CONVERTER plugin required for gui, please rerun 'make config' and either disable CONVERTER or enable GUI
.endif
.else
CONFIGURE_ARGS+=	--disable-converter
PLIST_SUB+=	CONVERTER="@comment "
.endif

.if ${PORT_OPTIONS:MM3U}
PLIST_SUB+=	M3U=""
.else
CONFIGURE_ARGS+=	--disable-m3u
PLIST_SUB+=	M3U="@comment "
.endif

.if ${PORT_OPTIONS:MPSF}
PLIST_SUB+=	PSF=""
.else
CONFIGURE_ARGS+=	--disable-psf
PLIST_SUB+=	PSF="@comment "
.endif

.if ${PORT_OPTIONS:MDSP}
PLIST_SUB+=	DSP=""
LIB_DEPENDS+=	samplerate:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=	--disable-src
PLIST_SUB+=	DSP="@comment "
.endif

.if ${PORT_OPTIONS:MMONO2STEREO}
PLIST_SUB+=	MONO2STEREO=""
.else
CONFIGURE_ARGS+=	--disable-mono2stereo
PLIST_SUB+=	MONO2STEREO="@comment "
.endif

.if ${PORT_OPTIONS:MVFS_ZIP}
PLIST_SUB+=	VFS_ZIP=""
LIB_DEPENDS+=	zip:${PORTSDIR}/archivers/libzip
.else
CONFIGURE_ARGS+=	--disable-vfs-zip
PLIST_SUB+=	VFS_ZIP="@comment "
.endif

post-patch:
# Do not link to libsupc++ which may be PIC-unsafe (breaks 64-bit arches)
	@${REINPLACE_CMD} -e 's, -lsupc++,,' \
		${WRKSRC}/plugins/adplug/Makefile.in \
		${WRKSRC}/plugins/gme/Makefile.in \
		${WRKSRC}/plugins/sid/Makefile.in \
		${WRKSRC}/plugins/supereq/Makefile.in
	@${REINPLACE_CMD} -e 's,/etc/timidity++/timidity-freepats.cfg:/etc/timidity/freepats.cfg:/etc/timidity/,${LOCALBASE}/share/,' \
		${WRKSRC}/plugins/wildmidi/wildmidiplug.c

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not build on powerpc-9: fails to compile
.endif

.include <bsd.port.post.mk>
