# Created by: Alex Trull <freebsd.alex@trull.org>
# $FreeBSD$

PORTNAME=	scummvm
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	games emulators
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Interpreter for several adventure games

USES=		gmake tar:bzip2
HAS_CONFIGURE=	yes
USE_SDL=	sdl

CONFIGURE_ARGS=	--with-sdl-prefix=${LOCALBASE} \
		--disable-alsa \
		--with-zlib-prefix=/usr \
		--disable-debug \
		--disable-nasm \
		--disable-tremor
LDFLAGS+=	${PTHREAD_LIBS}

OPTIONS_DEFINE=	VORBIS MP3 PNG FLAC FLUIDSYNTH MT32EMU DOCS
FLUIDSYNTH_DESC=	FluidSynth MIDI synthesizer
MT32EMU_DESC=	MT-32 emulator
OPTIONS_DEFAULT=	VORBIS MP3 PNG MT32EMU

VORBIS_LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg \
			libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_ON=	--with-ogg-prefix=${LOCALBASE} \
			--with-vorbis-prefix=${LOCALBASE}
VORBIS_CONFIGURE_OFF=	--disable-vorbis

MP3_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad
MP3_CONFIGURE_ON=	--with-mad-prefix=${LOCALBASE}
MP3_CONFIGURE_OFF=	--disable-mad

PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_ON=	--with-png-prefix=${LOCALBASE}
PNG_CONFIGURE_OFF=	--disable-png

FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CONFIGURE_ON=	--with-flac-prefix=${LOCALBASE}
FLAC_CONFIGURE_OFF=	--disable-flac

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:${PORTSDIR}/audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ON=	--with-fluidsynth-prefix=${LOCALBASE}
FLUIDSYNTH_CONFIGURE_OFF=	--disable-fluidsynth

MT32EMU_CONFIGURE_OFF=	--disable-mt32emu

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^mandir=/s/datarootdir/prefix/' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/dists/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
