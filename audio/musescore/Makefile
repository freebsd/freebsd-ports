PORTNAME=	${GH_PROJECT:tl}
DISTVERSIONPREFIX=	v
DISTVERSION=	4.6.5
PORTREVISION=	1
CATEGORIES=	audio

PATCH_SITES=	https://github.com/musescore/MuseScore/commit/
PATCHFILES+=	b79c3ba61e599e2211ba69f7be561ecfbdab941c.patch:-p1 # Fix build with Qt 6.10.1
PATCHFILES+=	6f63cd15ced0b2a624a85e471724fba922762974.patch:-p1 # Add missing include for Qt 6.10
PATCHFILES+=	e25d01bd7f650e51911929ec2aa519923913cd05.patch:-p1 # Add missing include for Qt 6.10
PATCHFILES+=	36d544ab41abff3dc675202953486b837f21b8b6.patch:-p1 # Fix build on FreeBSD

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

USES=		cmake compiler:c++17-lang desktop-file-utils gl localbase \
		pkgconfig qt:6 shared-mime-info
USE_GL=		opengl
USE_QT=		5compat base declarative networkauth scxml svg \
		shadertools:build tools:build

USE_GITHUB=	yes
GH_PROJECT=	MuseScore

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
CMAKE_ON=	MUE_COMPILE_USE_SYSTEM_FLAC \
		MUE_COMPILE_USE_SYSTEM_FREETYPE \
		MUE_COMPILE_USE_SYSTEM_HARFBUZZ \
		MUE_COMPILE_USE_SYSTEM_OPUS \
		MUE_COMPILE_USE_SYSTEM_OPUSENC \
		MUE_COMPILE_USE_SYSTEM_TINYXML
CMAKE_OFF=	MUSE_COMPILE_USE_PCH \
		${CMAKE_TESTS}
CMAKE_BUILD_TYPE=	release
CMAKE_ARGS=	-DMUSE_APP_BUILD_MODE="release"

post-install:
	# workaround for https://github.com/musescore/MuseScore/issues/26103
	@${RM} -r \
		${STAGEDIR}${PREFIX}/include \
		${STAGEDIR}${PREFIX}/lib \
		${STAGEDIR}${PREFIX}/libdata
	# workaround for https://github.com/musescore/MuseScore/issues/26104
	@${INSTALL_DATA} ${FILESDIR}/mscore.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${REINPLACE_CMD} -i '' -e "\
		s|^Version=.*|Version=${PORTVERSION}|; \
		s|^Name=.*|Name=MuseScore|; \
		"  ${STAGEDIR}${PREFIX}/share/applications/mscore.desktop

.include <bsd.port.mk>
