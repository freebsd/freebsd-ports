PORTNAME=		easyeffects
DISTVERSIONPREFIX=	v
DISTVERSION=		8.3.0
CATEGORIES=		audio

MAINTAINER=	iwtcex@gmail.com
COMMENT=	Audio effects for PipeWire
WWW=		https://github.com/wwmm/easyeffects

LICENSE=	GPLv3+

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa \
		nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libbs2b.so:audio/libbs2b \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libgsl.so:math/gsl \
		liblilv-0.so:audio/lilv \
		libmysofa.so:audio/libmysofa \
		libpipewire-0.3.so:multimedia/pipewire \
		librnnoise.so:audio/rnnoise \
		libsndfile.so:audio/libsndfile \
		libSoundTouch.so:audio/soundtouch \
		libspeexdsp.so:audio/speexdsp \
		libwebrtc-audio-processing-2.so:audio/webrtc-audio-processing2 \
		libzita-convolver.so:audio/zita-convolver
RUN_DEPENDS=	calf-lv2>0:audio/calf-lv2 \
		lsp-plugins-lv2>0:audio/lsp-plugins-lv2

USES=		cmake ebur128 gettext-tools kde:6 pkgconfig qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	wwmm

USE_KDE=	breeze-icons \
		colorscheme \
		config \
		coreaddons \
		i18n \
		iconthemes \
		kirigami2 \
		kirigami-addons \
		qqc2-desktop-style \
		ecm:build

USE_QT=		base declarative graphs

CMAKE_ON=	ENABLE_LIBCPP_WORKAROUNDS

# Somehow there are quite a few transitive dependencies being passed
# to the linker (notably libOpenGL.so). We'll ignore them for now.
LDFLAGS=	-Wl,--as-needed

.include <bsd.port.mk>
