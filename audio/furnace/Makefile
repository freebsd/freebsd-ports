PORTNAME=	furnace
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.8.3
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Chiptune tracker compatible with DefleMask modules (.dmf)
WWW=		https://github.com/tildearrow/furnace

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3.so:math/fftw3 \
		libfmt.so:devel/libfmt \
		libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile \
		libportaudio.so:audio/portaudio \
		librtmidi.so:audio/rtmidi \

USES=		cmake compiler:c++14-lang desktop-file-utils gl \
		localbase:ldflags pkgconfig sdl shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	tildearrow
GH_TUPLE=	superctr:adpcm:ef7a21715:adpcm/extern/adpcm
USE_GL=		gl
USE_SDL=	sdl2

CMAKE_ON=	SYSTEM_FFTW \
		SYSTEM_FMT \
		SYSTEM_FREETYPE \
		SYSTEM_LIBSNDFILE \
		SYSTEM_PORTAUDIO \
		SYSTEM_RTMIDI \
		SYSTEM_SDL2 \
		SYSTEM_ZLIB
CMAKE_OFF=	WITH_RENDER_OPENGL1

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/extern/fftw \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/extern/fmt \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/extern/freetype \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/extern/libsndfile-modified \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/extern/portaudio \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/extern/rtmidi \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/extern/SDL \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/extern/zlib \
			--no-same-owner --no-same-permissions

# bogus tags
PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	DOCS JACK NLS
OPTIONS_SUB=	yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	WITH_JACK

NLS_USES=	gettext-runtime
NLS_CMAKE_BOOL=	WITH_LOCALE

post-install:
	${INSTALL_DATA} \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/1024x1024/apps/furnace.png \
		${STAGEDIR}${PREFIX}/share/icons/

# maintainer section
maketuples:
	submodules2tuple -b ${DISTVERSIONPREFIX}${DISTVERSION} ${WWW}

.include <bsd.port.mk>
