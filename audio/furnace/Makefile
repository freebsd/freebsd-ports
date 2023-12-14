PORTNAME=	furnace
PORTVERSION=	0.6
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Chiptune tracker compatible with DefleMask modules (.dmf)
WWW=		https://github.com/tildearrow/furnace

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfmt.so:devel/libfmt \
		librtmidi.so:audio/rtmidi \
		libsndfile.so:audio/libsndfile

USES=		cmake gl localbase:ldflags pkgconfig sdl tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	tildearrow
GH_TUPLE=	libsdl-org:SDL:ffa78e6b:sdl/extern/SDL \
		superctr:adpcm:ef7a2171:adpcm/extern/adpcm \
		fmtlib:fmt:e57ca2e3:fmt/extern/fmt \
		libsndfile:libsndfile:ca200890:libsndfile/extern/libsndfile \
		PortAudio:portaudio:6ee9836a:portaudio/extern/portaudio
USE_GL=		gl
USE_SDL=	sdl2

CMAKE_ARGS+=	-DBUILD_GUI:BOOL=ON \
		-DSYSTEM_FMT:BOOL=ON \
		-DSYSTEM_LIBSNDFILE:BOOL=ON \
		-DSYSTEM_RTMIDI=ON \
		-DSYSTEM_SDL2:BOOL=ON \
		-DSYSTEM_ZLIB:BOOL=ON

# tags are bogus, ignore until 0.6 is released
PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	DOCS JACK

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_OFF=		-DWITH_JACK:BOOL=OFF

post-install:
	${INSTALL_DATA} \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/1024x1024/apps/furnace.png \
		${STAGEDIR}${PREFIX}/share/icons/

.include <bsd.port.mk>
