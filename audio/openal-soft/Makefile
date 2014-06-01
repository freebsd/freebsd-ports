# $FreeBSD$

PORTNAME=	openal-soft
PORTVERSION=	1.15.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/openal-releases/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A software implementation of the OpenAL specification

LICENSE=	LGPL20

CONFLICTS=	openal-200[0-9]*

USES=		tar:bzip2 cmake
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DALSA:BOOL=OFF -DPORTAUDIO:BOOL=OFF -DSOLARIS:BOOL=OFF \
		-DDSOUND:BOOL=OFF -DSNDIO:BOOL=OFF -DEXAMPLES:BOOL=OFF \
		-DMMDEVAPI:BOOL=OFF -DWINMM:BOOL=OFF -DCOREAUDIO:BOOL=OFF \
		-DOPENSL:BOOL=OFF -DALSOFT_CONFIG:BOOL=ON

OPTIONS_DEFINE=		PULSEAUDIO
PULSEAUDIO_DESC=	Enable sound streaming using PulseAudio

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse-simple.so:${PORTSDIR}/audio/pulseaudio
CFLAGS+=	-Iinclude -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-DPULSEAUDIO:BOOL=ON
.else
CMAKE_ARGS+=	-DPULSEAUDIO:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc/openal|${ETCDIR}|' \
		${WRKSRC}/Alc/alcConfig.c \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's|share/openal|${ETCDIR}|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
