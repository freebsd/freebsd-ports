PORTNAME=	qtractor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	audio
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}_GH0${EXTRACT_SUFX} \
		free-audio-clap-195b42a_GH0${EXTRACT_SUFX} \
		breakfastquay-minibpm-43de991_GH0${EXTRACT_SUFX} \
		steinbergmedia-vst3_base-fcf9da0_GH0${EXTRACT_SUFX} \
		steinbergmedia-vst3_pluginterfaces-4f547e8_GH0${EXTRACT_SUFX} \
		steinbergmedia-vst3_public_sdk-586dc5e_GH0${EXTRACT_SUFX}

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

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-runtime \
		gl gnome localbase:ldflags pkgconfig qt:6 shared-mime-info
USE_GNOME=	atk cairo gdkpixbuf gtk20 gtkmm24 pango
USE_QT=		base svg tools:build
USE_GL=		gl opengl

USE_GITHUB=	yes
GH_ACCOUNT=	rncbc
GH_TUPLE=	free-audio:clap:195b42a:clap/src/clap \
		breakfastquay:minibpm:43de991:minibpm/src/minibpm \
		steinbergmedia:vst3_base:fcf9da0:vst3_base/src/vst3/base \
		steinbergmedia:vst3_pluginterfaces:4f547e8:vst3_pluginterfaces/src/vst3/pluginterfaces \
		steinbergmedia:vst3_public_sdk:586dc5e:vst3_public_sdk/src/vst3/public.sdk

CMAKE_OFF=	CONFIG_CLAP # for audio/clap, but it doesn't install anything
#CMAKE_OFF+=	CONFIG_QT6 # breaks with Qt6: Gtk-ERROR **: 21:10:56.939: GTK 2.x symbols detected. Using GTK 2.x and GTK 3 in the same process is not supported

OPTIONS_DEFINE=		VST3
OPTIONS_DEFAULT=	VST3

VST3_DESC=		Enable VST3 plug-in support
VST3_USES=		xorg
VST3_USE=		XORG=xcb
VST3_CMAKE_BOOL=	CONFIG_VST3
VST3_CMAKE_ON=		-DCONFIG_VST3SDK=${WRKSRC}/src/vst3

post-patch:
	@${REINPLACE_CMD} \
		's|the ALSA Sequencer kernel module (snd-seq-midi)|alsa-seq-server (installed by audio/alsa-seq-server)|' \
		${WRKSRC}/src/qtractorMainForm.cpp

.include <bsd.port.mk>
