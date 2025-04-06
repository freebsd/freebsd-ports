PORTNAME=	furnace
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.8.1
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

USES=		cmake desktop-file-utils gl localbase:ldflags pkgconfig sdl \
		shared-mime-info tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	tildearrow
GH_TUPLE=	libsdl-org:SDL:2359383fc:sdl/extern/SDL \
		superctr:adpcm:ef7a21715:adpcm/extern/adpcm \
		fmtlib:fmt:e57ca2e36:fmt/extern/fmt
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

OPTIONS_DEFINE=	DOCS JACK NLS
OPTIONS_SUB=	yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_OFF=		-DWITH_JACK:BOOL=OFF

NLS_USES=	gettext-runtime
NLS_CMAKE_ON=	-DWITH_LOCALE:BOOL=ON
NLS_CMAKE_OFF=	-DWITH_LOCALE:BOOL=OFF

post-install:
	${INSTALL_DATA} \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/1024x1024/apps/furnace.png \
		${STAGEDIR}${PREFIX}/share/icons/

# maintainer section
maketuples:
	submodules2tuple -b ${DISTVERSIONPREFIX}${DISTVERSION} ${WWW}

.include <bsd.port.mk>
