PORTNAME=	${GH_PROJECT:tl}
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.4
CATEGORIES=	audio

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Free music composition & notation software
WWW=		https://musescore.org/ \
		https://github.com/musescore/MuseScore

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libasound.so:audio/alsa-lib \
		libasound_module_pcm_oss.so:audio/alsa-plugins \
		libFLAC.so:audio/flac \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libopus.so:audio/opus \
		libopusenc.so:audio/libopusenc \
		libtinyxml2.so:textproc/tinyxml2 \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang desktop-file-utils gl localbase \
		pkgconfig qt:6 shared-mime-info
USE_QT=		base 5compat declarative networkauth scxml svg \
		tools:build
USE_GL=		gl

USE_GITHUB=	yes
GH_PROJECT=	MuseScore

# Each release gets a subdir containing the distfiles for that release,
# so hope that scanning the parent dir finds new ones.
#
# Note needs PORTVERSION:R once there is a .minor version
DATADIR=	${PREFIX}/share/mscore-${PORTVERSION:R}

CMAKE_TESTS=	MUE_BUILD_BRAILLE_TESTS MUE_BUILD_ENGRAVING_TESTS MUE_BUILD_IMPORTEXPORT_TESTS MUE_BUILD_NOTATION_TESTS MUE_BUILD_PLAYBACK_TESTS MUE_BUILD_PROJECT_TESTS
CMAKE_ON=	MUE_COMPILE_USE_SYSTEM_FLAC \
		MUE_COMPILE_USE_SYSTEM_FREETYPE \
		MUE_COMPILE_USE_SYSTEM_HARFBUZZ \
		MUE_COMPILE_USE_SYSTEM_OPUS \
		MUE_COMPILE_USE_SYSTEM_OPUSENC \
		MUE_COMPILE_USE_SYSTEM_TINYXML
CMAKE_OFF=	MUE_BUILD_CRASHPAD_CLIENT \
		MUE_COMPILE_USE_PCH \
		${CMAKE_TESTS}
CMAKE_BUILD_TYPE=	release
CMAKE_ARGS=	-DMUSE_APP_BUILD_MODE="release"

post-stage:
	# workaround for https://github.com/musescore/MuseScore/issues/26103
	@${RM} -r \
		${STAGEDIR}${PREFIX}/include \
		${STAGEDIR}${PREFIX}/lib \
		${STAGEDIR}${PREFIX}/libdata
	# workaround for https://github.com/musescore/MuseScore/issues/26104
	@${INSTALL_DATA} ${FILESDIR}/mscore.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
