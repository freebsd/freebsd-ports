# Created by: Alex Trull <freebsd.alex@trull.org>
# $FreeBSD$

PORTNAME=	scummvm
DISTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	games emulators
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Interpreter for several adventure games

USE_BZIP2=	yes
USES=		gmake
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

.include <bsd.port.options.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${PORT_OPTIONS:MMP3}
LIB_DEPENDS+=	libmad.so:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--with-mad-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--with-png-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-png
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--with-flac-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
LIB_DEPENDS+=	libfluidsynth.so:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=--with-fluidsynth-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-fluidsynth
.endif

.if empty(PORT_OPTIONS:MMT32EMU)
CONFIGURE_ARGS+=--disable-mt32emu
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/dists/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/

.include <bsd.port.mk>
