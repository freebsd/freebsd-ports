# $FreeBSD$

PORTNAME=	citra
PORTVERSION=	s20200329
PORTREVISION?=	0
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Nintendo 3DS emulator/debugger

LICENSE=	BSD2CLAUSE BSD3CLAUSE BSL GPLv2+ ISCL LGPL21+ MIT OpenSSL UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/externals/fmt/LICENSE.rst
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/externals/inih/inih/LICENSE.txt
LICENSE_FILE_BSL=	${WRKSRC}/externals/catch/LICENSE.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/license.txt
LICENSE_FILE_ISCL=	${WRKSRC}/externals/cubeb/LICENSE
LICENSE_FILE_LGPL21+ =	${_LICENSE_STORE}/LGPL21 # soundtouch
LICENSE_FILE_MIT=	${WRKSRC}/externals/enet/LICENSE
LICENSE_FILE_OpenSSL=	${WRKSRC}/externals/libressl/COPYING

BUILD_DEPENDS=	boost-libs>=1.66:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	citra-emu
GH_TAGNAME=	680ef64ac
GH_TUPLE=	citra-emu:ext-libressl-portable:7d01cb0:libressl/externals/libressl \
		citra-emu:ext-soundtouch:060181e:soundtouch/externals/soundtouch \
		MerryMage:dynarmic:r1-992-g4e6848d1:dynarmic/externals/dynarmic \
		arsenm:sanitizers-cmake:aab6948:sanitizers_cmake/externals/cubeb/cmake/sanitizers-cmake \
		arun11299:cpp-jwt:v1.1.1:cpp_jwt/externals/cpp-jwt \
		benhoyt:inih:r42-6-g2023872:inih/externals/inih/inih \
		catchorg:Catch2:v2.3.0:catch/externals/catch \
		facebook:zstd:v1.4.4:zstd/externals/zstd \
		fmtlib:fmt:6.0.0-56-g4b8f8fac:fmt/externals/fmt \
		herumi:xbyak:v5.71:xbyak/externals/xbyak \
		kinetiknz:cubeb:cubeb-0.2-1172-g3ab5075:cubeb/externals/cubeb \
		lsalzman:enet:0eaf48e:enet/externals/enet \
		lvandeve:lodepng:31d9704:lodepng/externals/lodepng/lodepng \
		neobrain:nihstro:fd69de1:nihstro/externals/nihstro \
		weidai11:cryptopp:CRYPTOPP_7_0_0-23-gf320e7d9:cryptopp/externals/cryptopp/cryptopp \
		wwylele:teakra:e6ea0ea:teakra/externals/teakra

USES=		cmake compiler:c++17-lang iconv localbase:ldflags sdl
USE_SDL=	sdl2
LDFLAGS+=	-Wl,--as-needed # Qt5Network
TEST_TARGET=	test

OPTIONS_DEFINE=	ALSA FFMPEG PULSEAUDIO JACK SNDIO
OPTIONS_DEFAULT=ALSA FFMPEG PULSEAUDIO JACK SNDIO
OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CMAKE_BOOL=	USE_ALSA

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	ENABLE_FFMPEG_AUDIO_DECODER ENABLE_FFMPEG_VIDEO_DUMPER

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

SDL_CMAKE_BOOL=	ENABLE_SDL2
SDL_PLIST_FILES=bin/${PORTNAME} \
		bin/${PORTNAME}-room \
		share/man/man6/${PORTNAME}.6.gz

QT5_USES=	desktop-file-utils qt:5 shared-mime-info
QT5_USE=	QT=qmake_build,buildtools_build,concurrent_build,core,gui,multimedia,opengl,widgets
QT5_CMAKE_BOOL=	ENABLE_QT
QT5_PLIST_FILES=bin/${PORTNAME}-qt \
		"@comment bin/${PORTNAME}-room" \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/man/man6/${PORTNAME}-qt.6.gz \
		share/mime/packages/${PORTNAME}.xml

post-patch:
	@${REINPLACE_CMD} -e '/check_submodules_present()/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

.include <bsd.port.mk>
