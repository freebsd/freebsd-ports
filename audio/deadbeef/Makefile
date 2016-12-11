# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Ultimate music player for Unix-like systems

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
USES=		compiler:c11 desktop-file-utils execinfo gettext gmake iconv libtool \
		pkgconfig shebangfix tar:bzip2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-alsa --disable-nullout --disable-static
CPPFLAGS+=	-I../dumb/dumb-kode54/include -I../../plugins/libmp4ff \
		-I../../plugins/gme/game-music-emu-0.6pre \
		-I./sidplay-libs/libsidplay/include/sidplay \
		-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo -lintl
USE_GNOME=	intltool
INSTALLS_ICONS=	yes
SHEBANG_FILES=	yasmwrapper.sh
INSTALL_TARGET=	install-strip

BROKEN_aarch64=		Fails to compile: error in backend: Do not know how to split this operator's operand!
BROKEN_armv6=		Fails to compile: error: invalid conversion between vector type and integer type

OPTIONS_DEFINE=	PULSEAUDIO GUI VFS LASTFM ART SUPEREQ SID FFAP VTX \
		HOTKEYS OGG FFMPEG FLAC SNDFILE WAVPACK CDDA GME DUMB NOTIFY \
		MUSEPACK WILDMIDI TTA DCA AAC MMS SHN SHELLEXEC NLS M3U \
		PSF ADPLUG DSP MONO2STEREO CONVERTER VFS_ZIP ALAC PLTBROWSER \
		WMA SC68
OPTIONS_DEFAULT=MAD GTK2 VFS LASTFM ART SUPEREQ SID FFAP VTX HOSTKEYS \
		OGG FLAC SNDFILE WAVPACK CDDA GME DUMB NOTIFY MUSEPACK \
		WILDMIDI TTA DCA AAC MMS SHN SHELLEXEC M3U PSF ADPLUG DSP \
		MONO2STEREO CONVERTER VFS_ZIP HOTKEYS ALAC PLTBROWSER WMA SC68

PULSEAUDIO_DESC=	PulseAudio output plugin (unsupported)
GUI_DESC=		Standard GUI plugin
VFS_DESC=		HTTP streaming VFS plugin
LASTFM_DESC=		Last.fm/Libre.fm scrobbler plugin
ART_DESC=		Cover artwork loader plugin
SUPEREQ_DESC=		SuperEQ DSP plugin (equalizer)
SID_DESC=		Commodore 64 SID music player plugin
FFAP_DESC=		${APE_DESC}
VTX_DESC=		VTX ZX-Spectrum music player plugin
ADPLUG_DESC=		AdPlug audio format (OPL2/OPL3) support
HOTKEYS_DESC=		Local and global hotkeys support
GME_DESC=		Chiptune music support (based on GME)
DUMB_DESC=		D.U.M.B. plugin for MOD, S3M, etc.
NOTIFY_DESC=		OSD notification support in GTKUI plugin
WILDMIDI_DESC=		WildMIDI synthesizer plugin
SC68_DESC=		sc68 Atari ST And Amiga player
SHN_DESC=		Shorten waveform encoder support
SHELLEXEC_DESC=		Shell commands execution plugin
M3U_DESC=		M3U and PLS playlist format support
PSF_DESC=		AOSDK-based PSF(,QSF,SSF,DSF) plugin
DSP_DESC=		High-quality sample rate conversion support
MONO2STEREO_DESC=	Mono to stereo converter DSP plugin
CONVERTER_DESC=		Plugin for converting files from/to any formats
VFS_ZIP_DESC=		Play files directly from ZIP archives
PLTBROWSER_DESC=	Playlist browser GUI plugin

OPTIONS_SUB=		yes
OPTIONS_RADIO+=		GUI
OPTIONS_RADIO_GUI=	GTK2 GTK3
GUI_IMPLIES=		CONVERTER

OPTIONS_GROUP+=		MP3
OPTIONS_GROUP_MP3=	MAD MPG123

MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CONFIGURE_OFF=	--disable-libmad

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_CONFIGURE_OFF=	--disable-libmpg123

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse

GTK2_USE=		gnome=gtk20,glib20
GTK2_CONFIGURE_OFF=	--disable-gtk2
GTK2_CONFIGURE_ON=	--enable-gtk2
GTK2_VARS=		GTK_VER=2
GTK2_IMPLIES=		GUI

GTK3_USE=		gnome=gtk30
GTK3_CONFIGURE_OFF=	--disable-gtk3
GTK3_CONFIGURE_ON=	--enable-gtk3
GTK3_VARS=		GTK_VER=3
GTK3_IMPLIES=		GUI

PLIST_SUB+=		GTK_VER=${GTK_VER}

GUI_CONFIGURE_OFF=	--disable-gtk2 --disable-gtk3
GUI_LIB_DEPENDS=	libjansson.so:devel/jansson

VFS_LIB_DEPENDS=	libcurl.so:ftp/curl
VFS_CONFIGURE_OFF=	--disable-vfs-curl

LASTFM_LIB_DEPENDS=	libcurl.so:ftp/curl
LASTFM_CONFIGURE_OFF=	--disable-lfm

ART_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libImlib2.so:graphics/imlib2
ART_USES=		jpeg
ART_CONFIGURE_OFF=	--disable-artwork --disable-artwork-imlib2
ART_IMPLIES=		VFS

SUPEREQ_CONFIGURE_OFF=	--disable-supereq

SID_CONFIGURE_OFF=	--disable-sid

FFAP_BUILD_DEPENDS=	yasm:devel/yasm
FFAP_CONFIGURE_OFF=	--disable-ffap

VTX_CONFIGURE_OFF=	--disable-vtx

ADPLUG_CONFIGURE_OFF=	--disable-adplug

HOTKEYS_CONFIGURE_OFF=	--disable-hotkeys

OGG_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
OGG_CONFIGURE_OFF=	--disable-vorbis

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=	ffmpeg

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_OFF=	--disable-flac

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_OFF=	--disable-sndfile

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_OFF=	--disable-wavpack

CDDA_LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
			libcddb.so:audio/libcddb
CDDA_CONFIGURE_OFF=	--disable-cdda

GME_CONFIGURE_OFF=	--disable-gme

DUMB_CONFIGURE_OFF=	--disable-dumb

NOTIFY_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
NOTIFY_CONFIGURE_OFF=	--disable-notify

MUSEPACK_CONFIGURE_OFF=	--disable-musepack

WILDMIDI_RUN_DEPENDS=	${LOCALBASE}/share/freepats/crude.cfg:audio/freepats
WILDMIDI_CONFIGURE_OFF=	--disable-wildmidi

TTA_CONFIGURE_OFF=	--disable-tta

DCA_CONFIGURE_OFF=	--disable-dca

AAC_LIB_DEPENDS=	libfaad.so:audio/faad
AAC_CONFIGURE_OFF=	--disable-aac

MMS_CONFIGURE_OFF=	--disable-mms

SC68_CONFIGURE_ON=	--enable-sc68
SC68_CONFIGURE_OFF=	--disable-sc68

SHN_CONFIGURE_OFF=	--disable-shn

SHELLEXEC_CONFIGURE_ARGS+=	--disable-shellexec

NLS_CONFIGURE_OFF=	--disable-nls

M3U_CONFIGURE_OFF=	--disable-m3u

SPF_CONFIGURE_OFF=	--disable-psf

DSP_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
DSP_CONFIGURE_OFF=	--disable-src

MONO2STEREO_CONFIGURE_OFF=	--disable-mono2stereo

CONVERTER_CONFIGURE_OFF=	--disable-converter

VFS_ZIP_LIB_DEPENDS=	libzip.so:archivers/libzip
VFS_ZIP_CONFIGURE_OFF=	--disable-vfs-zip

ALAC_CONFIGURE_OFF=		--disable-alac

PLTBROWSER_CONFIGURE_OFF=	--disable-pltbrowser

WMA_CONFIGURE_OFF=		--disable-wma

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MGTK2} && !${PORT_OPTIONS:MGTK3}
PORT_OPTIONS:=          ${PORT_OPTIONS:NGUI}
.endif

.if !${PORT_OPTIONS:MMAD} && !${PORT_OPTIONS:MMPG123}
CONFIGURE_ARGS+=	--disable-mp3
PLIST_SUB+=		MP3="@comment "
.else
PLIST_SUB+=		MP3=""
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
	@${REINPLACE_CMD} \
		-e '/HAVE_OGG" = "yes"/ {n; n; /HAVE_VORBISPLUGIN=yes/d;}' \
		${WRKSRC}/configure
# Fix build with libzip-1.0
	@${REINPLACE_CMD} 's,zip_file_t,zip_file_DB,g' \
		${WRKSRC}/plugins/vfs_zip/vfs_zip.c

.include <bsd.port.mk>
