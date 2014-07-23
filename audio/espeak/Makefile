# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	espeak
PORTVERSION=	1.47.11
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Software speech synthesizer

LICENSE=	GPLv3

# default is runtime audio detection
LIB_DEPENDS=	${PORTAUDIOLIB} \
		${PULSEAUDIOLIB}

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	PORTAUDIO
OPTIONS_RADIO=	AUDIO_SYSTEM
OPTIONS_RADIO_AUDIO_SYSTEM=	PORTAUDIO PULSEAUDIO RUNTIME
RUNTIME_DESC=	Sound interface selected at runtime

PORTAUDIOLIB=	libportaudio.so:${PORTSDIR}/audio/portaudio
PULSEAUDIOLIB=	libpulse.so:${PORTSDIR}/audio/pulseaudio

CONFLICTS=	speak-1.[0-9]

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		AUDIO="${AUDIO}"

CXXFLAGS+=	-I${LOCALBASE}/include
USES=		gmake zip
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

REINPLACE_FILES=	Makefile speech.h
REINPLACE_ARGS=	-i.bak -e "s|%%DATADIR%%|${DATADIR}|g"

BROKEN_sparc64=	Does not compile on sparc64

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRUNTIME}
AUDIO=	"runtime"
.endif
.if ${PORT_OPTIONS:MPULSEAUDIO}
AUDIO=	"pulseaudio"
PORTAUDIOLIB=
.endif
.if ${PORT_OPTIONS:MPORTAUDIO}
AUDIO=	"portaudio"
PULSEAUDIOLIB=
.endif

post-patch:
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} ${REINPLACE_FILES}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libespeak.so*

.include <bsd.port.mk>
