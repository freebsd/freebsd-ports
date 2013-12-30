# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	alure
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/alure-releases/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Utility library to help manage common tasks with OpenAL

LICENSE=	MIT

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

USES=		cmake openal:soft pkgconfig
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS DUMB EXAMPLES FLAC FLUIDSYNTH MPG123 MODPLUG STATIC VORBIS
OPTIONS_DEFAULT=	DUMB FLAC VORBIS

DUMB_DESC=		DUMB audio library decoding support
FLUIDSYNTH_DESC=	MIDI support via FluidSynth
MODPLUG_DESC=		MOD decoding via ModPlug

OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	NaturalDocs:${PORTSDIR}/devel/naturaldocs
DUMB_BUILD_DEPENDS=	${LOCALBASE}/include/dumb.h:${PORTSDIR}/audio/dumb-allegro
DUMB_CMAKE_ON=		-DUSE_DUMB:BOOL=TRUE
DUMB_CMAKE_OFF=		-DUSE_DUMB:BOOL=FALSE
FLAC_LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac
FLAC_CMAKE_ON=		-DUSE_FLAC:BOOL=TRUE
FLAC_CMAKE_OFF=		-DUSE_FLAC:BOOL=FALSE
FLUIDSYNTH_LIB_DEPENDS=	fluidsynth:${PORTSDIR}/audio/fluidsynth
FLUIDSYNTH_CMAKE_ON=	-DUSE_FLUIDSYNTH:BOOL=TRUE
FLUIDSYNTH_CMAKE_OFF=	-DUSE_FLUIDSYNTH:BOOL=FALSE
MPG123_LIB_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
MPG123_CMAKE_ON=	-DUSE_MPG123:BOOL=TRUE
MPG123_CMAKE_OFF=	-DUSE_MPG123:BOOL=FALSE
MODPLUG_BUILD_DEPENDS=	${LOCALBASE}/include/libmodplug/modplug.h:${PORTSDIR}/audio/libmodplug
MODPLUG_CMAKE_ON=	-DUSE_MODPLUG:BOOL=TRUE
MODPLUG_CMAKE_OFF=	-DUSE_MODPLUG:BOOL=FALSE
VORBIS_LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis
VORBIS_CMAKE_ON=	-DUSE_VORBIS:BOOL=TRUE
VORBIS_CMAKE_OFF=	-DUSE_VORBIS:BOOL=TRUE

.include <bsd.port.options.mk>

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
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
