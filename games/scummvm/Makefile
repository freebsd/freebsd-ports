# New ports collection makefile for:	scummvm
# Date created:				Tue Sep  2 23:34:32 BST 2003
# Whom:				Alex Trull <freebsd.alex@trull.org>
#
# $FreeBSD$
#

PORTNAME=	scummvm
DISTVERSION=	1.5.0
CATEGORIES=	games emulators
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Interpreter for several adventure games

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_SDL=	sdl

MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-sdl-prefix=${LOCALBASE} \
		--disable-alsa \
		--with-zlib-prefix=/usr \
		--disable-debug \
		--disable-nasm \
		--disable-tremor
LDFLAGS+=	${PTHREAD_LIBS}

OPTIONS_DEFINE=	VORBIS MP3 FLAC FLUIDSYNTH MT32EMU
FLUIDSYNTH_DESC=	FluidSynth MIDI synthesizer
MT32EMU_DESC=	MT-32 emulator
OPTIONS_DEFAULT=	VORBIS MP3 MT32EMU

MAN6=		scummvm.6

PORTDOCS=	AUTHORS NEWS README TODO COPYRIGHT
ENGINEDATA=	drascula.dat \
		hugo.dat \
		kyra.dat \
		lure.dat \
		queen.tbl \
		sky.cpt \
		toon.dat \
		teenagent.dat

DESKTOP_ENTRIES="ScummVM" \
		"ScummVM - Run classic adventure games" \
		"${DATADIR}/scummvm.svg" \
		"scummvm" \
		"Application;Game;" \
		false

PLIST_FILES=	bin/scummvm \
		%%DATADIR%%/scummvm.svg \
		%%DATADIR%%/scummmodern.zip \
		%%DATADIR%%/translations.dat \
		$(ENGINEDATA:S/^/%%DATADIR%%\/$$/)
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${PORT_OPTIONS:MMP3}
LIB_DEPENDS+=	mad:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--with-mad-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--with-flac-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
LIB_DEPENDS+=	fluidsynth:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=--with-fluidsynth-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-fluidsynth
.endif

.if empty(PORT_OPTIONS:MMT32EMU)
CONFIGURE_ARGS+=--disable-mt32emu
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/dists/scummvm.6 ${MAN6PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/icons/scummvm.svg ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/gui/themes/scummmodern.zip ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/gui/themes/translations.dat ${DATADIR}
.for i in ${ENGINEDATA}
	@${INSTALL_DATA} ${WRKSRC}/dists/engine-data/${i} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
