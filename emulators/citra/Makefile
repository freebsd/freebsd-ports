PORTNAME=	citra
PORTVERSION=	s20220902
PORTREVISION?=	4
CATEGORIES=	emulators
.if make(makesum)
MASTER_SITES=	https://api.citra-emu.org/gamedb/?dummy=/:gamedb
.else
MASTER_SITES=	LOCAL/jbeich:gamedb
.endif
DISTFILES=	${PORTNAME}-${DISTVERSIONFULL}/compatibility_list.json:gamedb
EXTRACT_ONLY=	${DISTFILES:N*\:gamedb:C/\:.*//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo 3DS emulator/debugger
WWW=		https://citra-emu.org

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

DEPRECATED=	project has been discontinued and build fails with FFmpeg >7
EXPIRATION_DATE=	2025-10-31
BROKEN_aarch64=	https://github.com/citra-emu/citra/issues/5921

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	citra-emu
GH_TAGNAME=	746609f35
GH_TUPLE=	citra-emu:ext-boost:36603a1:boost/externals/boost \
		citra-emu:ext-libressl-portable:8929f81:libressl/externals/libressl \
		citra-emu:ext-soundtouch:060181e:soundtouch/externals/soundtouch \
		MerryMage:dynarmic:r3-223-g9f88f234:dynarmic/externals/dynarmic \
		arsenm:sanitizers-cmake:aab6948:sanitizers_cmake/externals/cubeb/cmake/sanitizers-cmake \
		arun11299:cpp-jwt:v1.4-14-ge12ef06:cpp_jwt/externals/cpp-jwt \
		benhoyt:inih:r52:inih/externals/inih/inih \
		catchorg:Catch2:v2.13.7:catch/externals/catch \
		facebook:zstd:v1.4.8:zstd/externals/zstd \
		fmtlib:fmt:7.1.2:fmt/externals/fmt \
		herumi:xbyak:v5.96:xbyak/externals/xbyak \
		kinetiknz:cubeb:cubeb-0.2-1350-gf79e0cf:cubeb/externals/cubeb \
		lsalzman:enet:v1.3.17-8-g498b9e3:enet/externals/enet \
		lvandeve:lodepng:31d9704:lodepng/externals/lodepng/lodepng \
		neobrain:nihstro:fd69de1:nihstro/externals/nihstro \
		weidai11:cryptopp:CRYPTOPP_8_5_0:cryptopp/externals/cryptopp/cryptopp \
		wwylele:teakra:01db7cd:teakra/externals/teakra

USES=		cmake:testing compiler:c++17-lang localbase:ldflags sdl
USE_SDL=	sdl2
CMAKE_ON=	USE_SYSTEM_BOOST Boost_USE_STATIC_LIBS
LDFLAGS+=	-Wl,--as-needed # Qt5Network

OPTIONS_DEFINE=	ALSA FFMPEG PULSEAUDIO JACK SNDIO
OPTIONS_DEFAULT=FFMPEG PULSEAUDIO JACK SNDIO
OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
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
QT5_USE=	QT=qmake:build,buildtools:build,linguisttools:build,concurrent:build,core,gui,multimedia,widgets
QT5_CMAKE_BOOL=	ENABLE_QT ENABLE_QT_TRANSLATION
QT5_PLIST_FILES=bin/${PORTNAME}-qt \
		"@comment bin/${PORTNAME}-room" \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/man/man6/${PORTNAME}-qt.6.gz \
		share/mime/packages/${PORTNAME}.xml

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/externals/boost/boost/container_hash/hash.hpp
.endif

post-configure:
	@${CP} ${DISTFILES:M*\:gamedb:C/\:.*//:S,^,${DISTDIR}/,} \
		${BUILD_WRKSRC}/dist/compatibility_list/

.include <bsd.port.post.mk>
