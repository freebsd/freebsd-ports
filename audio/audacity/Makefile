PORTNAME=	audacity
DISTVERSIONPREFIX=	Audacity-
DISTVERSION=	3.3.3
PORTREVISION=	1
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	4c833569fb12.patch:-p1

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	GUI editor for digital audio waveforms
WWW=		https://www.audacityteam.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	conan:sysutils/conan
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libopenjp2.so:graphics/openjpeg \
		libmp3lame.so:audio/lame \
		libmpg123.so:audio/mpg123 \
		libopus.so:audio/opus \
		libportaudio.so:audio/portaudio \
		libportmidi.so:audio/portmidi \
		libpng.so:graphics/png \
		libsndfile.so:audio/libsndfile \
		libsoxr.so:audio/libsoxr \
		libsqlite3.so:databases/sqlite3 \
		libwavpack.so:audio/wavpack \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake compiler:c++17-lang cpe desktop-file-utils gettext \
		gnome libtool python:build pkgconfig shared-mime-info

USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_WX=		3.2+
CPE_VENDOR=	audacityteam
WX_COMPS=	wx
PORTDOCS=	README.md

CMAKE_ARGS=	-Daudacity_lib_preference:STRING=system \
		-Daudacity_use_curl:STRING=system \
		-Daudacity_use_expat:STRING=system \
		-Daudacity_use_jpeg:STRING=system \
		-Daudacity_use_libmp3lame:STRING=system \
		-Daudacity_use_libmpg123:STRING=system \
		-Daudacity_use_libopus:STRING=system \
		-Daudacity_use_libsndfile:STRING=system \
		-Daudacity_use_midi:STRING=system \
		-Daudacity_use_nyquist:STRING=local \
		-Daudacity_use_portaudio:STRING=system \
		-Daudacity_use_portmixer:STRING=local \
		-Daudacity_use_portsmf:STRING=local \
		-Daudacity_use_png:STRING=system \
		-Daudacity_use_soxr:STRING=system \
		-Daudacity_use_sqlite:STRING=system \
		-Daudacity_use_wavpack=system \
		-Daudacity_use_wxwidgets:STRING=system \
		-Daudacity_use_zlib:STRING=system

CMAKE_ON=	audacity_bundle_gplv3 audacity_conan_allow_prebuilt_binaries audacity_obey_system_dependencies
CMAKE_OFF=	audacity_has_audiocom_upload audacity_conan_enabled audacity_conan_force_build_dependencies \
		audacity_has_crashreports audacity_has_networking audacity_has_updates_check audacity_has_url_schemes_support \
		audacity_has_sentry_reporting audacity_has_tests audacity_has_vst3 audacity_perform_codesign audacity_use_pch

OPTIONS_DEFINE=		DEBUG DOCS FFMPEG FLAC ID3TAG LADSPA LV2 MAD MANUAL \
			OGG SBSMS SOUNDTOUCH TWOLAME VAMP \
			VORBIS VST
OPTIONS_DEFAULT=	FFMPEG FLAC ID3TAG LADSPA LV2 MAD OGG SBSMS \
			SOUNDTOUCH TWOLAME VAMP VORBIS VST
OPTIONS_EXCLUDE_i386=	SBSMS

LV2_DESC=		Add LV2 plug-in support
MAD_DESC=		Use libmad for mp2/3 decoding support
MANUAL_DESC=		Include manual
SBSMS_DESC=		Use libsbsms for pitch and tempo changing
SOUNDTOUCH_DESC=	Use libSoundTouch for pitch and tempo changing
TWOLAME_DESC=		Use libtwolame for MP2 export support
VAMP_DESC=		Vamp plug-in support
VST_DESC=		VST plug-in support

DEBUG_CMAKE_ON=		wxWidgets_USE_DEBUG

DOCS_BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man \
			docbook2man:textproc/docbook-utils
DOCS_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

FFMPEG_CMAKE_ON=	-Daudacity_use_ffmpeg:STRING=loaded
FFMPEG_CMAKE_OFF=	-Daudacity_use_ffmpeg:STRING=off
FFMPEG_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libavcodec.pc:multimedia/ffmpeg
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

FLAC_CMAKE_ON=		-Daudacity_use_libflac:STRING=system
FLAC_CMAKE_OFF=		-Daudacity_use_libflac:STRING=off
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

ID3TAG_CMAKE_ON=	-Daudacity_use_libid3tag:STRING=system
ID3TAG_CMAKE_OFF=	-Daudacity_use_libid3tag:STRING=off
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

LADSPA_CMAKE_BOOL=	audacity_use_ladspa
LADSPA_RUN_DEPENDS=	listplugins:audio/ladspa

LV2_CMAKE_ON=		-Daudacity_use_lv2:STRING=system
LV2_CMAKE_OFF=		-Daudacity_use_lv2:STRING=off
LV2_LIB_DEPENDS=	liblilv-0.so:audio/lilv \
			libserd-0.so:devel/serd \
			libsord-0.so:devel/sord \
			libsratom-0.so:audio/sratom \
			libsuil-0.so:audio/suil

MAD_CMAKE_ON=		-Daudacity_use_libmad:STRING=system
MAD_CMAKE_OFF=		-Daudacity_use_libmad:STRING=off
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

MANUAL_CMAKE_BOOL=	audacity_package_manual

# TODO: fix NLS support properly
PLIST_SUB+=		NLS=""
OPTIONS_SUB=		yes

OGG_CMAKE_ON=		-Daudacity_use_libogg:STRING=system
OGG_CMAKE_OFF=		-Daudacity_use_libogg:STRING=off
OGG_LIB_DEPENDS=	libogg.so:audio/libogg

SBSMS_CMAKE_ON=		-Daudacity_use_sbsms:STRING=local
SBSMS_CMAKE_OFF=	-Daudacity_use_sbsms:STRING=off

SOUNDTOUCH_CMAKE_ON=	-Daudacity_use_soundtouch:STRING=system
SOUNDTOUCH_CMAKE_OFF=	-Daudacity_use_soundtouch:STRING=off
SOUNDTOUCH_LIB_DEPENDS=	libSoundTouch.so:audio/soundtouch

TWOLAME_CMAKE_ON=	-Daudacity_use_twolame:STRING=system
TWOLAME_CMAKE_OFF=	-Daudacity_use_twolame:STRING=off
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame

VAMP_CMAKE_ON=		-Daudacity_use_vamp:STRING=system
VAMP_CMAKE_OFF=		-Daudacity_use_vamp:STRING=off
VAMP_LIB_DEPENDS=	libvamp-hostsdk.so:audio/vamp-plugin-sdk

VORBIS_CMAKE_ON=	-Daudacity_use_libvorbis:STRING=system
VORBIS_CMAKE_OFF=	-Daudacity_use_libvorbis:STRING=off
VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis

VST_CMAKE_BOOL=		audacity_use_vst

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DHAVE_MMX:BOOL=OFF \
		-DHAVE_SSE:BOOL=OFF \
		-DHAVE_SSE2:BOOL=OFF
.endif

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
