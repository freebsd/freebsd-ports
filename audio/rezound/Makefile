# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rezound
DISTVERSION=	0.12.3beta
PORTREVISION=	20
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/ReZound/${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file editor

LICENSE=	GPLv2

LIB_DEPENDS=	libFOX-1.4.so:${PORTSDIR}/x11-toolkits/fox14

USES=		bison
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lX11
CONFIGURE_ARGS=	--disable-alsa
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ENV=	ac_cv_path_RESWRAP=${LOCALBASE}/bin/fox-1.4/reswrap

OPTIONS_DEFINE=	LARGEFILE JACK AUDIOFILE PORTAUDIO OGG VORBIS FLAC FFTW \
		SOUNDTOUCH LADSPA LAME CDRDAO DOCS BROKEN_NLS
OPTIONS_DEFAULT=	AUDIOFILE PORTAUDIO OGG VORBIS FLAC SOUNDTOUCH \
		LADSPA LAME

LARGEFILE_DESC=	Use 64-bit file I/O
FFTW_DESC=	Use fast Fourier transform routines
CDRDAO_DESC=	Burning audio files to CD support
BROKEN_NLS_DESC=	${NLS_DESC} (broken!)

LARGEFILE_CONFIGURE_ON=	--enable-largefile
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
AUDIOFILE_LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:${PORTSDIR}/audio/portaudio
OGG_LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FFTW_LIB_DEPENDS=	libfftw.so:${PORTSDIR}/math/fftw
SOUNDTOUCH_LIB_DEPENDS=	libSoundTouch.so:${PORTSDIR}/audio/soundtouch
LADSPA_RUN_DEPENDS=	${LOCALBASE}/lib/ladspa/amp.so:${PORTSDIR}/audio/ladspa
LADSPA_CONFIGURE_OFF=	--disable-ladspa
LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame
CDRDAO_RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao

.include <bsd.port.options.mk>

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
# Fix some sloppy C++ coding which upsets Clang
	${REINPLACE_CMD} -e '/&string_to_anytype/s,static ,,' \
		${WRKSRC}/src/misc/CNestedDataFile/anytype.h
	${REINPLACE_CMD} -e 's,push_back((,this->&,' \
		${WRKSRC}/src/misc/auto_array.h
	${REINPLACE_CMD} -e 's,overflowWrite(,this->&,' \
		${WRKSRC}/src/PoolFile/TPoolAccesser.cpp
	${REINPLACE_CMD} -e 's,map<string,map<const string,' \
		${WRKSRC}/src/PoolFile/TPoolFile.cpp
.if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/AUTHORS/d; /COPYING/d' ${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e 's/ install-pkgdocDATA$$//' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
