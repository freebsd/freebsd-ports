# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	alure
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/alure-releases/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Utility library to help manage common tasks with OpenAL

LICENSE=	MIT

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile

USES=		cmake pkgconfig
USE_OPENAL=	soft
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES STATIC VORBIS FLAC MPG123 DUMB MODPLUG FLUIDSYNTH
OPTIONS_DEFAULT=	VORBIS FLAC DUMB

DUMB_DESC=		DUMB audio library decoding support
MODPLUG_DESC=		MOD decoding via ModPlug
FLUIDSYNTH_DESC=	MIDI support via FluidSynth

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
PLUGIN_OPTIONS_CMAKE+=	-DUSE_VORBIS:BOOL=TRUE
.else
PLUGIN_OPTIONS_CMAKE+=	-DUSE_VORBIS:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLAC:BOOL=TRUE
.else
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLAC:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MMPG123}
LIB_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPG123:BOOL=TRUE
.else
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPG123:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MDUMB}
BUILD_DEPENDS+=	${LOCALBASE}/include/dumb.h:${PORTSDIR}/audio/dumb-allegro
PLUGIN_OPTIONS_CMAKE+=	-DUSE_DUMB:BOOL=TRUE
.else
PLUGIN_OPTIONS_CMAKE+=	-DUSE_DUMB:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MMODPLUG}
BUILD_DEPENDS+=	${LOCALBASE}/include/libmodplug/modplug.h:${PORTSDIR}/audio/libmodplug
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MODPLUG:BOOL=TRUE
.else
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MODPLUG:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
LIB_DEPENDS+=	fluidsynth:${PORTSDIR}/audio/fluidsynth
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLUIDSYNTH:BOOL=TRUE
.else
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLUIDSYNTH:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	NaturalDocs:${PORTSDIR}/devel/naturaldocs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' \
		-e 's|"ModPlug support (for IT/XM/S3M/MOD)" OFF)|"ModPlug support (for IT/XM/S3M/MOD)" ON)|' \
		${WRKSRC}/CMakeLists.txt

.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} \
		-e 's|INSTALL(DIRECTORY "$${ALURE_SOURCE_DIR}/docs/html"|INSTALL(DIRECTORY "$${ALURE_SOURCE_DIR}/docs/html" "$${ALURE_SOURCE_DIR}/docs/naturaldocs"|' \
		${WRKSRC}/CMakeLists.txt
.endif

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i '' '/FIND_PROGRAM(NATDOCS_BIN NaturalDocs)/,/ENDIF(NATDOCS_BIN)/s/^/#/' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i '' -e '/INSTALL(DIRECTORY "$${ALURE_SOURCE_DIR}/,+2d' ${WRKSRC}/CMakeLists.txt
.endif

.if ! ${PORT_OPTIONS:MSTATIC}
	@${REINPLACE_CMD} -e 's|"Build the static version of the library" ON)|"Build the static version of the library" OFF)|' \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
