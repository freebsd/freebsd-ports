# New ports collection makefile for:	ReZound
# Date created:				17 May 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rezound
DISTVERSION=	0.12.3beta
PORTREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/ReZound/${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file editor

LICENSE=	GPLv2

LIB_DEPENDS=	FOX-1.4:${PORTSDIR}/x11-toolkits/fox14

USE_BISON=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-alsa
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	LARGEFILE	"Enable 64-bit file I/O support"	off \
		JACK		"Enable Jack audio server support"	off \
		AUDIOFILE	"Enable Audio File library support"	on \
		PORTAUDIO	"Enable PortAudio support"		on \
		OGG		"Enable OGG support"			on \
		VORBIS		"Enable Vorbis support"			on \
		FLAC		"Enable FLAC support"			on \
		FFTW		"Enable FFTW support"			off \
		SOUNDTOUCH	"Enable SoundTouch features"		on \
		LADSPA		"Enable LADSPA plugins support"		on \
		LAME		"Enable loading and saving MP3 files"	on \
		CDRDAO		"Enable burning audio files to CD"	off
#		BROKEN_NLS	"Enable Native Language Support"	on
# NLS support is broken as of recent versions of libstdc++; rezound dies at
# startup with "locale::facet::_S_create_c_locale name not valid" exception

.include <bsd.port.pre.mk>

.if defined(WITH_LARGEFILE)
CONFIGURE_ARGS+=	--enable-largefile
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
.endif

.if defined(WITH_AUDIOFILE)
LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile
.endif

.if defined(WITH_PORTAUDIO)
LIB_DEPENDS+=	portaudio:${PORTSDIR}/audio/portaudio
.endif

.if defined(WITH_OGG)
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_FFTW)
LIB_DEPENDS+=	fftw:${PORTSDIR}/math/fftw
.endif

.if defined(WITH_SOUNDTOUCH)
LIB_DEPENDS+=	SoundTouch:${PORTSDIR}/audio/soundtouch
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

.if defined(WITH_BROKEN_NLS)	# Enable only if you know what you're doing
USE_GETTEXT=	yes
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
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's/ install-pkgdocDATA$$//' ${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e '/AUTHORS/d; /COPYING/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
