# New ports collection makefile for:	scummvm
# Date created:				Tue Sep  2 23:34:32 BST 2003
# Whom:				Alex Trull <freebsd.alex@trull.org>
#
# $FreeBSD$
#

PORTNAME=	scummvm
DISTVERSION=	1.0.0
CATEGORIES=	games emulators
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Graphical Adventure Game Virtual Machine

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_SDL=	sdl

MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=--with-sdl-prefix=${LOCALBASE} \
		--disable-alsa \
		--with-zlib-prefix=/usr \
		--disable-debug \
		--disable-tremor
CONFIGURE_ENV=	CXX="${CXX}"

OPTIONS=	VORBIS "Enable Ogg Vorbis support" off \
		MAD "Enable mad (MP3) support" on \
		MPEG2 "Enable MPEG2 support (implies VORBIS)" on \
		FLAC "Enable FLAC support" off \
		FLUIDSYNTH "Enable FluidSynth MIDI synthesizer" off \
		DPLUGINS "Enable support for dynamic plugins" off

MAN6=		scummvm.6

PORTDOCS=	NEWS README TODO
PLIST_FILES=	bin/scummvm

.include <bsd.port.pre.mk>

.if defined(WITH_MPEG2)
WITH_VORBIS=	yes
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	ogg.6:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--with-mad-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if defined(WITH_MPEG2)
WITH_VORBIS=	yes
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
CONFIGURE_ARGS+=--with-mpeg2-prefix=${LOCALBASE} --enable-mpeg2
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--with-flac-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if defined(WITH_FLUIDSYNTH)
LIB_DEPENDS+=	fluidsynth.2:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=--with-fluidsynth-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-fluidsynth
.endif

.if defined(WITH_DPLUGINS)
CONFIGURE_ARGS+=	--enable-plugins
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-O//' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/-lfluidsynth/& ${PTHREAD_LIBS}/' ${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/dists/scummvm.6 ${PREFIX}/man/man6

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
