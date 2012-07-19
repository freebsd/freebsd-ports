# New ports collection makefile for:	scummvm
# Date created:				Tue Sep  2 23:34:32 BST 2003
# Whom:				Alex Trull <freebsd.alex@trull.org>
#
# $FreeBSD$
#

PORTNAME=	scummvm
DISTVERSION=	1.4.1
PORTREVISION=	3
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

OPTIONS=	VORBIS "Enable Ogg Vorbis support" on \
		MP3 "Enable MP3 support" on \
		FLAC "Enable FLAC support" off \
		FLUIDSYNTH "Enable FluidSynth MIDI synthesizer" off \
 		MT32EMU "Enable MT-32 emulator" on \

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

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if defined(WITH_MP3)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--with-mad-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--with-flac-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if defined(WITH_FLUIDSYNTH)
LIB_DEPENDS+=	fluidsynth.1:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=--with-fluidsynth-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-fluidsynth
.endif

.if defined(WITHOUT_MT32EMU)
CONFIGURE_ARGS+=--disable-mt32emu
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/dists/scummvm.6 ${PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/icons/scummvm.svg ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/gui/themes/scummmodern.zip ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/gui/themes/translations.dat ${DATADIR}
.for i in ${ENGINEDATA}
	@${INSTALL_DATA} ${WRKSRC}/dists/engine-data/${i} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
