PORTNAME=	bespokesynth
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software modular synth
WWW=		https://www.bespokesynth.com/ \
		https://github.com/BespokeSynth/BespokeSynth

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_15=	compilation broken with clang-19: see https://github.com/BespokeSynth/BespokeSynth/issues/1687

BUILD_DEPENDS=	juce706>0:devel/juce706 \
		pybind11>0:devel/pybind11
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libjsoncpp.so:devel/jsoncpp \
		libpng16.so:graphics/png

USES=		cmake:noninja desktop-file-utils gl localbase:ldflags pkgconfig python
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	BespokeSynth
GH_PROJECT=	BespokeSynth

DATADIR=	${PREFIX}/share/BespokeSynth

GH_TUPLE=	Ableton:link:a4e4c2f:ableton/libs/ableton-link \
			chriskohlhoff:asio:01b4e87:ableton_asio/libs/ableton-link/modules/asio-standalone \
		ArashPartow:exprtk:ca58bbd:exprtk/libs/exprtk \
		surge-synthesizer:tuning-library:eb8617be49ac3c2436cf54de6bff94a1b1c94acf:surge_synthesizer_tuning_library/libs/tuning-library \
		ODDSound:MTS-ESP:fcfaa59a043d515d288c9d587bf61a0a7d7571a8:ODDSound_MTS_ESP/libs/oddsound-mts/MTS-ESP \
		Ableton:link:a4e4c2f3e598e28e5bea90002f954b997b8c8c53:Ableton_link/libs/link \
		cameron314:readerwriterqueue:8e7627d:readerwriterqueue/libs/readerwriterqueue

#[submodule "libs/JUCE"]
#	path = libs/JUCE
#	url = https://github.com/juce-framework/JUCE
#[submodule "libs/pybind11"]
#	path = libs/pybind11
#	url = https://github.com/pybind/pybind11
#[submodule "libs/tuning-library"]
#	path = libs/tuning-library
#	url = https://github.com/surge-synthesizer/tuning-library
#[submodule "libs/oddsound-mts/MTS-ESP"]
#	path = libs/oddsound-mts/MTS-ESP
#	url = https://github.com/ODDSound/MTS-ESP
#[submodule "libs/json/jsoncpp"]
#	path = libs/json/jsoncpp
#	url = https://github.com/open-source-parsers/jsoncpp.git
#[submodule "libs/ableton-link"]
#	path = libs/ableton-link
#	url = https://github.com/Ableton/link.git
#[submodule "libs/readerwriterqueue"]
#	path = libs/readerwriterqueue
#	url = https://github.com/cameron314/readerwriterqueue.git
#[submodule "libs/exprtk"]
#	path = libs/exprtk
#	url = https://github.com/ArashPartow/exprtk.git
#	branch = cmake

CMAKE_ON=	BESPOKE_SYSTEM_JUCE \
		BESPOKE_SYSTEM_PYBIND11 \
		BESPOKE_SYSTEM_JSONCPP

CXXFLAGS+=	-DJUCE_INCLUDE_PNGLIB_CODE=0
LDFLAGS+=	-lpng

.include <bsd.port.mk>
