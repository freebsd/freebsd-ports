# New ports collection makefile for:	ReZound
# Date created:				17 May 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rezound
DISTVERSION=	0.12.0beta
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file editor

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	FOX-1.4.7:${PORTSDIR}/x11-toolkits/fox-devel

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
CONFIGURE_ARGS+=	--disable-alsa
USE_REINPLACE=	yes

OPTIONS=	LARGEFILE	"Enable 64-bit file I/O support (BROKEN!)" off \
		JACK		"Enable Jack audio server support" on \
		AUDIOFILE	"Enable Audio File Library support" on \
		PORTAUDIO	"Enable PortAudio support" on \
		OGG		"Enable OGG support" on \
		VORBIS		"Enable Vorbis support" on \
		FLAC		"Enable FLAC support" on \
		FFTW		"Enable FFTW support" on \
		SOUNDTOUCH	"Enable SoundTouch features" on \
		LADSPA		"Enable LADSPA plugin support" on \
		LAME		"Enable loading and saving MP3s" on \
		CDRDAO		"Enable burning audio files to CD" on \
		NLS		"Enable National Language Support" on

.include <bsd.port.pre.mk>

.if defined(WITH_LARGEFILE)
CONFIGURE_ARGS+=	--enable-largefile
BROKEN=		"no expl(), logl(), nearbyintl(), et al"
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.endif

.if defined(WITH_AUDIOFILE)
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
.endif

.if defined(WITH_PORTAUDIO)
LIB_DEPENDS+=	portaudio.0:${PORTSDIR}/audio/portaudio
.endif

.if defined(WITH_OGG)
LIB_DEPENDS=	ogg.5:${PORTSDIR}/audio/libogg
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_FFTW)
BUILD_DEPENDS+=	${LOCALBASE}/include/fftw.h:${PORTSDIR}/math/fftw
.endif

.if defined(WITH_SOUNDTOUCH)
BUILD_DEPENDS+=	${LOCALBASE}/include/soundtouch/SoundTouch.h:${PORTSDIR}/audio/soundtouch
.endif

.if defined(WITH_LADSPA)
RUN_DEPENDS+=	${LOCALBASE}/lib/ladspa/amp.so:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ARGS+=	--disable-ladspa
.endif

.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_CDRDAO)
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch: .SILENT
.if ${OSVERSION} > 500027
	${REINPLACE_CMD} -e '/atoll/d' ${WRKSRC}/config/platform/bsd.h
.endif
.if ${OSVERSION} > 502112
	${REINPLACE_CMD} -e '/round/d' ${WRKSRC}/config/platform/bsd.h
.endif
.if ${OSVERSION} > 502120
	${REINPLACE_CMD} -e '/nearbyint/d' ${WRKSRC}/config/platform/bsd.h
.endif
	${REINPLACE_CMD} -E 's,(_nl_expand_alias \()\),\1...),' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,$$(prefix)/doc,$$(datadir)/doc,' \
		${WRKSRC}/config/am_include.mk ${WRKSRC}/Makefile.in \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/src/misc/Makefile.in \
		${WRKSRC}/src/misc/CNestedDataFile/Makefile.in \
		${WRKSRC}/src/PoolFile/Makefile.in \
		${WRKSRC}/src/backend/DSP/Makefile.in \
		${WRKSRC}/src/backend/Makefile.in \
		${WRKSRC}/src/backend/File/Makefile.in \
		${WRKSRC}/src/backend/Edits/Makefile.in \
		${WRKSRC}/src/backend/Effects/Makefile.in \
		${WRKSRC}/src/backend/Filters/Makefile.in \
		${WRKSRC}/src/backend/Looping/Makefile.in \
		${WRKSRC}/src/backend/Generate/Makefile.in \
		${WRKSRC}/src/backend/Remaster/Makefile.in \
		${WRKSRC}/src/backend/LADSPA/Makefile.in \
		${WRKSRC}/src/frontend_fox/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's/ install-pkgdocDATA$$//' ${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e '/AUTHORS/d; /COPYING/d' ${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/key_bindings.dat ${DATADIR}

.include <bsd.port.post.mk>
