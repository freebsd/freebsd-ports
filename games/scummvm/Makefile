# New ports collection makefile for:	scummvm
# Date created:				Tue Sep  2 23:34:32 BST 2003
# Whom:				Alex Trull <freebsd.alex@trull.org>
#
# $FreeBSD$
#

PORTNAME=	scummvm
DISTVERSION=	1.1.1
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
		--disable-tremor
CONFIGURE_ENV=	CXX="${CXX}"
 		LDFLAGS="${PTHREAD_LIBS}"

OPTIONS=	VORBIS "Enable Ogg Vorbis support" off \
		MP3 "Enable MP3 support" on \
		MPEG2 "Enable MPEG2 support (implies VORBIS)" on \
		FLAC "Enable FLAC support" off \
		FLUIDSYNTH "Enable FluidSynth MIDI synthesizer" off \
 		MT32EMU "Enable MT-32 emulator" on \
 		X86_ASM "Enable assembly code (i386 only)" on

MAN6=		scummvm.6

PORTDOCS=	AUTHORS NEWS README TODO COPYRIGHT
ENGINEDATA=	drascula.dat \
		kyra.dat \
		lure.dat \
		queen.tbl \
		sky.cpt \
		teenagent.dat

PLIST_FILES=	bin/scummvm %%DATADIR%%/scummmodern.zip \
		%%DATADIR%%/scummvm.svg \
		%%DATADIR%%/scummmodern.zip \
		$(ENGINEDATA:S/^/%%DATADIR%%\/$$/)
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
.if defined(WITH_X86_ASM)
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=--with-nasm-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-nasm
.endif
.endif

.if defined(WITH_MPEG2)
WITH_VORBIS=	yes
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	ogg.7:${PORTSDIR}/audio/libogg \
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
LIB_DEPENDS+=	fluidsynth.4:${PORTSDIR}/audio/fluidsynth
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
