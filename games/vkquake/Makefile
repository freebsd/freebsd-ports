PORTNAME=	vkquake
DISTVERSION=	1.34.1
CATEGORIES=	games

MAINTAINER=	seafork@disroot.org
COMMENT=	Vulkan Quake port based on QuakeSpasm
WWW=		https://github.com/Novum/vkQuake

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USES=		compiler:c11 meson pkgconfig sdl

USE_GITHUB=	yes
GH_ACCOUNT=	Novum
GH_PROJECT=	vkQuake

.include "${.CURDIR}/../quake-data/Makefile.include"

CFLAGS+=	-DDATADIR='\"${Q1DIR}\"' -Wno-error=atomic-alignment
LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=			DEBUG FLAC OPUS USERDIRS VORBIS WAVE
OPTIONS_DEFAULT=		FLAC MP3 OPUS SDL2 USERDIRS VORBIS WAVE
OPTIONS_RADIO=			MP3LIBRARY
OPTIONS_RADIO_MP3LIBRARY=	MAD MP3
OPTIONS_SINGLE=			SDL
OPTIONS_SINGLE_SDL=		SDL2 SDL3

MP3LIBRARY_DESC=	MP3 audio library
SDL2_DESC=		SDL-2.x support
SDL3_DESC=		SDL-3.x support
USERDIRS_DESC=		Support loading game data from user directories (~/.vkquake)
WAVE_DESC=		Wave audio support

DEBUG_MESON_ON=		--buildtype=debug --optimization=0
DEBUG_MESON_OFF=	--buildtype=plain --optimization=2
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_MESON_ENABLED=	use_codec_flac
MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_MESON_ENABLED=	use_codec_mp3
MAD_MESON_ON=		-Dmp3_lib=mad
MP3_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MP3_MESON_ENABLED=	use_codec_mp3
MP3_MESON_ON=		-Dmp3_lib=mpg123
OPUS_LIB_DEPENDS=	libopus.so:audio/opus \
			libopusfile.so:audio/opusfile
OPUS_MESON_ENABLED=	use_codec_opus
SDL2_USE=		SDL=sdl2
SDL2_MESON_FALSE=	use_sdl3
SDL3_USE=		SDL=sdl3
USERDIRS_MESON_ENABLED=	do_userdirs
VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis \
			libvorbisfile.so:audio/libvorbis
VORBIS_MESON_ENABLED=	use_codec_vorbis
WAVE_MESON_ENABLED=	use_codec_wave

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${MESON_BUILD_DIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${Q1DIR} \
		 ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps \
		 ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/_build/vkquake.pak \
		${STAGEDIR}${Q1DIR}
	${INSTALL_DATA} ${WRKSRC}/Misc/vkQuake_256.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/vkquake.png
	${INSTALL_DATA} ${WRKSRC}/Misc/vkQuake_512.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/vkquake.png
	${INSTALL_DATA} ${FILESDIR}/vkquake.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
