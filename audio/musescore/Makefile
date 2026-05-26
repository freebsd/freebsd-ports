PORTNAME=	${GH_PROJECT:tl}
DISTVERSIONPREFIX=	v
PORTVERSION=	4.7.3
# PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Free music composition & notation software
WWW=		https://musescore.org/ \
		https://github.com/musescore/MuseScore

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libasound.so:audio/alsa-lib \
		libFLAC.so:audio/flac \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libopus.so:audio/opus \
		libopusenc.so:audio/libopusenc \
		libtinyxml2.so:textproc/tinyxml2 \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	alsa-plugins>=1.2:audio/alsa-plugins
BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		vulkan-loader>0:graphics/vulkan-loader

USES=		cmake compiler:c++17-lang desktop-file-utils gl localbase \
		pkgconfig qt:6 pathfix
USE_GL=		opengl
USE_QT=		5compat base declarative networkauth scxml svg \
		tools:build
USE_GITHUB=	yes
GH_PROJECT=	MuseScore
GH_ACCOUNT=	musescore

OPTIONS_DEFINE=		MNX

MNX_DESC=	experimental MNX json import/export support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMNX}
BUILD_DEPENDS+=	xxd:sysutils/xxd
GH_TUPLE+=	\
		nlohmann:json:v3.12.0:json \
		w3c:mnx:d513cf7a28a84c803ed36e448b416cb49c3a22f9:w3c \
		pboettch:json-schema-validator:40af3ec39670e768fc3f01f935140af311d71024:validator \
		rpatters1:mnxdom:e7c947bf768caccf315426dcae0dfac02caf738b:mnxdom \
		musescore:muse_framework:8d6707fb9cbc9b5b52f7b7649d0dd4976dd4e0ac:muse_framework/muse
CMAKE_ON+=	MUE_BUILD_IMPEXP_MNX_MODULE
.else
CMAKE_OFF+=	MUE_BUILD_IMPEXP_MNX_MODULE
.endif

# Each release gets a subdir containing the distfiles for that release,
# so hope that scanning the parent dir finds new ones.
#
# Note needs PORTVERSION:R once there is a .minor version
DATADIR=	${PREFIX}/share/mscore-${PORTVERSION:R}

CMAKE_TESTS=	MUE_BUILD_BRAILLE_TESTS \
		MUE_BUILD_ENGRAVING_TESTS \
		MUE_BUILD_IMPORTEXPORT_TESTS \
		MUE_BUILD_NOTATION_TESTS \
		MUE_BUILD_PLAYBACK_TESTS \
		MUE_BUILD_PROJECT_TESTS
CMAKE_ON+=	MUE_COMPILE_USE_SYSTEM_FLAC \
		MUE_COMPILE_USE_SYSTEM_FREETYPE \
		MUE_COMPILE_USE_SYSTEM_HARFBUZZ \
		MUE_COMPILE_USE_SYSTEM_OPUS \
		MUE_COMPILE_USE_SYSTEM_OPUSENC \
		MUE_COMPILE_USE_SYSTEM_TINYXML
CMAKE_OFF+=	MUE_BUILD_CRASHPAD_CLIENT \
		MUE_COMPILE_USE_PCH \
		${CMAKE_TESTS}
CMAKE_BUILD_TYPE=	Release
CMAKE_ARGS+=	-DMUSE_APP_BUILD_MODE="release"

.include <bsd.port.pre.mk>

post-patch-MNX-on:
# mnxdom dependencies
	@${MKDIR} ${WRKDIR}/.build/_deps
	@${MV} ${WRKSRC_mnxdom} ${WRKDIR}/.build/_deps/mnxdom-src
	@${MV} ${WRKSRC_json} ${WRKDIR}/.build/_deps/nlohmann_json-src
	@${MV} ${WRKSRC_w3c} ${WRKDIR}/.build/_deps/mnx_w3c-src
	@${MV} ${WRKSRC_validator} ${WRKDIR}/.build/_deps/json_schema_validator-src

post-install:
	# ${RM} ${STAGEDIR}${PREFIX}/bin/musescore

post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${CMAKE_SOURCE_PATH}/share/icons/AppIcon/MS4_AppIcon_48x48.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/mscore.png
	${INSTALL_DATA} ${FILESDIR}/mscore.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${REINPLACE_CMD} -i '' -e "\
		s|^Version=.*|Version=${PORTVERSION}|; \
		s|^Name=.*|Name=MuseScore Studio|; \
		"  ${STAGEDIR}${PREFIX}/share/applications/mscore.desktop
	${LN} -s mscore ${STAGEDIR}${PREFIX}/bin/musescore

.include <bsd.port.post.mk>
