PORTNAME=	dosbox-staging
DISTVERSIONPREFIX=	v
DISTVERSION=	0.78.0
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	DOS/x86 emulator based on DOSBox

LICENSE=	GPLv2

LIB_DEPENDS=	libopusfile.so:audio/opusfile \
		libpng.so:graphics/png \
		libslirp.so:net/libslirp

USES=		compiler:c++14-lang gl meson pkgconfig sdl

USE_GL=		gl
USE_SDL=	sdl2 net2
USE_GITHUB=	yes

MESON_ARGS=	-Duse_mt32emu=false
LDFLAGS+=	-pthread

OPTIONS_DEFINE=	ALSA DOCS FLUIDSYNTH
OPTIONS_DEFAULT=	FLUIDSYNTH

ALSA_DESC=		ALSA midi support
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MESON_TRUE=	use_alsa

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_MESON_TRUE=	use_fluidsynth

post-patch:
	@${REINPLACE_CMD} 's,/usr/share/doc/dosbox-staging,${DOCSDIR},' \
		${WRKSRC}/docs/dosbox.1
	${MV} ${WRKSRC}/docs/dosbox.1 ${WRKSRC}/docs/dosbox-staging.1
	@${REINPLACE_CMD} '/^Exec/s,dosbox,dosbox-staging,' \
		${WRKSRC}/contrib/linux/dosbox-staging.desktop

.include <bsd.port.mk>
