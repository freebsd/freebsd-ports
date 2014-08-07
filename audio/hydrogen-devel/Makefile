# Created by: Shane Ambler <FreeBSD@ShaneWare.Biz>
# $FreeBSD$

PORTNAME=	hydrogen-devel
PORTVERSION=	0.9.6r2
CATEGORIES=	audio
MASTER_SITES=	GH

MAINTAINER=	FreeBSD@ShaneWare.Biz
COMMENT=	Advanced drum machine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	hydrogen-0.*

LIB_DEPENDS+=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libtar.so:${PORTSDIR}/devel/libtar

USE_GITHUB=	yes
GH_ACCOUNT=	hydrogen-music
GH_PROJECT=	hydrogen
GH_TAGNAME=	0.9.6-RC2
GH_COMMIT=	2ff9010

MAJORVERSION=	0.9.6
USE_QT4=	corelib gui qmake_build linguist_build moc_build network \
		qt3support rcc_build sql uic_build xml
USES=		cmake:outsource desktop-file-utils pkgconfig
CMAKE_ARGS+=	-DTHREADS_HAVE_PTHREAD_ARG:BOOL=ON
USE_LDCONFIG=	yes
CXXFLAGS+=	-I${LOCALBASE}/include/portaudio2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/portaudio2 -L${LOCALBASE}/lib

OPTIONS_DEFINE=		JACK ALSA PORTAUDIO OSS LIBARCHIVE LASH LADSPA RDF RUBBERBAND
OPTIONS_DEFAULT=	JACK LADSPA LIBARCHIVE OSS RDF

LIBARCHIVE_DESC=	LibArchive support
RUBBERBAND_DESC=	librubberband for time stretching
RDF_DESC=		RDF File support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	alsa-plugins>=0:${PORTSDIR}/audio/alsa-plugins
CMAKE_ARGS+=	-DWANT_ALSA:BOOL=ON
.else
CMAKE_ARGS+=	-DWANT_ALSA:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack
CMAKE_ARGS+=	-DWANT_JACK:BOOL=ON -DWANT_JACKSESSION:BOOL=ON
.else
CMAKE_ARGS+=	-DWANT_JACK:BOOL=OFF -DWANT_JACKSESSION:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MLADSPA}
BUILD_DEPENDS+=	ladspa>=0:${PORTSDIR}/audio/ladspa
RUN_DEPENDS+=	analyseplugin:${PORTSDIR}/audio/ladspa
CMAKE_ARGS+=	-DWANT_LADSPA:BOOL=ON
CMAKE_ARGS+=	-DLADSPA_LIBRARIES:STRING=${LOCALBASE}/lib/ladspa
.else
CMAKE_ARGS+=	-DWANT_LADSPA:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MLASH}
LIB_DEPENDS+=	liblash.so:${PORTSDIR}/audio/lash
CMAKE_ARGS+=	-DWANT_LASH:BOOL=ON
.else
CMAKE_ARGS+=	-DWANT_LASH:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MLIBARCHIVE}
LIB_DEPENDS+=	libarchive.so:${PORTSDIR}/archivers/libarchive
CMAKE_ARGS+=	-DWANT_LIBARCHIVE:BOOL=ON
.else
CMAKE_ARGS+=	-DWANT_LIBARCHIVE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOSS}
CMAKE_ARGS+=	-DWANT_OSS:BOOL=ON
.else
CMAKE_ARGS+=	-DWANT_OSS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	libportaudio.so.2:${PORTSDIR}/audio/portaudio2
CMAKE_ARGS+=	-DWANT_PORTAUDIO:BOOL=ON
.else
CMAKE_ARGS+=	-DWANT_PORTAUDIO:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MRDF}
LIB_DEPENDS+=	liblrdf.so:${PORTSDIR}/textproc/liblrdf
CFLAGS+=	-I${LOCALBASE}/include/raptor2
CXXFLAGS+=	-I${LOCALBASE}/include/raptor2
CMAKE_ARGS+=	-DWANT_LRDF:BOOL=ON
.else
CMAKE_ARGS+=	-DWANT_LRDF:BOOL=OFF
.endif

# using librubberband is experimental and current versions have bad timing
# installing the rubberband cli tool still works as before
.if ${PORT_OPTIONS:MRUBBERBAND}
LIB_DEPENDS+=	librubberband.so:${PORTSDIR}/audio/rubberband
CMAKE_ARGS+=	-DWANT_RUBBERBAND:BOOL=ON
CMAKE_ARGS+=	-DRUBBERBAND_INCLUDE_DIR:STRING=${LOCALBASE}/include/rubberband
.else
CMAKE_ARGS+=	-DWANT_RUBBERBAND:BOOL=OFF
.endif

.include <bsd.port.mk>
