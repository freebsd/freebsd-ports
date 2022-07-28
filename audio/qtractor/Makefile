PORTNAME=	qtractor
DISTVERSIONPREFIX=	qtractor_
DISTVERSION=	0_9_27
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/rncbc/qtractor/archive/refs/tags/ \
		https://download.steinberg.net/sdk_downloads/:vst3sdk
DISTFILES=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX} \
		${VST3_SDK_ARCHIVE}:vst3sdk
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio/MIDI multi-track sequencer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	non-constant-expression cannot be narrowed from type 'double' to 'float' in initializer list, see https://github.com/rncbc/qtractor/issues/353

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libaubio.so:audio/aubio \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjack.so:audio/jack \
		liblilv-0.so:audio/lilv \
		liblo.so:audio/liblo \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		librubberband.so:audio/rubberband \
		libsamplerate.so:audio/libsamplerate \
		libserd-0.so:devel/serd \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		libsuil-0.so:audio/suil \
		libvorbis.so:audio/libvorbis \
		libvorbisenc.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-runtime gnome localbase:ldflags pkgconfig qt:5 shared-mime-info
USE_GNOME=	atk cairo gdkpixbuf2 gtk20 gtkmm24 pango
USE_QT=		core gui svg widgets x11extras xml buildtools_build linguisttools_build qmake_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}_${DISTVERSION}

CMAKE_OFF=	CONFIG_CLAP # for audio/clap, but it doesn't install anything

OPTIONS_DEFINE=		VST3
OPTIONS_DEFAULT=	VST3

VST3_DESC=		Enable VST3 plug-in support
VST3_USES=		xorg
VST3_USE=		XORG=xcb
VST3_CMAKE_BOOL=	CONFIG_VST3
VST3_CMAKE_ON=		-DCONFIG_VST3SDK=${WRKDIR}/VST_SDK/vst3sdk
#VST3_BUILD_DEPENDS=	vst3sdk>0:audio/vst3sdk # this is supposed to work instead of bundled archive, but it doesn't for some reason, see https://github.com/rncbc/qtractor/issues/331
VST3_SDK_ARCHIVE=	vst-sdk_3.7.4_build-25_2021-12-16.zip

post-extract-VST3-on:
	@cd ${WRKDIR} && unzip -qq ${DISTDIR}/${VST3_SDK_ARCHIVE}

post-patch:
	@${REINPLACE_CMD} \
		's|the ALSA Sequencer kernel module (snd-seq-midi)|alsa-seq-server (installed by audio/alsa-seq-server)|' \
		${WRKSRC}/src/qtractorMainForm.cpp

post-patch-VST3-on:
	@${REINPLACE_CMD} -e ' \
		s,__linux__,__linux__ || __FreeBSD__,; \
		s,endian.h,sys/endian.h, \
		' \
		${WRKDIR}/VST_SDK/vst3sdk/pluginterfaces/base/fplatform.h
	@${REINPLACE_CMD} -e ' \
		s,stdatomic.h,atomic,; \
		s,atomic_int_least32_t,std::atomic_int_least32_t, \
		' \
		${WRKDIR}/VST_SDK/vst3sdk/pluginterfaces/base/funknown.cpp

.include <bsd.port.mk>
