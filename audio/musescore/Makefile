# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	musescore
PORTVERSION=	2.1
CATEGORIES=	audio
MASTER_SITES=	http://ftp.osuosl.org/pub/musescore/releases/MuseScore-${PORTVERSION}/
DISTNAME=	MuseScore-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free music composition & notation software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BROKEN_aarch64=		Fails to compile: error: constant expression evaluates to -1

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libfreetype.so:print/freetype2

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils \
		pkgconfig shared-mime-info zip
USE_QT5=	core gui widgets opengl concurrent designer help network \
		scripttools qml quick svg sql printsupport testlib webkit \
		xml xmlpatterns \
		buildtools_build linguisttools_build qmake_build uitools_build
ALL_TARGET=	lrelease manpages all
INSTALLS_ICONS=	yes
CMAKE_ARGS+=	-DUSE_SYSTEM_FREETYPE="ON"

DATADIR=	${PREFIX}/share/mscore-${PORTVERSION}

OPTIONS_DEFINE=		ALSA JACK PORTAUDIO PULSEAUDIO OCR
OPTIONS_DEFAULT=	PORTAUDIO
OCR_DESC=		Optical Character Recognition

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	BUILD_ALSA
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	BUILD_JACK
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	BUILD_PORTAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	BUILD_PULSEAUDIO
OCR_CMAKE_BOOL=		OCR

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
