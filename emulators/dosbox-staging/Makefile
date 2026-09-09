PORTNAME=	dosbox-staging
DISTVERSIONPREFIX=	v
DISTVERSION=	0.83.0
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	DOS/x86 emulator based on DOSBox
WWW=		https://dosbox-staging.github.io/

BUILD_DEPENDS=	${LOCALBASE}/include/asio.hpp:net/asio
LIB_DEPENDS=	libz-ng.so:archivers/zlib-ng \
		libasound.so:audio/alsa-lib \
		libfluidsynth.so:audio/fluidsynth \
		libiir.so:audio/iir1 \
		libopusfile.so:audio/opusfile \
		libspeexdsp.so:audio/speexdsp \
		libpng.so:graphics/png \
		libslirp.so:net/libslirp

USES=		cmake compiler:c++20-lang gl localbase:ldflags pkgconfig sdl

USE_GL=		gl
USE_SDL=	sdl2 image2
USE_GITHUB=	yes

CMAKE_ON=	USE_SYSTEM_LIBS
CMAKE_OFF=	OPT_TESTS
LDFLAGS+=	-pthread

OPTIONS_DEFINE=		DOCS MT32EMU
OPTIONS_DEFAULT=	MT32EMU

MT32EMU_DESC=		MIDI playback support via mt32emu
MT32EMU_LIB_DEPENDS=	libmt32emu.so:emulators/libmt32emu
MT32EMU_CMAKE_BOOL=	OPT_MT32EMU

post-patch:
	@${SED} -i '' '1s,bash,sh,' ${WRKSRC}/scripts/ci/get-version.sh
	@${REINPLACE_CMD} '/^Exec/s,dosbox,dosbox-staging,' \
		${WRKSRC}/extras/linux/org.dosbox_staging.dosbox_staging.desktop

post-install:
	${MV} ${STAGEDIR}/${PREFIX}/bin/dosbox ${STAGEDIR}/${PREFIX}/bin/dosbox-staging

.include <bsd.port.mk>
