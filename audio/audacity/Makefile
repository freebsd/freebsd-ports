PORTNAME=	audacity
DISTVERSIONPREFIX=	Audacity-
DISTVERSION=	3.7.5
CATEGORIES=	audio
MASTER_SITES+=	https://github.com/${PORTNAME}/${PORTNAME}-manual/releases/download/v${DISTVERSION}/:manual
DISTFILES+=	${PORTNAME}-manual-${DISTVERSION}.tar.gz:manual

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	GUI editor for digital audio waveforms
WWW=		https://www.audacityteam.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	conan:sysutils/conan \
		lv2>0:audio/lv2 \
		rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libharfbuzz.so:print/harfbuzz \
		liblilv-0.so:audio/lilv \
		libmp3lame.so:audio/lame \
		libmpg123.so:audio/mpg123 \
		libopus.so:audio/opus \
		libopusfile.so:audio/opusfile \
		libportaudio.so:audio/portaudio \
		libportmidi.so:audio/portmidi \
		libserd-0.so:devel/serd \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libsoxr.so:audio/libsoxr \
		libsqlite3.so:databases/sqlite3 \
		libsratom-0.so:audio/sratom \
		libsuil-0.so:audio/suil \
		libuuid.so:misc/libuuid \
		libwavpack.so:audio/wavpack

USES=		cmake compiler:c++20-lang cpe desktop-file-utils \
		gettext-runtime gnome python:build pkgconfig shared-mime-info
CPE_VENDOR=	audacityteam

USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30
USE_WX=		3.2+
WX_COMPS=	wx

CMAKE_ARGS=	-DAUDACITY_BUILD_LEVEL=2 \
		-Daudacity_lib_preference:STRING=system \
		-Daudacity_use_curl:STRING=system \
		-Daudacity_use_expat:STRING=system \
		-Daudacity_use_jpeg:STRING=system \
		-Daudacity_use_libmp3lame:STRING=system \
		-Daudacity_use_libmpg123:STRING=system \
		-Daudacity_use_libopus:STRING=system \
		-Daudacity_use_libsndfile:STRING=system \
		-Daudacity_use_lv2:STRING=system \
		-Daudacity_use_midi:STRING=system \
		-Daudacity_use_nyquist:STRING=local \
		-Daudacity_use_png:STRING=system \
		-Daudacity_use_portaudio:STRING=system \
		-Daudacity_use_portmixer:STRING=local \
		-Daudacity_use_portsmf:STRING=local \
		-Daudacity_use_rapidjson:STRING=system \
		-Daudacity_use_soxr:STRING=system \
		-Daudacity_use_sqlite:STRING=system \
		-Daudacity_use_wavpack=system \
		-Daudacity_use_wxwidgets:STRING=system \
		-Daudacity_use_zlib:STRING=system

CMAKE_ON=	audacity_bundle_gplv3 audacity_conan_allow_prebuilt_binaries \
		audacity_obey_system_dependencies
CMAKE_OFF=	audacity_conan_enabled audacity_conan_force_build_dependencies \
		audacity_has_audiocom_upload audacity_has_crashreports \
		audacity_has_networking audacity_has_tests \
		audacity_has_updates_check audacity_has_url_schemes_support \
		audacity_has_vst3 audacity_perform_codesign audacity_use_pch

PORTDOCS=	README.md

OPTIONS_DEFINE=		DEBUG DOCS FFMPEG FLAC ID3TAG LADSPA MANUAL NLS OGG \
			SBSMS SOUNDTOUCH TWOLAME VAMP VORBIS VST
OPTIONS_DEFAULT=	FFMPEG FLAC ID3TAG LADSPA OGG SBSMS SOUNDTOUCH TWOLAME \
			VAMP VORBIS VST
OPTIONS_EXCLUDE_i386=	SBSMS
OPTIONS_SUB=		yes

MANUAL_DESC=		Include manual
SBSMS_DESC=		Use libsbsms for pitch and tempo changing
SOUNDTOUCH_DESC=	Use libSoundTouch for pitch and tempo changing
TWOLAME_DESC=		Use libtwolame for MP2 export support
VAMP_DESC=		Vamp plug-in support
VST_DESC=		VST plug-in support

DEBUG_CMAKE_ON=		wxWidgets_USE_DEBUG

FFMPEG_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libavcodec.pc:multimedia/ffmpeg
FFMPEG_RUN_DEPENDS=	${LOCALBASE}/lib/libavformat.so:multimedia/ffmpeg
FFMPEG_CMAKE_ON=	-Daudacity_use_ffmpeg:STRING=loaded
FFMPEG_CMAKE_OFF=	-Daudacity_use_ffmpeg:STRING=off

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_ON=		-Daudacity_use_libflac:STRING=system
FLAC_CMAKE_OFF=		-Daudacity_use_libflac:STRING=off

ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag
ID3TAG_CMAKE_ON=	-Daudacity_use_libid3tag:STRING=system
ID3TAG_CMAKE_OFF=	-Daudacity_use_libid3tag:STRING=off

LADSPA_RUN_DEPENDS=	listplugins:audio/ladspa
LADSPA_CMAKE_BOOL=	audacity_use_ladspa

MANUAL_CMAKE_BOOL=	audacity_package_manual

NLS_USES=		gettext-tools
NLS_CMAKE_BOOL=		audacity_locale

OGG_LIB_DEPENDS=	libogg.so:audio/libogg
OGG_CMAKE_ON=		-Daudacity_use_libogg:STRING=system
OGG_CMAKE_OFF=		-Daudacity_use_libogg:STRING=off

SBSMS_CMAKE_ON=		-Daudacity_use_sbsms:STRING=local
SBSMS_CMAKE_OFF=	-Daudacity_use_sbsms:STRING=off

SOUNDTOUCH_BROKEN_OFF=	Disabling soundtouch builds are currently broken due to a bug.
SOUNDTOUCH_LIB_DEPENDS=	libSoundTouch.so:audio/soundtouch
SOUNDTOUCH_CMAKE_ON=	-Daudacity_use_soundtouch:STRING=system
SOUNDTOUCH_CMAKE_OFF=	-Daudacity_use_soundtouch:STRING=off

TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame
TWOLAME_CMAKE_ON=	-Daudacity_use_twolame:STRING=system
TWOLAME_CMAKE_OFF=	-Daudacity_use_twolame:STRING=off

VAMP_LIB_DEPENDS=	libvamp-hostsdk.so:audio/vamp-plugin-sdk
VAMP_CMAKE_ON=		-Daudacity_use_vamp:STRING=system
VAMP_CMAKE_OFF=		-Daudacity_use_vamp:STRING=off

VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
VORBIS_CMAKE_ON=	-Daudacity_use_libvorbis:STRING=system
VORBIS_CMAKE_OFF=	-Daudacity_use_libvorbis:STRING=off

VST_CMAKE_BOOL=		audacity_use_vst

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DHAVE_MMX:BOOL=OFF \
		-DHAVE_SSE:BOOL=OFF \
		-DHAVE_SSE2:BOOL=OFF
.endif

post-configure-MANUAL-on:
	@${MV} ${WRKDIR}/help/manual ${WRKDIR}/.build/help/

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt
	#delete empty directories: https://github.com/audacity/audacity/issues/808
	@${FIND} ${STAGEDIR} -type d -empty -delete

post-install-DEBUG-off:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/audacity -name '*.so*' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
