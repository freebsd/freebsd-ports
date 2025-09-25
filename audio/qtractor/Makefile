PORTNAME=	qtractor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.8
CATEGORIES=	audio
MASTER_SITES=	https://download.steinberg.net/sdk_downloads/:vst3sdk
DISTFILES=	${VST3_SDK_ARCHIVE}:vst3sdk
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}_GH0${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio/MIDI multi-track sequencer
WWW=		https://qtractor.org \
		https://github.com/rncbc/qtractor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

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
		libsndfile.so:audio/libsndfile \
		libsuil-0.so:audio/suil \
		libvorbis.so:audio/libvorbis \
		libvorbisenc.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis
RUN_DEPENDS=	alsa-seq-server>0:audio/alsa-seq-server

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-runtime gnome localbase:ldflags pkgconfig qt:5 shared-mime-info
USE_GNOME=	atk cairo gdkpixbuf gtk20 gtkmm24 pango
USE_QT=		core gui svg widgets x11extras xml buildtools:build linguisttools:build qmake:build
#USE_QT=		base svg tools:build # for Qt6

USE_GITHUB=	yes
GH_ACCOUNT=	rncbc

CMAKE_OFF=	CONFIG_CLAP # for audio/clap, but it doesn't install anything
CMAKE_OFF+=	CONFIG_QT6 # breaks with Qt6: Gtk-ERROR **: 21:10:56.939: GTK 2.x symbols detected. Using GTK 2.x and GTK 3 in the same process is not supported

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
