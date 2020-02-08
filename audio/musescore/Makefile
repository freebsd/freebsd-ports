# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	musescore
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.2
CATEGORIES=	audio
# DISTNAME=	MuseScore-${DISTVERSION}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Free music composition & notation software

LICENSE=	GPLv2
# LICENSE_FILE=	LICENSE.GPL

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lib desktop-file-utils \
		pkgconfig qt:5 shared-mime-info
USE_QT=		core declarative gui widgets opengl concurrent designer help \
		location network quickcontrols2 \
		scripttools svg sql printsupport testlib \
		webchannel xml xmlpatterns \
		buildtools_build linguisttools_build qmake_build uitools_build

USE_GITHUB=	yes
GH_ACCOUNT=	musescore
GH_PROJECT=	MuseScore

# Each release gets a subdir containing the distfiles for that release,
# so hope that scanning the parent dir finds new ones.
DATADIR=	${PREFIX}/share/mscore-${PORTVERSION:R}

ALL_TARGET=	lrelease manpages all
CMAKE_ARGS+=	-DUSE_SYSTEM_FREETYPE="ON" \
		-DBUILD_PORTMIDI=OFF \
		-DBUILD_PCH=OFF \
		-DDOWNLOAD_SOUNDFONT=OFF

# WebEngine is only available on i386/amd64, amd ppc64 starting FreeBSD 13.0.
# If enabled on arches that don't have WebEngine, the build breaks.
OPTIONS_DEFINE=		ALSA JACK PORTAUDIO PULSEAUDIO WEBENGINE
OPTIONS_DEFAULT=	PORTAUDIO
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE
OPTIONS_DEFAULT_powerpc64=     ${OPTIONS_DEFAULT_powerpc64_${OSREL:R}}
OPTIONS_DEFAULT_powerpc64_13=  WEBENGINE

WEBENGINE_DESC=		Use WebEngine in the welcome panel

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	BUILD_ALSA
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	BUILD_JACK
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	BUILD_PORTAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	BUILD_PULSEAUDIO
WEBENGINE_USE=		qt=webengine
WEBENGINE_CMAKE_BOOL=	BUILD_WEBENGINE

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-inconsistent-missing-override
.endif

post-extract:
	@${RM} -r ${WRKSRC}/thirdparty/freetype

post-patch:
	@${FIND} ${WRKSRC} -name "CMakeLists.txt" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		'/RELEASE/s|-O2 ||; \
		 /COMPILE_FLAGS/s|-g ||; \
		 s|share/man|man|; \
		 /COMPILE_FLAGS/s|$${PCH_INCLUDE} |-include $${PROJECT_BINARY_DIR}/all.h |'
	@${REINPLACE_CMD} -e \
		's|<errno.h>|<cerrno>| ; \
		 s|<limits.h>|<climits>| ; \
		 s|<math.h>|<cmath>| ; \
		 s|<stdio.h>|<cstdio>|' ${WRKSRC}/all.h

.include <bsd.port.post.mk>
