PORTNAME=	azahar
DISTVERSION=	2126.1.2
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/azahar-emu/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-unified-source-${DISTVERSION}

MAINTAINER=	kreinholz@gmail.com
COMMENT=	Nintendo 3DS emulator/debugger
WWW=		https://azahar-emu.org

LICENSE=	GPLv2+ ISCL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/license.txt
LICENSE_FILE_ISCL=	${WRKSRC}/externals/cubeb/LICENSE

BROKEN_aarch64=	build fails on aarch64 with system boost-libs

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		cpp-httplib>0:www/cpp-httplib \
		glslang>0:graphics/glslang \
		robin-map>0:devel/robin-map \
		spirv-tools>0:graphics/spirv-tools \
		vulkan-headers>0:graphics/vulkan-headers

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libCatch2.so:devel/catch2 \
		libenet.so:net/enet \
		libfaad.so:audio/faad \
		libfmt.so:devel/libfmt \
		libinih.so:devel/inih \
		libSoundTouch.so:audio/soundtouch \
		libxxhash.so:devel/xxhash \
		libZycore.so:devel/zycore-c \
		libZydis.so:devel/zydis

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pkgconfig \
		ssl tar:xz

CMAKE_ON=	Boost_USE_SHARED_LIBS \
		USE_SYSTEM_BOOST \
		USE_SYSTEM_CATCH2 \
		USE_SYSTEM_CPP_HTTPLIB \
		USE_SYSTEM_ENET \
		USE_SYSTEM_FAAD \
		USE_SYSTEM_FMT \
		USE_SYSTEM_GLSLANG \
		USE_SYSTEM_INIH \
		USE_SYSTEM_JSON \
		USE_SYSTEM_OPENSSL \
		USE_SYSTEM_SOUNDTOUCH \
		USE_SYSTEM_SPIRV_TOOLS \
		USE_SYSTEM_SDL2 \
		USE_SYSTEM_VULKAN_HEADERS \
		USE_SYSTEM_XXHASH

CMAKE_OFF=	ENABLE_OPENAL

LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=		ALSA JACK PULSEAUDIO SNDIO VULKAN
OPTIONS_DEFAULT=	JACK PULSEAUDIO SNDIO VULKAN

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

VULKAN_DESC=		Vulkan renderer (experimental)
VULKAN_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=	ENABLE_VULKAN

.if !defined(AZAHAR_SLAVE)
USES+=			desktop-file-utils qt:6 sdl shared-mime-info
USE_QT=			base multimedia svg tools:build translations:run
USE_SDL=		sdl2

CMAKE_ON+=		ENABLE_QT \
			ENABLE_QT_TRANSLATION \
			ENABLE_SDL2
.endif

.if defined(AZAHAR_SLAVE)
CMAKE_ON+=		ENABLE_LIBRETRO \
			CMAKE_POSITION_INDEPENDENT_CODE
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		-e 's/@BUILD_FULLNAME@/${DISTVERSION}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

.if defined(AZAHAR_SLAVE)
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/libretro
	${INSTALL_LIB} ${BUILD_WRKSRC}/bin/Release/${PORTNAME}_libretro.so \
		${STAGEDIR}${PREFIX}/lib/libretro/
.  for d in applications icons mime ${PORTNAME}
	${RM} -r ${STAGEDIR}${PREFIX}/share/${d}
.  endfor
.else
post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libcitra_room.a
.endif

.include <bsd.port.post.mk>
