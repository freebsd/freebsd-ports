# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	alure
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/alure-releases/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Utility library to help manage common tasks with OpenAL

LICENSE=	MIT

LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile

USE_OPENAL=	soft
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_VERBOSE=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

OPTIONS_DEFINE=		VORBIS FLAC MPG123 DUMB MODPLUG FLUIDSYNTH DOCS EXAMPLES
OPTIONS_DEFAULT=	VORBIS FLAC DUMB

DUMB_DESC=		DUMB audio library decoding support
MODPLUG_DESC=		MOD decoding via ModPlug
FLUIDSYNTH_DESC=	MIDI support via FluidSynth

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
PLIST_SUB+=	VORBIS=""
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
PLUGIN_OPTIONS_CMAKE+=	-DUSE_VORBIS:BOOL=TRUE
.else
PLIST_SUB+=	VORBIS="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_VORBIS:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MFLAC}
PLIST_SUB+=	FLAC=""
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLAC:BOOL=TRUE
.else
PLIST_SUB+=	FLAC="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLAC:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MMPG123}
PLIST_SUB+=	MPG123=""
LIB_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPG123:BOOL=TRUE
.else
PLIST_SUB+=	mpg123="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPG123:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MDUMB}
PLIST_SUB+=	DUMB=""
BUILD_DEPENDS+=	${LOCALBASE}/include/dumb.h:${PORTSDIR}/audio/dumb-allegro
PLUGIN_OPTIONS_CMAKE+=	-DUSE_DUMB:BOOL=TRUE
.else
PLIST_SUB+=	DUMB="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_DUMB:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MMODPLUG}
PLIST_SUB+=	MODPLUG=""
BUILD_DEPENDS+=	${LOCALBASE}/include/libmodplug/modplug.h:${PORTSDIR}/audio/libmodplug
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MODPLUG:BOOL=TRUE
.else
PLIST_SUB+=	MODPLUG="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MODPLUG:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
PLIST_SUB+=	FLUIDSYNTH=""
LIB_DEPENDS+=	fluidsynth:${PORTSDIR}/audio/fluidsynth
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLUIDSYNTH:BOOL=TRUE
.else
PLIST_SUB+=	FLUIDSYNTH="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLUIDSYNTH:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	NaturalDocs:${PORTSDIR}/devel/naturaldocs
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' \
		-e 's|"ModPlug support (for IT/XM/S3M/MOD)" OFF)|"ModPlug support (for IT/XM/S3M/MOD)" ON)|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/lib/pkgconfig|/libdata/pkgconfig|' \
		${WRKSRC}/XCompile.txt

.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} \
		-e 's|INSTALL(DIRECTORY "$${ALURE_SOURCE_DIR}/docs/html"|INSTALL(DIRECTORY "$${ALURE_SOURCE_DIR}/docs/html" "$${ALURE_SOURCE_DIR}/docs/naturaldocs"|' \
		${WRKSRC}/CMakeLists.txt
.endif

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i '' '/FIND_PROGRAM(NATDOCS_BIN NaturalDocs)/,/ENDIF(NATDOCS_BIN)/s/^/#/' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i '' -e '/INSTALL(DIRECTORY "$${ALURE_SOURCE_DIR}/,+2d' ${WRKSRC}/CMakeLists.txt
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
