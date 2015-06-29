# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Ultimate music player for Unix-like systems

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libmad.so:${PORTSDIR}/audio/libmad

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig gettext iconv shebangfix tar:bzip2 desktop-file-utils \
		libtool execinfo
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-alsa --disable-nullout --disable-gtk3
CPPFLAGS+=	-I../dumb/dumb-kode54/include -I../../plugins/libmp4ff -I../../plugins/gme/game-music-emu-0.6pre -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo -lintl
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
SHEBANG_FILES=	yasmwrapper.sh
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	PULSEAUDIO GUI VFS LASTFM ART EQ SID FFAP VTX HOTKEYS OGG FFMPEG \
		FLAC SNDFILE WAV CDDA GME DUMB NOTIFY MUSEPACK WILD TTA DCA AAC \
		MMS SHN AO SHELLEXEC NLS M3U PSF ADP DSP MONO2STEREO CONVERTER VFS_ZIP \
		ALAC PLTBROWSER WMA
OPTIONS_DEFAULT=	GUI VFS LASTFM ART EQ SID FFAP VTX HOSTKEYS OGG FFMPEG \
			FLAC SNDFILE WAV CDDA GME DUMB NOTIFY MUSEPACK WILD TTA DCA \
			AAC MMS SHN AO SHELLEXEC M3U PSF ADP DSP MONO2STEREO CONVERTER VFS_ZIP \
			HOTKEYS ALAC PLTBROWSER WMA
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
ALAC_DESC=		ALAC plugin
PLTBROWSER_DESC=	Playlist browser gui plugin
WMA_DESC=		WMA plugin

OPTIONS_SUB=	yes

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse

GUI_USE=	gnome=gtk20,glib20
GUI_CONFIGURE_OFF=	--disable-gtkui --disable-gtk3

VFS_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
VFS_CONFIGURE_OFF=	--disable-vfs-curl

LASTFM_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
LASTFM_CONFIGURE_OFF=	--disable-lfm

ART_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
			libImlib2.so:${PORTSDIR}/graphics/imlib2
ART_USES=		jpeg
ART_CONFIGURE_OFF=	--disable-artwork --disable-artwork-imlib2

EQ_CONFIGURE_OFF=	--disable-supereq

SID_CONFIGURE_OFF=	--disable-sid

FFAP_BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
FFAP_CONFIGURE_OFF=	--disable-ffap

VTX_CONFIGURE_OFF=	--disable-vtx

ADP_CONFIGURE_OFF=	--disable-adplug

HOTKEYS_CONFIGURE_OFF=	--disable-hotkeys

OGG_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
OGG_CONFIGURE_OFF=	--disable-vorbis

FFMPEG_LIB_DEPENDS=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libavformat0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libavutil0.so:${PORTSDIR}/multimedia/ffmpeg0
FFMPEG_CONFIGURE_ENABLE=	ffmpeg

FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CONFIGURE_OFF=	--disable-flac

SNDFILE_LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile
SNDFILE_CONFIGURE_OFF=	--disable-sndfile

WAV_LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack
WAV_CONFIGURE_OFF=	--disable-wavpack

CDDA_LIB_DEPENDS=	libcdio.so:${PORTSDIR}/sysutils/libcdio \
			libcddb.so:${PORTSDIR}/audio/libcddb
CDDA_CONFIGURE_OFF=	--disable-cdda

GME_CONFIGURE_OFF=	--disable-gme

DUMB_CONFIGURE_OFF=	--disable-dumb

NOTIFY_LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
NOTIFY_CONFIGURE_OFF=	--disable-notify

MUSEPACK_CONFIGURE_OFF=	--disable-musepack

WILD_RUN_DEPENDS=	${LOCALBASE}/share/freepats/crude.cfg:${PORTSDIR}/audio/freepats
WILD_CONFIGURE_OFF=	--disable-wildmidi

TTA_CONFIGURE_OFF=	--disable-tta

DCA_CONFIGURE_OFF=	--disable-dca

AAC_LIB_DEPENDS=	libfaad.so:${PORTSDIR}/audio/faad
AAC_CONFIGURE_OFF=	--disable-aac

MMS_CONFIGURE_OFF=	--disable-mms

SHN_CONFIGURE_OFF=	--disable-shn

AO_CONFIGURE_OFF=	--disable-ao

SHELLEXEC_CONFIGURE_ARGS+=	--disable-shellexec

NLS_CONFIGURE_OFF=	--disable-nls

M3U_CONFIGURE_OFF=	--disable-m3u

SPF_CONFIGURE_OFF=	--disable-psf

DSP_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
DSP_CONFIGURE_OFF=	--disable-src

MONO2STEREO_CONFIGURE_OFF=	--disable-mono2stereo

CONVERTER_CONFIGURE_OFF=	--disable-converter

VFS_ZIP_LIB_DEPENDS=	libzip.so:${PORTSDIR}/archivers/libzip
VFS_ZIP_CONFIGURE_OFF=	--disable-vfs-zip

ALAC_CONFIGURE_OFF=		--disable-alac

PLTBROWSER_CONFIGURE_OFF=	--disable-pltbrowser

WMA_CONFIGURE_OFF=		--disable-wma

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MART} && ! ${PORT_OPTIONS:MVFS}
BROKEN=		VFS plugin required for album art loader, please rerun 'make config' and either disable ART or enable VFS
.endif

.if ${PORT_OPTIONS:MCONVERTER} && ! ${PORT_OPTIONS:MGUI}
BROKEN=		CONVERTER plugin required for gui, please rerun 'make config' and either disable CONVERTER or enable GUI
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
		-e 's,libavcodec ,libavcodec0 ,g' \
		-e 's,libavutil ,libavutil0 ,g' \
		-e 's,libavformat ,libavformat0 ,g' \
		${WRKSRC}/configure

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not build on powerpc-9: fails to compile
.endif

.include <bsd.port.mk>
