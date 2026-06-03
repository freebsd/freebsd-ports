PORTNAME=	dosbox-staging
DISTVERSIONPREFIX=	v
DISTVERSION=	0.82.2
PORTREVISION=	2
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	DOS/x86 emulator based on DOSBox
WWW=		https://dosbox-staging.github.io/

LICENSE=	GPLv2

LIB_DEPENDS=	libz-ng.so:archivers/zlib-ng \
		libiir.so:audio/iir1 \
		libopusfile.so:audio/opusfile \
		libspeexdsp.so:audio/speexdsp \
		libpng.so:graphics/png \
		libslirp.so:net/libslirp

USES=		compiler:c++17-lang gl meson pkgconfig sdl

USE_GL=		gl
USE_SDL=	sdl2 net2
USE_GITHUB=	yes

MESON_ARGS=	-Dunit_tests=disabled
LDFLAGS+=	-pthread

OPTIONS_DEFINE=		ALSA DOCS FLUIDSYNTH MT32EMU
OPTIONS_DEFAULT=	FLUIDSYNTH MT32EMU

ALSA_DESC=		ALSA midi support
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MESON_TRUE=	use_alsa

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_MESON_TRUE=	use_fluidsynth

MT32EMU_DESC=		MIDI playback support via mt32emu
MT32EMU_LIB_DEPENDS=	libmt32emu.so:emulators/libmt32emu
MT32EMU_MESON_TRUE=	use_mt32emu

.if defined(PACKAGE_BUILDING)
# Disable SIMD autodetection
# https://github.com/dosbox-staging/dosbox-staging/issues/4020
MESON_ARGS+=	-Duse_zlib_ng=sse2,ssse3,neon
.endif

post-patch:
	@${SED} -i '' '1s,bash,sh,' ${WRKSRC}/scripts/get-version.sh
	@${REINPLACE_CMD} 's,/usr/share/doc/dosbox-staging,${DOCSDIR},' \
		${WRKSRC}/docs/dosbox.1
	${MV} ${WRKSRC}/docs/dosbox.1 ${WRKSRC}/docs/dosbox-staging.1
	@${REINPLACE_CMD} '/^Exec/s,dosbox,dosbox-staging,' \
		${WRKSRC}/contrib/linux/org.dosbox-staging.dosbox-staging.desktop

.include <bsd.port.mk>
