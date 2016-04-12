# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	musescore
PORTVERSION=	2.0.2
CATEGORIES=	audio
MASTER_SITES=	http://ftp.osuosl.org/pub/musescore/releases/MuseScore-${PORTVERSION}/
DISTNAME=	MuseScore-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free music composition & notation software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils \
		pkgconfig shared-mime-info zip
USE_QT5=	concurrent declarative designer help network scripttools svg \
		webkit xml xmlpatterns \
		buildtools_build linguisttools_build qmake_build uitools_build
ALL_TARGET=	lrelease manpages all

DATADIR=	${PREFIX}/share/mscore-${PORTVERSION:R}

OPTIONS_DEFINE=		ALSA JACK PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	PORTAUDIO

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_ON=		-DBUILD_ALSA:BOOL=ON
ALSA_CMAKE_OFF=		-DBUILD_ALSA:BOOL=OFF
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_ON=		-DBUILD_JACK:BOOL=ON
JACK_CMAKE_OFF=		-DBUILD_JACK:BOOL=OFF
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_ON=	-DBUILD_PORTAUDIO:BOOL=ON
PORTAUDIO_CMAKE_OFF=	-DBUILD_PORTAUDIO:BOOL=OFF
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DBUILD_PULSEAUDIO:BOOL=ON
PULSEAUDIO_CMAKE_OFF=	-DBUILD_PULSEAUDIO:BOOL=OFF

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-inconsistent-missing-override
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "CMakeLists.txt" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		'/RELEASE/s|-O2 || ; \
		 /COMPILE_FLAGS/s|-g || ; \
		 /COMPILE_FLAGS/s|$${PCH_INCLUDE} |-include $${PROJECT_BINARY_DIR}/all.h |'
	@${REINPLACE_CMD} -e \
		's|<errno.h>|<cerrno>| ; \
		 s|<limits.h>|<climits>| ; \
		 s|<math.h>|<cmath>| ; \
		 s|<stdio.h>|<cstdio>|' ${WRKSRC}/all.h

.include <bsd.port.post.mk>
