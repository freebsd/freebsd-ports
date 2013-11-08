# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rezound
DISTVERSION=	0.12.3beta
PORTREVISION=	19
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/ReZound/${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file editor

LICENSE=	GPLv2

LIB_DEPENDS=	FOX-1.4:${PORTSDIR}/x11-toolkits/fox14

USES=		bison
NO_STAGE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-alsa
CONFIGURE_ENV+=	ac_cv_path_RESWRAP=${LOCALBASE}/bin/fox-1.4/reswrap
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	LARGEFILE JACK AUDIOFILE PORTAUDIO OGG VORBIS FLAC FFTW \
		SOUNDTOUCH LADSPA LAME CDRDAO DOCS BROKEN_NLS
OPTIONS_DEFAULT=	AUDIOFILE PORTAUDIO OGG VORBIS FLAC SOUNDTOUCH \
		LADSPA LAME

LARGEFILE_DESC=	64-bit file I/O support
FFTW_DESC=	Use fast Fourier transform routines
CDRDAO_DESC=	Burning audio files to CD support
BROKEN_NLS_DESC=	${NLS_DESC} (broken!)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLARGEFILE}
CONFIGURE_ARGS+=	--enable-largefile
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
.endif

.if ${PORT_OPTIONS:MAUDIOFILE}
LIB_DEPENDS+=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	portaudio:${PORTSDIR}/audio/portaudio
.endif

.if ${PORT_OPTIONS:MOGG}
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.endif

.if ${PORT_OPTIONS:MFFTW}
LIB_DEPENDS+=	fftw:${PORTSDIR}/math/fftw
.endif

.if ${PORT_OPTIONS:MSOUNDTOUCH}
LIB_DEPENDS+=	SoundTouch:${PORTSDIR}/audio/soundtouch
.endif

.if ${PORT_OPTIONS:MLADSPA}
RUN_DEPENDS+=	${LOCALBASE}/lib/ladspa/amp.so:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ARGS+=	--disable-ladspa
.endif

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if ${PORT_OPTIONS:MCDRDAO}
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao
.endif

# NLS support is broken as of recent versions of libstdc++; rezound dies at
# startup with "locale::facet::_S_create_c_locale name not valid" exception
.if ${PORT_OPTIONS:MBROKEN_NLS}	# Enable only if you know what you're doing
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -E '/atoll|round|nearbyint/d' \
		${WRKSRC}/config/platform/bsd.h
	${REINPLACE_CMD} -E 's,(_nl_expand_alias \()\),\1...), ; \
		/^C(XX)?FLAGS=/d ; /CXXFLAGS="\$$CXXFLAGS -[gW]/d ; \
		/^return /s,\(int\)( n?gettext),(long)\1,' \
			${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,WORDS_BIGENDIN,WORDS_BIGENDIAN,' \
		${WRKSRC}/src/backend/COSSSoundPlayer.cpp
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
.if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/AUTHORS/d; /COPYING/d' ${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e 's/ install-pkgdocDATA$$//' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
