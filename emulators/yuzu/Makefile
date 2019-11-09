# $FreeBSD$

PORTNAME=	yuzu
PORTVERSION=	s20191108
PORTREVISION?=	0
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Nintendo Switch emulator/debugger

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE BSL GPLv2+ ISCL LGPL21+ LGPL3+ MIT OpenSSL UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/externals/fmt/LICENSE.rst
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/externals/inih/inih/LICENSE.txt
LICENSE_FILE_BSL=	${WRKSRC}/externals/catch/LICENSE.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/license.txt
LICENSE_FILE_ISCL=	${WRKSRC}/externals/cubeb/LICENSE
LICENSE_FILE_LGPL21+ =	${_LICENSE_STORE}/LGPL21 # soundtouch
LICENSE_FILE_LGPL3+ =	${_LICENSE_STORE}/LGPL3 # sirit
LICENSE_FILE_MIT=	${WRKSRC}/externals/sirit/externals/SPIRV-Headers/LICENSE
LICENSE_FILE_OpenSSL=	${WRKSRC}/externals/libressl/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64
ONLY_FOR_ARCHS_REASON=	requires int128

BUILD_DEPENDS=	boost-libs>=1.66:devel/boost-libs \
		gmake:devel/gmake

USE_GITHUB=	yes
GH_ACCOUNT=	yuzu-emu
GH_TAGNAME=	a056d8de1
GH_TUPLE=	yuzu-emu:unicorn:1.0.1-153-g73f45735:unicorn/externals/unicorn \
		DarkLordZach:mbedtls:a280e60:mbedtls/externals/mbedtls \
		KhronosGroup:SPIRV-Headers:2c51218:SPIRV_Headers/externals/sirit/externals/SPIRV-Headers \
		KhronosGroup:Vulkan-Headers:v1.1.117:Vulkan_Headers/externals/Vulkan-Headers \
		MerryMage:dynarmic:r1-1436-g087a7441:dynarmic/externals/dynarmic \
		ReinUsesLisp:sirit:f7c4b07:sirit/externals/sirit \
		arsenm:sanitizers-cmake:aab6948:sanitizers_cmake/externals/cubeb/cmake/sanitizers-cmake \
		catchorg:Catch2:v2.3.0:catch/externals/catch \
		citra-emu:ext-libressl-portable:7d01cb0:libressl/externals/libressl \
		citra-emu:ext-soundtouch:060181e:soundtouch/externals/soundtouch \
		facebook:zstd:v1.3.8:zstd/externals/zstd \
		fmtlib:fmt:6.0.0-56-g4b8f8fac:fmt/externals/fmt \
		kinetiknz:cubeb:cubeb-0.2-1151-g9eb4c89:cubeb/externals/cubeb \
		lz4:lz4:v1.8.0-8-g4db65c1:lz4/externals/lz4 \
		madler:zlib:v1.2.11:zlib/externals/zlib/zlib \
		nih-at:libzip:rel-1-5-2-93-g89bd6d63:libzip/externals/libzip/libzip \
		svn2github:inih:603729d:inih/externals/inih/inih \
		weidai11:cryptopp:CRYPTOPP_7_0_0-23-gf320e7d9:cryptopp/externals/cryptopp/cryptopp \
		xiph:opus:v1.3.1-4-gad8fe90d:opus/externals/opus/opus

USES=		cmake compiler:c++17-lang iconv localbase:ldflags \
		python:2.7,build sdl
USE_SDL=	sdl2
LDFLAGS+=	-Wl,--as-needed # Qt5Network
TEST_TARGET=	test

OPTIONS_DEFINE=	ALSA PULSEAUDIO JACK SNDIO
OPTIONS_DEFAULT=ALSA PULSEAUDIO JACK SNDIO
OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CMAKE_BOOL=	USE_ALSA

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

SDL_CMAKE_BOOL=	ENABLE_SDL2
SDL_PLIST_FILES=bin/${PORTNAME}-cmd \
		bin/${PORTNAME}-tester

QT5_USES=	desktop-file-utils qt:5 shared-mime-info
QT5_USE=	QT=qmake_build,buildtools_build,concurrent_build,core,gui,opengl,webengine,widgets
QT5_CMAKE_BOOL=	ENABLE_QT YUZU_USE_QT_WEB_ENGINE
QT5_PLIST_FILES=bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/mime/packages/${PORTNAME}.xml

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		-e '/check_submodules_present()/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

.include <bsd.port.mk>
