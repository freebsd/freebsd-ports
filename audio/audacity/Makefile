# Created by: Marc van Woerkom <3d@FreeBSD.org>

PORTNAME=	audacity
PORTVERSION=	2.4.2
PORTREVISION=	4
DISTVERSIONPREFIX=	Audacity-
CATEGORIES=	audio

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	GUI editor for digital audio waveforms

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libexpat.so:textproc/expat2 \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libsoxr.so:audio/libsoxr

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext \
		gnome libtool python:build pkgconfig shared-mime-info
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
USE_WX=		3.1+
WX_COMPS=	wx
INSTALLS_ICONS=	yes
PORTDOCS=	README.txt

CMAKE_ARGS=	-Daudacity_lib_preference:STRING=system \
		-Daudacity_use_expat:STRING=system \
		-Daudacity_use_wxwidgets:STRING=system \
		-Daudacity_use_soxr:STRING=system \
		-Daudacity_use_sndfile:STRING=system \
		-Daudacity_use_portsmf:STRING=local \
		-Daudacity_use_portmixer:STRING=local \
		-Daudacity_use_portaudio:STRING=system
CMAKE_OFF=	audacity_use_pch

OPTIONS_DEFINE=		DEBUG DOCS FFMPEG FLAC ID3TAG LADSPA LAME LV2 MAD \
			MIDI OGG SBSMS SOUNDTOUCH TWOLAME VAMP \
			VORBIS VST
OPTIONS_DEFAULT=	FLAC ID3TAG LADSPA MAD MIDI OGG SBSMS \
			SOUNDTOUCH TWOLAME VAMP VORBIS VST
OPTIONS_EXCLUDE_i386=	SBSMS

LAME_DESC=		Use lame for import and export support
LV2_DESC=		Add LV2 plug-in support
MAD_DESC=		Use libmad for mp2/3 decoding support
MIDI_DESC=		MIDI support
SBSMS_DESC=		Use libsbsms for pitch and tempo changing
SOUNDTOUCH_DESC=	Use libSoundTouch for pitch and tempo changing
TWOLAME_DESC=		Use libtwolame for MP2 export support
VAMP_DESC=		Vamp plug-in support
VST_DESC=		VST plug-in support

DEBUG_CMAKE_ON=		wxWidgets_USE_DEBUG

DOCS_BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man \
			docbook2man:textproc/docbook-utils

FFMPEG_CMAKE_ON=	-Daudacity_use_ffmpeg:STRING=loaded
FFMPEG_CMAKE_OFF=	-Daudacity_use_ffmpeg:STRING=off
FFMPEG_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libavcodec.pc:multimedia/ffmpeg
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

FLAC_CMAKE_ON=		-Daudacity_use_flac:STRING=system
FLAC_CMAKE_OFF=		-Daudacity_use_flac:STRING=local
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

ID3TAG_CMAKE_ON=	-Daudacity_use_id3tag:STRING=system
ID3TAG_CMAKE_OFF=	-Daudacity_use_id3tag:STRING=off
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

LADSPA_CMAKE_BOOL=	audacity_use_ladspa
LADSPA_RUN_DEPENDS=	listplugins:audio/ladspa

LAME_CMAKE_ON=		-Daudacity_use_lame:STRING=system
LAME_CMAKE_OFF=		-Daudacity_use_lame:STRING=local
LAME_BUILD_DEPENDS=	${LOCALBASE}/include/lame/lame.h:audio/lame
LAME_CPPFLAGS=		-I${LOCALBASE}/include/lame
LAME_LDFLAGS=		-L${LOCALBASE}/lib
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame

LV2_CMAKE_ON=		-Daudacity_use_lv2:STRING=system
LV2_CMAKE_OFF=		-Daudacity_use_lv2:STRING=off
LV2_LIB_DEPENDS=	liblilv-0.so:audio/lilv \
			libserd-0.so:devel/serd \
			libsord-0.so:devel/sord \
			libsratom-0.so:audio/sratom \
			libsuil-0.so:audio/suil

MAD_CMAKE_ON=		-Daudacity_use_mad:STRING=system
MAD_CMAKE_OFF=		-Daudacity_use_mad:STRING=off
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

MIDI_CMAKE_ON=		-Daudacity_use_midi:STRING=local
MIDI_CMAKE_OFF=		-Daudacity_use_midi:STRING=off

# TODO: fix NLS support properly
PLIST_SUB+=		NLS=""

OGG_CMAKE_ON=		-Daudacity_use_ogg:STRING=system
OGG_CMAKE_OFF=		-Daudacity_use_ogg:STRING=local
OGG_LIB_DEPENDS=	libogg.so:audio/libogg

SBSMS_CMAKE_ON=		-Daudacity_use_sbsms:STRING=local
SBSMS_CMAKE_OFF=	-Daudacity_use_sbsms:STRING=off

SOUNDTOUCH_CMAKE_ON=	-Daudacity_use_soundtouch:STRING=system
SOUNDTOUCH_CMAKE_OFF=	-Daudacity_use_soundtouch:STRING=off
SOUNDTOUCH_LIB_DEPENDS=		libSoundTouch.so:audio/soundtouch

TWOLAME_CMAKE_ON=	-Daudacity_use_twolame:STRING=system
TWOLAME_CMAKE_OFF=	-Daudacity_use_twolame:STRING=off
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame

VAMP_CMAKE_ON=		-Daudacity_use_vamp:STRING=system
VAMP_CMAKE_OFF=		-Daudacity_use_vamp:STRING=off
VAMP_LIB_DEPENDS=	libvamp-hostsdk.so:audio/vamp-plugin-sdk

VORBIS_CMAKE_ON=	-Daudacity_use_vorbis:STRING=system
VORBIS_CMAKE_OFF=	-Daudacity_use_vorbis:STRING=off
VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis

VST_CMAKE_BOOL=		audacity_use_vst

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DHAVE_MMX:BOOL=OFF \
		-DHAVE_SSE:BOOL=OFF \
		-DHAVE_SSE2:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,Python2,Python${PYTHON_MAJOR_VER}, ; \
		/CMAKE_CXX_STANDARD/s,14,11,' ${WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
